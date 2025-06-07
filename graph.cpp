#include "graph.h"
#include <Qdebug>
#include <algorithm>
#include <QFile>
#include <QTextStream>
#include <QStandardPaths>
#include <QStringList>
#include <QByteArray>
#include <QList>
#include <QDir>
#include <QStringView>
#include <qelapsedtimer.h>
#include <qfileinfo.h>
#include <set>
#include <stack>
#include <queue>
#include <utility>
#include <climits>
#include <array>


Graph::Graph(QObject *parent)
{
    placeCount = 0;
    edgeCount = 0;
    nextPlaceId = 0;

}

void Graph::addPlace(const QString &name, int recommendedTime, QString type,bool withLog)
{
    if (placeNameToIdMap.count(name)) {
        QString m = QString("错误：\n地点 %1 已存在。\n").arg(name);
        emit newLog(m,"ERROR");
        return;
    }
    placeCount++;
    int currentId = nextPlaceId++;
    places.emplace_back(currentId, name, recommendedTime, type);
    placeNameToIdMap[name] = currentId;

    // 扩展邻接表以容纳新地点
    if (currentId >= adjacencyList.size()) {
        adjacencyList.resize(currentId + 1);
    }

    if(withLog){
        QString m = QString("新建地点：\n名称:%1,种类:%2,建议时长:%3,ID:%4\n").arg(name).arg(type).arg(recommendedTime).arg(currentId);
        emit newLog(m,"INFO");
    }
    return;
}

void Graph::addEdge(const QString &placeName1, const QString &placeName2, int length,bool withLog)
{
    int id1 = getPlaceIdByName(placeName1);
    int id2 = getPlaceIdByName(placeName2);
    if (id1 == -1) {
        emit newLog(QString("添加道路失败：地点 '%1' 不存在。").arg(placeName1), "ERROR");
        qDebug() << "错误：添加道路失败，地点 '" << placeName1 << "' 不存在。";
        return ;
    }
    if (id2 == -1) {
        emit newLog(QString("添加道路失败：地点 '%1' 不存在。").arg(placeName2), "ERROR");
        qDebug() << "错误：添加道路失败，地点 '" << placeName2 << "' 不存在。";
        return ;
    }
    if (length <= 0) {
        emit newLog(QString("添加道路失败：道路长度必须为正数 (提供的长度: %1)。").arg(length), "ERROR");
        qDebug() << "错误：道路长度必须为正数。";
        return ;
    }
    if (id1 == id2) {
        if (withLog) {
            emit newLog(QString("添加道路失败：起点和终点是同一个地点 '%1'。").arg(placeName1), "ERROR");
            qDebug() << "错误：添加道路失败，起点和终点是同一个地点。";
        }
        return;
    }
    std::pair<int, int> currentEdgePair = (id1 < id2) ? std::make_pair(id1, id2) : std::make_pair(id2, id1);
    if (existEdge.count(currentEdgePair)) { // 使用 std::set 进行 O(log N) 查找
        if (withLog) {
            // 原来的 qDebug 输出信息有误 ("错误：道路长度必须为正数。")，已修正
            emit newLog(QString("添加道路失败：%1 <--> %2 道路已存在。").arg(placeName1).arg(placeName2), "ERROR");
            qDebug() << "错误：道路 " << placeName1 << " <--> " << placeName2 << " 已存在。";
        }
        return;
    }
    // 添加边 id1 -> id2
    adjacencyList[id1].emplace_back(id2, length);
    // 添加边 id2 -> id1
    adjacencyList[id2].emplace_back(id1, length);
    edges.push_back({id1, id2,length});
    edgeCount++;
    existEdge.insert(currentEdgePair);

    if(withLog) {
        QString logMsg = QString("成功添加道路：'%1' (ID:%2) <--> '%3' (ID:%4), 长度: %5")
                             .arg(placeName1).arg(id1)
                             .arg(placeName2).arg(id2)
                             .arg(length);
        emit newLog(logMsg, "INFO");
        qDebug() << logMsg;
    }
    return ;
}

void Graph::showAllPlaces()
{
    QString m = "地点信息如下\n(id,名字,种类,推荐游玩时间)：\n";
    for(auto& i:places) {
        if(i.isValid == false) continue;
        QString info = QString("%1, %2, %3, %4\n").arg(i.id).arg(i.name).arg(i.type).arg(i.recommendedTime);
        m+=info;
    }
    emit newLog(m,"INFO");
}

void Graph::showAllEdges()
{
    sort(edges.begin(),edges.end());
    QString m = "道路信息如下\n(起点-终点-长度)：\n";
    for(auto& i:edges) {
        QString info = QString("%1(%4) <--> %2(%5)-%3\n").arg(places[i.id1].name).arg(places[i.id2].name).arg(i.length).arg(i.id1).arg(i.id2);
        m+=info;
    }
    emit newLog(m,"INFO");
}

bool Graph::removePlace(const QString &name)
{
    int id_to_remove = getPlaceIdByName(name);

    if (id_to_remove == -1) {
        QString msg = QString("删除失败：地点 '%1' 不存在于名称映射中。\n").arg(name);
        emit newLog(msg, "ERROR");
        qDebug() << msg;
        return false;
    }
    if (id_to_remove >= static_cast<int>(places.size()) || id_to_remove < 0 || !places[id_to_remove].isValid) {
        // 注意: places.size() 返回 size_t，需要转换为 int 进行比较，或者将 id_to_remove 转为 size_t
        QString msg = QString("删除失败：地点 '%1' (ID: %2) 对应的记录无效或已被删除。\n").arg(name).arg(id_to_remove);
        emit newLog(msg, "ERROR");
        qDebug() << msg;
        return false;
    }
    //  将地点标记为无效
    places[id_to_remove].isValid = false;
    QString successMsgPart = QString("地点 '%1' (ID: %2)").arg(name).arg(id_to_remove);
    qDebug() << successMsgPart << "已被标记为无效。\n";
    //  从名称到ID的映射中移除
    placeNameToIdMap.erase(name);
    //  清除该地点的所有出边
    if(!adjacencyList[id_to_remove].empty()){
        adjacencyList[id_to_remove].clear();
    }
    qDebug() << "清除了地点 ID:" << id_to_remove << " 的所有出边。";

    for (int i = 0; i < static_cast<int>(adjacencyList.size()); ++i) {
        if (i == id_to_remove) { // 自身出边已清除
            continue;
        }
        // 确保地点 i 是有效的
        if (i >= static_cast<int>(places.size()) || !places[i].isValid) {
            continue;
        }

        auto& edges_of_i = adjacencyList[i];
        auto original_neighbor_count = edges_of_i.size();
        // 使用 erase-remove 移除边
        edges_of_i.erase(
            std::remove_if(edges_of_i.begin(), edges_of_i.end(),
                           [id_to_remove](const Edge& edge) {
                               return edge.toNodeId == id_to_remove;
                           }),
            edges_of_i.end()
            );
        if (edges_of_i.size() < original_neighbor_count) {
            qDebug() << "从地点 ID:" << i << " (" << places[i].name << ") 移除了指向 ID:" << id_to_remove << " 的边。";
        }
    }
    //  从全局 edges 列表中移除与该地点相关的边
    auto original_global_edge_count = edges.size();
    if(!edges.empty()) {
        edges.erase(
            std::remove_if(edges.begin(), edges.end(),
                           [id_to_remove](const EdgeInfo& edge_info) {
                               return edge_info.id1 == id_to_remove || edge_info.id2 == id_to_remove;
                           }),
            edges.end()
            );
    }
    if (edges.size() < original_global_edge_count) {
        qDebug() << "从全局边信息列表 (edges) 中移除了与 ID:" << id_to_remove << " 相关的边。";
    }
    // 更新 edgeCount
    edgeCount = edges.size();

    //  更新有效地点计数
    placeCount--;

    emit newLog(successMsgPart + " 已成功移除。\n", "INFO");

    return true;

}

bool Graph::removeEdge(const QString &startPlaceName, const QString &endPlaceName)
{
    int start_id = getPlaceIdByName(startPlaceName);
    int end_id = getPlaceIdByName(endPlaceName);


    if (start_id == -1) {
        QString msg = QString("移除道路失败：起点 '%1' 不存在。\n").arg(startPlaceName);
        emit newLog(msg, "ERROR");
        qDebug() << msg;
        return false;
    }
    if (end_id == -1) {
        QString msg = QString("移除道路失败：终点 '%1' 不存在。\n").arg(endPlaceName);
        emit newLog(msg, "ERROR");
        qDebug() << msg;
        return false;
    }
    bool edgeFoundAndRemoved = false;

    //  从邻接表中移除边
    //  从 start_id 的邻接列表中移除指向 end_id 的边
    if (start_id < static_cast<int>(adjacencyList.size())) {
        auto& start_adj = adjacencyList[start_id];
        size_t original_size = start_adj.size();
        start_adj.erase(
            std::remove_if(start_adj.begin(), start_adj.end(),
                           [end_id](const Edge& edge) {
                               return edge.toNodeId == end_id;
                           }),
            start_adj.end()
            );
        if (start_adj.size() < original_size) {
            edgeFoundAndRemoved = true; // 标记至少在一个方向上找到了并移除了边
            qDebug() << "从 ID:" << start_id << " (" << startPlaceName << ") 的邻接列表中移除了指向 ID:" << end_id << " (" << endPlaceName << ") 的边。";
        }
    }

    //  从 end_id 的邻接列表中移除指向 start_id 的边
    if (end_id < static_cast<int>(adjacencyList.size())) {
        auto& end_adj = adjacencyList[end_id];
        size_t original_size = end_adj.size();
        end_adj.erase(
            std::remove_if(end_adj.begin(), end_adj.end(),
                           [start_id](const Edge& edge) {
                               return edge.toNodeId == start_id;
                           }),
            end_adj.end()
            );
        if (end_adj.size() < original_size) {
            edgeFoundAndRemoved = true; // 再次确认
            qDebug() << "从 ID:" << end_id << " (" << endPlaceName << ") 的邻接列表中移除了指向 ID:" << start_id << " (" << startPlaceName << ") 的边。";
        }
    }
    //  从全局的 edges 列表中移除该边
    size_t original_global_edges_size = edges.size();
    edges.erase(
        std::remove_if(edges.begin(), edges.end(),
                       [start_id, end_id](const EdgeInfo& ei) {
                           return (ei.id1 == start_id && ei.id2 == end_id) ||
                                  (ei.id1 == end_id && ei.id2 == start_id);
                       }),
        edges.end()
        );

    if (edges.size() < original_global_edges_size) {
        edgeFoundAndRemoved = true; // 确认在全局列表中也移除了
        qDebug() << "从全局边信息列表 (edges) 中移除了连接 '" << startPlaceName << "' 和 '" << endPlaceName << "' 的边。";
    }


    // 更新边的总数
    edgeCount = edges.size();

    if (edgeFoundAndRemoved) {
        QString msg = QString("道路 '%1' <--> '%2' 已成功移除。").arg(startPlaceName).arg(endPlaceName);
        emit newLog(msg, "INFO");
        qDebug() << msg;
        return true;
    } else {
        QString msg = QString("移除道路失败：在 '%1' 和 '%2' 之间未找到可移除的道路。").arg(startPlaceName).arg(endPlaceName);
        emit newLog(msg, "WARNING");
        qDebug() << msg;
        return false;
    }

}

int Graph::getPlaceIdByName(const QString &name) const
{
    auto it = placeNameToIdMap.find(name);
    if (it != placeNameToIdMap.end()) {
        return it->second;
    }
    qDebug() << "错误：找不到地点 '" << name << "'";
    return -1; // 未找到
}

int Graph::getPlacesCount() const
{
    return placeCount;
}

int Graph::getEdgesCount() const
{
    return edgeCount;
}

bool Graph::findPlacesByType(const QString &type)
{
    QString m ="";
    for(auto& p:places) {
        if(p.type != type || p.isValid == false) continue;
        m+=QString("名字：%1,类型：%2,建议时长：%3\n").arg(p.name).arg(p.type).arg(p.recommendedTime);
    }
    if(m == "") {
        emit newLog(QString("未找到类型:%1\n").arg(type),"ERROR");
        return false;
    }
    else {
        emit newLog(m,"INFO");
        return true;
    }
}

bool Graph::findPlaceByName(const QString &name)
{
    QString m = "";
    for(auto& p:places) {
        if(p.name != name || p.isValid == false) continue;
        m+=QString("名字：%1,类型：%2,建议时长：%3\n").arg(p.name).arg(p.type).arg(p.recommendedTime);
        break;
    }
    if(m == "") {
        emit newLog(QString("未找到对应地点:%1\n").arg(name),"ERROR");
        return false;
    }
    else {
        emit newLog(m,"INFO");
        return true;
    }
}

bool Graph::findPlacesByTime(const int &time)
{
    QString m ="";
    for(auto& p:places) {
        if(p.recommendedTime == time || p.isValid == false) continue;
        m+=QString("名字：%1,类型：%2,建议时长：%3\n").arg(p.name).arg(p.type).arg(p.recommendedTime);
    }
    if(m == "") {
        emit newLog(QString("未找到对应时间的地点:%1\n").arg(time),"ERROR");
        return false;
    }
    else {
        emit newLog(m,"INFO");
        return true;
    }
}

bool Graph::fineEdgesByPlace(const QString &placeName)
{
    int placeId = getPlaceIdByName(placeName);

    if (placeId == -1) {
        QString msg = QString("查找道路失败：地点 '%1' 不存在。").arg(placeName);
        emit newLog(msg, "ERROR");
        qDebug() << msg;
        return false;
    }

    // 确保 placeId 在 places 向量的有效范围内且地点是有效的
    if (placeId >= static_cast<int>(places.size()) || !places[placeId].isValid) {
        QString msg = QString("查找道路失败：地点 '%1' (ID: %2) 记录无效或已被删除。").arg(placeName).arg(placeId);
        emit newLog(msg, "ERROR");
        qDebug() << msg;
        return false;
    }

    const PlaceNode& currentPlace = places[placeId];
    QStringList edgeLogEntries;
    edgeLogEntries.append(QString("地点 '%1' (ID: %2) 的道路信息如下：").arg(currentPlace.name).arg(currentPlace.id));

    bool foundEdges = false;
    if (placeId < static_cast<int>(adjacencyList.size())) { // 确保邻接表有此ID的条目
        const std::vector<Edge>& connectedEdges = adjacencyList[placeId];
        if (connectedEdges.empty()) {
            edgeLogEntries.append("  (该地点当前没有直接连接的道路)");
        } else {
            for (const Edge& edge : connectedEdges) {
                int neighborId = edge.toNodeId;
                // 确保邻居地点也有效
                if (neighborId >= 0 && neighborId < static_cast<int>(places.size()) && places[neighborId].isValid) {
                    const PlaceNode& neighborPlace = places[neighborId];
                    edgeLogEntries.append(QString("  -> 连接到 '%1' (ID: %2), 长度: %3")
                                              .arg(neighborPlace.name)
                                              .arg(neighborPlace.id)
                                              .arg(edge.length));
                    foundEdges = true;
                }
            }
        }
    }

    if(foundEdges){
        emit newLog(edgeLogEntries.join('\n'), "INFO");
        qDebug().noquote() << edgeLogEntries.join('\n'); // .noquote() 使 qDebug 输出换行符而不是 \n
        return true;
    } else {
        emit newLog("未能找到对应边", "ERROR");
        return false;
    }

}

void Graph::printGraph()
{
    QString msg = "";
    for(size_t i=0;i<adjacencyList.size();i++) {
        if(!places[i].isValid) continue;
        QString u = places[i].name;
        for(auto& e:adjacencyList[i]) {
            QString v = places[e.toNodeId].name;
            msg += QString("%1 <--> %2\n").arg(u).arg(v);
        }
    }
    emit newLog(msg,"INFO");
}

bool Graph::isConnected()
{
    // 处理特殊情况：地点少于2个
    if (placeCount == 0) {
        emit newLog("图中地点少于2个，视为连通。", "INFO");
        qDebug() << "图中地点少于2个，视为连通。";
        return true;
    }

    // 初始化并查集
    UnionSet unionset(places.size());

    // 构建并查集
    for(int i=0; i < static_cast<int>(adjacencyList.size()); i++) { // 明确类型转换
        if(!places[i].isValid) continue; // 只处理有效的起始地点
        for(auto& e : adjacencyList[i]) {
            // 确保目标地点ID有效并且目标地点也是有效的
            if (e.toNodeId >= 0 && e.toNodeId < static_cast<int>(places.size()) && places[e.toNodeId].isValid) {
                if(!unionset.isUnited(i, e.toNodeId)) {
                    unionset.unite(i, e.toNodeId);
                }
            }
        }
    }

    QString msg = "";

    // 判断连通性：计算有效节点的连通分量数量
    int validPlaceEffectiveRootCount = 0;
    std::set<int> distinctRootsOfValidNodes; // 用于存储有效节点所属的不同根节点

    for(int i = 0; i < static_cast<int>(places.size()); i++) {
        if(places[i].isValid) {
            distinctRootsOfValidNodes.insert(unionset.findroot(i));
        }
    }
    validPlaceEffectiveRootCount = distinctRootsOfValidNodes.size();

    // 如果图中没有有效节点，也视为连通
    if (placeCount == 0 && validPlaceEffectiveRootCount == 0) { // placeCount 是有效节点数
        emit newLog("图中没有有效地点，视为连通。", "INFO");
        qDebug() << "图中没有有效地点，视为连通。";
        return true;
    }


    bool isEffectivelyConnected = (validPlaceEffectiveRootCount <= 1); // 小于等于1都算（

    if(!isEffectivelyConnected) {
        msg += QString("图不连通！检测到 %1 个独立的连通分量 (基于 %2 个有效地点)。\n").arg(validPlaceEffectiveRootCount).arg(placeCount);
        msg += "以下是一些建议的边，用于尝试连接不同的分量：\n";

        // 5. 找出并建议连接边
        std::vector<int> representativeNodes; // 存储不同连通分量的代表节点
        std::map<int, int> rootToRepresentativeNodeMap; // 映射根到其代表节点ID
        for(int i = 0; i < static_cast<int>(places.size()); i++) {
            if(places[i].isValid) {
                int root = unionset.findroot(i);
                if (rootToRepresentativeNodeMap.find(root) == rootToRepresentativeNodeMap.end()) {
                    rootToRepresentativeNodeMap[root] = i; // 选择第一个遇到的有效节点作为代表
                    representativeNodes.push_back(i);
                }
            }
        }

        // 添加 N-1 条边来连接 N 个分量
        for(size_t i = 0; i + 1 < representativeNodes.size(); i++) {
            msg += QString("  建议添加: %1 <--> %2\n").arg(places[representativeNodes[i]].name).arg(places[representativeNodes[i+1]].name);
        }
        emit newLog(msg, "INFO");
        qDebug().noquote() << msg;
        return false;
    } else {
        msg = QString("图为连通的! (包含 %1 个有效地点，形成 %2 个连通分量)\n").arg(placeCount).arg(validPlaceEffectiveRootCount);
        emit newLog(msg, "INFO");
        qDebug() << msg;
        return true;
    }
}

void Graph::calcDegree()
{
    degreeMap.clear();
    for(int i=0;i<nextPlaceId;i++) {
        if(static_cast<size_t>(i)<places.size() && places[i].isValid) {
            int d = 0;
            for(auto& e:adjacencyList[i]) {
                if (e.toNodeId >= 0 && places[e.toNodeId].isValid) {
                    d++;
                }
            }
            degreeMap[i]=d;
        }
    }
}

int Graph::hasEulerPath()
{
    if(!isConnected()) {
        emit newLog("非连通图不存在欧拉路径！\n","INFO");
        return -1;
    }
    if(placeCount == 0) {
        emit newLog("空图无法判断！\n","ERROR");
        return -1;
    }
    calcDegree();
    std::vector<int> nodes; // 存储度数为奇数的节点;
    for(auto& p:degreeMap) {
        if(p.second&1) {
            nodes.push_back(p.first);
        }
    }
    if(nodes.empty()) {

        int s = -1;
        for(int i = 0; i < nextPlaceId; ++i) {
            if(static_cast<size_t>(i) < places.size() && places[i].isValid) {
                s = i;
                break;
            }
        }
        QString msg = "存在欧拉回路！\n";
        emit newLog(msg,"INFO");
        return s;
    } else if (nodes.size() == 2) {
        // 奇数度节点为2个 --> 存在欧拉路径
        emit newLog("图中存在欧拉路径（起点和终点不同）。", "INFO");
        return nodes[0]; // 返回其中一个奇数度节点作为起点

    } else {
        // 其他情况 --> 不存在欧拉路径或回路
        QString msg = QString("图中不存在欧拉路径或回路，因为存在 %1 个奇数度的顶点。")
                          .arg(nodes.size());
        emit newLog(msg, "ERROR");
        return -1;
    }

}

void Graph::printEulerPath()
{
    int s = hasEulerPath();
    if(s == -1) {
        emit newLog("不存在欧拉路径，无法执行命令！\n","ERROR");
        qDebug() << "由于不存在欧拉路径或无法确定起点，无法打印路径。";
        return;
    }
    std::vector<int> path;
    std::stack<int> st;
    std::vector<std::vector<Edge>> adj = adjacencyList;
    long long totalLength = 0;    // 总路径长度
    int totalTime = 0; // 总建议游玩时间
    st.push(s);
    while(!st.empty()) {
        int cur = st.top();
        if(!adj[cur].empty()) {
            Edge e = adj[cur].back(); // 获取当前节点cur的最后一条边
            int next = e.toNodeId;    // 下一个节点
            int l = e.length;         // 当前边的长度
            adj[cur].pop_back();
            auto& a = adj[next];
            for(auto it = a.begin();it!=a.end();it++) {
                if (it->toNodeId == cur) { // 匹配目标节点
                    a.erase(it);
                    break;
                }
            }
            st.push(next);
            totalLength+=l;
        } else {
            path.push_back(cur);
            st.pop();
        }
    }
    std::reverse(path.begin(), path.end());
    if (path.empty() && placeCount > 0) {
        emit newLog("未能找到欧拉路径（可能由于图结构问题或算法未能覆盖所有边）。\n", "WARNING");
        qDebug() << "未能找到欧拉路径";
        return;
    }

    QString pathString = QString("找到的欧拉路径/回路如下 (总长度 %1 米)：\n").arg(totalLength);

        int firstNodeId = path[0];
        if (static_cast<size_t>(firstNodeId) < places.size() && places[firstNodeId].isValid) {
            pathString += places[firstNodeId].name;
            totalTime += places[firstNodeId].recommendedTime;
        } else {
            pathString += QString("无效或未知ID %1").arg(firstNodeId);
        }

        // 构建路径字符串
        for (size_t i = 0; i < path.size() - 1; ++i) {
            // int u_id = eulerPathNodeIds[i]; // 当前段的起点ID
            int v_id = path[i+1]; // 当前段的终点ID
            QString v_name = (static_cast<size_t>(v_id) < places.size() && places[v_id].isValid) ?
                                 places[v_id].name : QString("无效或未知ID %1").arg(v_id);
            pathString += QString(" --> %1").arg(v_name);
            if (places[v_id].isValid) {
                totalTime += places[v_id].recommendedTime;
            }
        }

    pathString += QString("\n总建议游玩时间（包含沿途所有地点）：%1 分钟.").arg(totalTime);

    emit newLog(pathString, "INFO");
    qDebug().noquote() << pathString;

}

void Graph::findShortestPath(const QString &startName, const QString &endName)
{
    if (placeNameToIdMap.count(startName) == 0 ||
        static_cast<size_t>(placeNameToIdMap[startName]) >= places.size() ||
        !places[placeNameToIdMap[startName]].isValid) {
        QString msg = QString("错误：起始地点 '%1' 不存在或无效。\n").arg(startName);
        emit newLog(msg, "ERROR");
        qDebug().noquote() << msg;
        return;
    }
    if (placeNameToIdMap.count(endName) == 0 ||
        static_cast<size_t>(placeNameToIdMap[endName]) >= places.size() ||
        !places[placeNameToIdMap[endName]].isValid) {
        QString msg = QString("错误：目标地点 '%1' 不存在或无效。\n").arg(endName);
        emit newLog(msg, "ERROR");
        qDebug().noquote() << msg;
        return;
    }

    int startId = placeNameToIdMap[startName];
    int endId = placeNameToIdMap[endName];
    int time = 0;
    if (startId == endId) {
        QString msg = QString("路径查找：起始地点和目标地点相同 ('%1')。\n路径长度：0。\n路径：%1\n")
                          .arg(startName);
        emit newLog(msg, "INFO");
        qDebug().noquote() << msg;
        return;
    }

    size_t nodeCount = places.size();
    std::vector<long long> dist(nodeCount, LLONG_MAX);
    std::vector<int> pre(nodeCount, -1);

    std::priority_queue<std::pair<long long, int>> pq; // {-距离, 节点ID}

    dist[startId] = 0;
    pq.push({0, startId});

    while (!pq.empty()) {
        long long negD = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (static_cast<size_t>(u) < adjacencyList.size()) {
            for (const auto& edge : adjacencyList[u]) {
                int v = edge.toNodeId;
                int w = edge.length;

                if (static_cast<size_t>(v) >= nodeCount || !places[v].isValid) {
                    continue; // 跳过无效的邻居节点
                }

                if (dist[u] != LLONG_MAX && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pre[v] = u;
                    pq.push({-dist[v], v});
                }
            }
        }
    }

    if (dist[endId] == LLONG_MAX) { // 如果目标地点不可达
        QString msg = QString("未能找到从 '%1' 到 '%2' 的路径。\n").arg(startName).arg(endName);
        emit newLog(msg, "WARNING");
        qDebug().noquote() << msg;
    } else {
        std::vector<QString> pathVec;
        int pNode = endId;
        while (pNode != -1) {
            time+=places[pNode].recommendedTime;
            pathVec.push_back(places[pNode].name);
            pNode = pre[pNode];
        }

        // 检查路径重建是否成功
        bool pathReconstructionError = pathVec.empty() || (pathVec.size() == 1 && pathVec.front().startsWith("[错误"));
        if (pathReconstructionError && startId != endId) { // 如果起点终点不同但路径重建失败
            QString msg = QString("错误：无法重建从 '%1' 到 '%2' 的有效路径，尽管计算出距离为 %3。\n")
                              .arg(startName).arg(endName).arg(dist[endId]);
            emit newLog(msg, "ERROR");
            qDebug().noquote() << msg;
            return;
        }


        std::reverse(pathVec.begin(), pathVec.end());

        QString sep = " --> ";
        QString pathText;
        if (!pathVec.empty()) {
            pathText = pathVec[0]; // 先添加第一个元素
            for (size_t i = 1; i < pathVec.size(); ++i) {
                pathText += sep + pathVec[i]; // 从第二个元素开始，前面加上分隔符
            }
        }

        QString msg = QString("从 '%1' 到 '%2' 的最短路径：\n总长度：%3 米\n路径：%4\n推荐游玩时间：%5\n")
                          .arg(startName)
                          .arg(endName)
                          .arg(dist[endId])
                          .arg(pathText)
                          .arg(time);
        emit newLog(msg, "INFO");
        qDebug().noquote() << msg;
    }
}

void Graph::printMST()
{
    if(placeCount == 0) {
        QString msg = QString("错误：空图不存在最小生成树\n");
        emit newLog(msg, "ERROR");
        qDebug().noquote() << msg;
        return;
    }
    if(!isConnected()) {
        QString msg = QString("错误：非连通图不存在最小生成树\n");
        emit newLog(msg, "ERROR");
        qDebug().noquote() << msg;
        return;
    }
    std::vector<std::array<int,3>> mst;
    sort(edges.begin(),edges.end());
    int totalLength = 0;
    UnionSet unionset(places.size());
    int index=0;
    while(mst.size() != placeCount-1 && index<edges.size())
    {
        int u=edges[index].id1;
        int v=edges[index].id2;
        int w=edges[index].length;
        index++;
        if(!unionset.isUnited(u,v)) {
            mst.push_back({u,v,w});
            unionset.unite(u,v);
            totalLength += w;
        }
    }
    QString msg = QString("以下是一种最小生成树:\n");
    for(auto [u,v,w]:mst) {
        msg+= QString("%1 <--> %2, 长度：%3\n").arg(places[u].name).arg(places[v].name).arg(w);
    }
    msg+= QString("最小生成树总最小代价为：%1").arg(totalLength);
    emit newLog(msg,"INFO");
    return;
}

void Graph::saveFile(const QString &filepath)
{
    if (placeCount == 0 && edgeCount == 0) {
        emit newLog("图中没有数据，无需保存。", "INFO");
        qDebug() << "图中没有数据，保存操作已取消。";
        return;
    }

    QFileInfo fileInfo(filepath);
    QString dirPath = fileInfo.path();
    QString baseName = fileInfo.baseName();

    QString placesPath = QDir(dirPath).filePath(baseName+"_nodes.csv");
    QString edgesPath = QDir(dirPath).filePath(baseName+"_edges.csv");

    bool placesSuccess = false;
    bool edgesSuccess = false;

    QFile placesFile(placesPath);
    if(!placesFile.open(QIODevice::WriteOnly|QIODevice::Text)) {
        QString errorMsg = QString("错误：无法创建或打开地点文件进行写入：\n%1\n原因: %2")
                               .arg(placesPath, placesFile.errorString());
        emit newLog(errorMsg, "ERROR");
        qDebug() << errorMsg;
    } else {
        QTextStream stream(&placesFile);
        stream.setEncoding(QStringConverter::Utf8);
        stream<<"name"<<","<<"type"<<","<<"recommendedTime"<<'\n';
        for(auto& place:places) {
            if(!place.isValid) continue;
            stream<<place.name<<","<<place.type<<","<<place.recommendedTime<<'\n';
        }
        placesFile.close();
        QString successMsg = QString("所有地点信息已成功保存到：\n%1").arg(placesPath);
        emit newLog(successMsg, "INFO");
        qDebug() << successMsg;
        placesSuccess = true;
    }
    QFile edgesFile(edgesPath);
    if(!edgesFile.open(QIODevice::WriteOnly|QIODevice::Text)) {
        QString errorMsg = QString("错误：无法创建或打开地点文件进行写入：\n%1\n原因: %2")
                               .arg(edgesPath, edgesFile.errorString());
        emit newLog(errorMsg, "ERROR");
        qDebug() << errorMsg;
    } else {
        QTextStream stream(&edgesFile);
        stream.setEncoding(QStringConverter::Utf8);
        stream<<"node"<<","<<"node"<<","<<"weight"<<'\n';

        for(auto& edge:edges) {
            if (edge.id1 < places.size() && places[edge.id1].isValid &&
                edge.id2 < places.size() && places[edge.id2].isValid)
            {
                stream << places[edge.id1].name << ","
                            << places[edge.id2].name << ","
                            << edge.length << "\n";
            }
        }
        edgesFile.close();
        QString successMsg = QString("所有道路信息已成功保存到：\n%1").arg(edgesPath);
        emit newLog(successMsg, "INFO");
        qDebug() << successMsg;
        edgesSuccess = true;
    }
    if (placesSuccess && edgesSuccess) {
        emit newLog("图数据已全部分别保存到地点和道路文件中。", "INFO");
    } else {
        emit newLog("图数据保存过程中出现错误，请检查日志详情。", "WARNING");
    }
}

bool Graph::updatePlaceRecommenedTime(const QString &placeName, int newTime)
{
    int placeId = getPlaceIdByName(placeName);

    if (placeId == -1) {
        QString msg = QString("更新建议用时失败：地点 '%1' 不存在。\n").arg(placeName);
        emit newLog(msg, "ERROR");
        qDebug() << msg;
        return false;
    }

    // 确保 placeId 在 places 向量的有效范围内且地点是有效的
    if (placeId >= static_cast<int>(places.size()) || !places[placeId].isValid) {
        QString msg = QString("更新建议用时失败：地点 '%1' (ID: %2) 记录无效或已被删除。\n").arg(placeName).arg(placeId);
        emit newLog(msg, "ERROR");
        qDebug() << msg;
        return false;
    }

    if (newTime < 0) {
        QString msg = QString("更新建议用时失败：地点 '%1' 的建议用时 (%2) 不能为负数。\n").arg(placeName).arg(newTime);
        emit newLog(msg, "ERROR");
        qDebug() << msg;
        return false;
    }

    places[placeId].recommendedTime = newTime;

    QString msg = QString("地点 '%1' (ID: %2) 的建议用时已更新为 %3 分钟。\n").arg(placeName).arg(placeId).arg(newTime);
    emit newLog(msg, "INFO");
    qDebug() << msg;
    return true;
}

bool Graph::updateEdgeLength(const QString &startPlaceName, const QString &endPlaceName, int newLength)
{
    int startId = getPlaceIdByName(startPlaceName);
    int endId = getPlaceIdByName(endPlaceName);

    if (startId == -1) {
        QString msg = QString("更新道路长度失败：起点 '%1' 不存在。").arg(startPlaceName);
        emit newLog(msg, "ERROR");
        qDebug() << msg;
        return false;
    }
    if (endId == -1) {
        QString msg = QString("更新道路长度失败：终点 '%1' 不存在。").arg(endPlaceName);
        emit newLog(msg, "ERROR");
        qDebug() << msg;
        return false;
    }

    if (startId == endId) {
        QString msg = QString("更新道路长度失败：起点和终点是同一个地点 '%1'。").arg(startPlaceName);
        emit newLog(msg, "ERROR");
        qDebug() << msg;
        return false;
    }

    if (newLength <= 0) {
        QString msg = QString("更新道路长度失败：新的道路长度 (%1) 必须为正数。").arg(newLength);
        emit newLog(msg, "ERROR");
        qDebug() << msg;
        return false;
    }

    bool updatedInAdjList1 = false;
    bool updatedInAdjList2 = false;
    bool updatedInGlobalEdges = false;

    // 更新邻接表
    // 更新 startId -> endId
    if (startId < static_cast<int>(adjacencyList.size()) && places[startId].isValid) {
        for (Edge& edge : adjacencyList[startId]) {
            if (edge.toNodeId == endId && places[endId].isValid) { // 确保目标节点也有效
                edge.length = newLength;
                updatedInAdjList1 = true;
                // 更新所有 startId 和 endId 之间的直接连接
            }
        }
    }

    // 更新 endId -> startId
    if (endId < static_cast<int>(adjacencyList.size()) && places[endId].isValid) {
        for (Edge& edge : adjacencyList[endId]) {
            if (edge.toNodeId == startId && places[startId].isValid) { // 确保目标节点也有效
                edge.length = newLength;
                updatedInAdjList2 = true;
            }
        }
    }

    // 更新全局 edges 列表
    for (EdgeInfo& edgeInfo : edges) {
        if ((edgeInfo.id1 == startId && edgeInfo.id2 == endId) ||
            (edgeInfo.id1 == endId && edgeInfo.id2 == startId)) {
            // 确保这两个地点仍然有效
            if (places[startId].isValid && places[endId].isValid) {
                edgeInfo.length = newLength;
                updatedInGlobalEdges = true;
            }
        }
    }

    if (updatedInAdjList1 && updatedInAdjList2 && updatedInGlobalEdges) {
        QString msg = QString("连接 '%1' (ID:%2) 和 '%3' (ID:%4) 的道路长度已更新为 %5。\n")
                          .arg(startPlaceName).arg(startId)
                          .arg(endPlaceName).arg(endId)
                          .arg(newLength);
        emit newLog(msg, "INFO");
        qDebug() << msg;
        return true;
    } else if (updatedInAdjList1 || updatedInAdjList2 || updatedInGlobalEdges) {
        QString warningMsg = QString("警告：道路 '%1' <--> '%2' 的长度更新可能不完全。邻接表1:%3, 邻接表2:%4, 全局列表:%5\n")
                                 .arg(startPlaceName).arg(endPlaceName)
                                 .arg(updatedInAdjList1).arg(updatedInAdjList2).arg(updatedInGlobalEdges);
        emit newLog(warningMsg, "WARNING");
        qDebug() << warningMsg;
        return true;
    }
    else {
        QString msg = QString("更新道路长度失败：在 '%1' 和 '%2' 之间未找到可更新的道路。\n")
                          .arg(startPlaceName).arg(endPlaceName);
        emit newLog(msg, "WARNING");
        qDebug() << msg;
        return false;
    }
}

bool Graph::readPlaceFile(const QString &filePath)
{
    QFile csvFile(filePath);
    // 以只读和文本模式打开文件
    if (!csvFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "错误：无法打开 CSV 文件：" << csvFile.errorString();
        emit newLog(QString("无法打开 CSV 文件 '%1': %2").arg(filePath).arg(csvFile.errorString()), "ERROR");
        return 0;
    }
    // 创建输入流
    QTextStream inStream(&csvFile);
    // 在循环开始前，先读取并丢弃第一行（表头）
    if (!inStream.atEnd()) {
        inStream.readLine();
    }
    qDebug() << "开始读取并解析 CSV 文件：" << filePath;
    int lineNumber = 0;
    while(!inStream.atEnd())
    {
        lineNumber++;
        QString line = inStream.readLine(); // 读取一行
        QStringList s = line.split(','); // 按逗号分割字符串
        if(s.size()!= 3) {
            emit newLog(QString("CSV 文件 '%1' 不符合格式规范无法读取！\n").arg(filePath), "ERROR");
            return 0;
        }
        addPlace(s[0],s[2].toInt(),s[1],false);
    }
    csvFile.close();

    qDebug() << "CSV 文件读取和解析完成。";
    emit newLog(QString("CSV 文件 '%1' 读取完毕。\n").arg(filePath), "INFO");
    return 1;
}

bool Graph::readEdgeFile(const QString &filePath)
{
    QElapsedTimer timer;
    timer.start();
    QFile csvFile(filePath);
    // 以只读和文本模式打开文件
    if (!csvFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "错误：无法打开 CSV 文件：" << csvFile.errorString();
        emit newLog(QString("无法打开 CSV 文件 '%1': %2").arg(filePath).arg(csvFile.errorString()), "ERROR");
        return 0;
    }
    // 创建输入流
    QTextStream inStream(&csvFile);
    // 在循环开始前，先读取并丢弃第一行（表头）
    if (!inStream.atEnd()) {
        inStream.readLine();
    }
    qDebug() << "开始读取并解析 CSV 文件：" << filePath;
    int lineNumber = 0;
    QString line;
    QList<QString> s;

    while(!inStream.atEnd())
    {
        lineNumber++;
        line = inStream.readLine(); // 读取一行
        s = line.split(',');
        if(s.size()!= 3) {
            emit newLog(QString("CSV 文件 '%1' 不符合格式规范无法读取！\n").arg(filePath), "ERROR");
            return 0;
        }
        QString name1 = s[0];
        QString name2 = s[1];
        int w = s[2].toInt();
        addEdge(name1,name2,w,false);
    }

    qDebug() << "CSV 文件读取和解析完成。";
    emit newLog(QString("CSV 文件 '%1' 读取完毕。共%2 行\n").arg(filePath).arg(lineNumber), "INFO");
    qDebug() << "文件读取耗时:" << timer.elapsed() << "ms";
    return true;
}

bool Graph::clear()
{
    places.clear();
    placeNameToIdMap.clear();
    adjacencyList.clear();
    edges.clear();
    existEdge.clear();

    nextPlaceId = 0;
    placeCount = 0;
    edgeCount = 0;

    QString msg = "图已清空，所有地点和道路信息已被移除。";
    emit newLog(msg, "INFO");
    qDebug() << msg;

    return true;
}

Graph::UnionSet::UnionSet(int n)
{
    fa.resize(n);
    for(int i=0;i<n;i++) fa[i]=i;
}

int Graph::UnionSet::findroot(int k)
{
    return fa[k]==k?k:fa[k]=findroot(fa[k]);
}

bool Graph::UnionSet::isUnited(int i, int j)
{
    return findroot(i) == findroot(j);
}

void Graph::UnionSet::unite(int i, int j)
{
    fa[findroot(i)] = findroot(j);
}

int Graph::UnionSet::rootCounts()
{
    std::set<int> rootset;
    for(int i=0;i<fa.size();i++) {
        int rt = findroot(i);
        if(rootset.count(rt) > 0) {
            continue;
        } else {
            rootset.insert(rt);
        }
    }
    return rootset.size();

}

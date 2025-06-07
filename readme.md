
# 华东师范大学计算机科学技术系项目报告

- **课程名称**：数据结构 
- **指导教师**：肖春芸
- **姓名**：吴俊达
- **学号**：10245102514
- **年级**：24级 
- **日期**：2025/6/3

---
## 一、 项目名称 

**校园导航系统**
## 二、 项目仓库

- 仓库地址：[NightRain5212/CampusNavigation](https://github.com/NightRain5212/CampusNavigation)
- 所用语言：**C++**(94.8%), Makefile(3.7%), **CMake**(1.3%), **C**(0.2%)

## 三、项目结构

- 本项目主要使用QT框架进行开发，文件类型如下
	- .ui：QT窗口设计文件
	- .h：核心接口头文件
		- graph.h：管理图数据结构的核心
		- *window.h：窗口类头文件
		- *dialog.h：对话框窗口头文件
	- .cpp：各类.h文件的实现
	- main.cpp: 程序主要入口


## 四、 主要功能

本项目实现了一个校园导航系统，主要功能如下:

1. 节点和边的基本操作： 
	1. 插入节点：支持添加新的地点信息。 
	2. 删除节点：支持删除指定的地点。 
	3. 查找节点：支持查找地点信息。 (可以按关键字查找)
	4. 更新节点：支持更新地点的参观时间等信息。
	5. 插入边：支持添加新的道路信息。 
	6. 删除边：支持删除指定的道路。 
	7. 查找边：支持查找边信息。 
	8. 更新边：支持更新道路的权重（长度）
2. 文件操作 ：
	1. 读取道路信息文件，并构建对应图结构中的边
	2. 读取地点信息文件，并构建对应图结构中的顶点
	3. 保存文件，将所有的地点信息和道路信息保存至文件中
3. 操作选项：
	1. 显示所有地点信息
	2. 显示所有道路信息
	3. 打印已经建立的图,以边集的形式
	4. 重置图信息，即清空
4. 算法相关：
	1. 判断图的连通性
	2. 判断是否存在欧拉路径
	3. 计算两点之间的最短路径，并给出总的推荐游玩时间
	4. 求构件图的最小生成树
	5. 求欧拉路径（并给出欧拉路径的总长度和途径地点的游玩时间之和）
5. 用户交互界面：
	基于QT实现了图形用户界面GUI，可实时显示已构建图中的地点数和边数，可将用户进行的操作结果进行反馈显示在日志栏中，基于用户进行的每一步操作保存在日志文件中。

## 五、 其他部分 

1. 性能：

2. 遇到的主要问题：


## 六、 代码示例

- 最短路径
```cpp
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

        QString msg = QString("从 '%1' 到 '%2' 的最短路径：\n总长度：%3 米\n路径：%4推荐游玩时间：%5\n")
                          .arg(startName)
                          .arg(endName)
                          .arg(dist[endId])
                          .arg(pathText)
                          .arg(time);
        emit newLog(msg, "INFO");
        qDebug().noquote() << msg;
    }
}
```

## 七、总结 

通过本次实验，实现了一个基本的校园导航系统，能够进行节点和边的基本操作，计算最短路径，检
测欧拉回路，并推荐游览线路。在项目开发过程中，解决了图的连通性检测、数据加载与存储、用户交互
界面设计等问题，提升了C++编程的综合能力
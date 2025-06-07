#ifndef GRAPH_H
#define GRAPH_H

#include <QObject>
#include <set>
struct PlaceNode {
    int id;                 // 地点的唯一整数ID
    QString name;           // 地点名称
    int recommendedTime;    // 建议参观用时 (例如：分钟)
    QString type;         // 地点类型
    bool isValid;         // 删除标记

    // 构造函数
    PlaceNode(int _id = -1, QString _name = "", int _time = 0, QString _type = "", bool _isvalid = true)
        : id(_id), name(std::move(_name)), recommendedTime(_time), type(_type), isValid(_isvalid) {}

    bool operator<(const PlaceNode& other) const {
        return id < other.id; // 或者按名称排序 name < other.name;
    }
};

struct Edge {
    int toNodeId;       // 这条边指向的目标地点的ID
    int length;         // 路径长度

    Edge(int to = -1, int l = 0) : toNodeId(to), length(l) {}

    bool operator<(const Edge& other) const {
        return length < other.length;
    }
};

struct EdgeInfo {
    int id1;
    int id2;
    int length;
    bool operator<(const EdgeInfo& other) const {
        return length < other.length;
    }
};

class Graph : public QObject
{
    Q_OBJECT

private:
    std::vector<PlaceNode> places;                     // 使用向量存储所有地点，索引即ID (如果ID从0连续增加)
    std::unordered_map<QString, int> placeNameToIdMap;   // 从地点名称到ID的映射，方便查找
    std::vector<std::vector<Edge>> adjacencyList;        // 邻接表，adjacencyList[i] 存储与地点ID i 相连的所有边
    int nextPlaceId;                                   // 用于生成新的唯一地点ID
    std::vector<EdgeInfo> edges;
    std::set<std::pair<int, int>> existEdge;
    int placeCount;
    int edgeCount;
    struct UnionSet
    {
        std::vector<int> fa;
        UnionSet(int n);
        int findroot(int k);
        bool isUnited(int i,int j);
        void unite(int i,int j);
        int rootCounts();
    };
    std::map<int,int> degreeMap;                        // 用于保存节点的度

public:
    explicit Graph(QObject *parent = nullptr);
    void addPlace(const QString& name, int recommendedTime, QString type,bool withLog=true);
    void addEdge(const QString& placeName1, const QString& placeName2, int length,bool withLog=true);
    void showAllPlaces();
    void showAllEdges();
    bool removePlace(const QString& name);
    bool removeEdge(const QString& start,const QString& end);
    int getPlaceIdByName(const QString& name) const;
    int getPlacesCount() const;
    int getEdgesCount() const;
    bool findPlacesByType(const QString& type);
    bool findPlaceByName(const QString& name);
    bool findPlacesByTime(const int& time);
    bool updatePlaceRecommenedTime(const QString& placeName,int value);
    bool updateEdgeLength(const QString& startPlace,const QString& endPlace, int length);
    bool readPlaceFile(const QString& filePath);
    bool readEdgeFile(const QString& filePath);
    bool clear();
    bool fineEdgesByPlace(const QString& placeName);
    void printGraph();
    bool isConnected();
    void calcDegree();
    int hasEulerPath();   // 返回可能的一个起点
    void printEulerPath();
    void findShortestPath(const QString& placeName1, const QString& placeName2);
    void printMST();
    void saveFile(const QString& filepath);


signals:
    void newLog(const QString& message,const QString& level);
};

#endif // GRAPH_H

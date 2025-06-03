#ifndef DICT_H
#define DICT_H

#include <unordered_map>
#include <set>
#include <vector>
#include <QString>
#include <QHash>
#include <QObject>
using namespace std;


struct NodeInfo
{
    int recommendation_time;
    QString name;
    QString type;

};

struct EdgeInfo
{
    int start;
    int end;
    int weight;
};

class InfoDict : public QObject
{
    Q_OBJECT
private:
    unordered_map<QString, int> *NodeMap;
    unordered_map<int,NodeInfo> *NodeinfoMap;
    set<EdgeInfo> *EdgeSet;
    int NodeCount;
    int EdgeCount;

public:
    InfoDict();
    ~InfoDict();
    void insertNode(const QString& name,const QString& type,const int& time);
    void removeNode(const QString& name);
    void searchNodeByName();
    void searchNodeByType();
    void updateNodeTime();
    void showAllNodeInfo();

    void insertEdge();
    void removeEdge();
    void updateEdgeWeight();
    void searchEdgeByStartNode();
    void searchEdgeByEndNode();
    void showAllEdgeInfo();
    void showAllEdgeInfoOrderByWeight();

    void readNodeFile();
    void writeNodeFile();
    void readEdgeFile();
    void writeEdgeFile();

signals:
    void newLog(const QString& message,const QString& level);

};

#endif // DICT_H

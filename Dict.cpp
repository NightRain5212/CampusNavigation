#include "Dict.h"
#include <QString>

InfoDict::InfoDict() {
    NodeMap = new unordered_map<QString,int>();
    NodeinfoMap = new unordered_map<int,NodeInfo>();
    EdgeSet = new set<EdgeInfo> ();
    NodeCount = 0;
    EdgeCount = 0;
}

InfoDict::~InfoDict() {
    delete NodeMap;
    delete NodeinfoMap;
    NodeinfoMap = nullptr;
    NodeMap = nullptr;
}

void InfoDict::insertNode(const QString &name, const QString &type, const int &time)
{
    NodeInfo ninfo{time,name,type};
    int id = 0;
    while(NodeinfoMap->count(id)!=0 ) id++;
    NodeMap->emplace(name,id);
    NodeinfoMap->emplace(id,ninfo);
    NodeCount++;
}

void InfoDict::removeNode(const QString &name)
{
    if(NodeMap->count(name)) {
        int id = NodeMap->at(name);
        NodeinfoMap->erase(id);
        NodeCount--;
    }
}

void InfoDict::showAllNodeInfo() {
    QString m = QString("地点信息如下：\n");
    for(auto& p:(*NodeinfoMap)) {
        m += QString("名字:%1 种类:%2 推荐游玩时间:%3").arg(p.second.name).arg(p.second.type).arg(p.second.recommendation_time);
    }
    emit newLog(m,"INFO");
}

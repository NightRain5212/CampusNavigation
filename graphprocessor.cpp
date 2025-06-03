#include "graphprocessor.h"
#include <QDebug>

graphProcessor::graphProcessor(Graph *_graph, QObject *parent)
    : QObject(parent),graph(_graph)
{
    if(!graph) {
        qDebug() << "图实例为空！";
    }
}

void graphProcessor::readEdgeFile(const QString &filepath)
{
    bool ok = graph->readEdgeFile(filepath);
    if(ok) {
        emit processingFinished(true,QString("文件 '%1' 已成功加载并处理。").arg(filepath));
    } else {
        emit processingFinished(false,QString("文件 '%2' 处理失败").arg(filepath));
    }
    return ;
}


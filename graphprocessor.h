#ifndef GRAPHPROCESSOR_H
#define GRAPHPROCESSOR_H

#include <QObject>
#include "graph.h"
#include<QString>

class graphProcessor : public QObject
{
    Q_OBJECT
public:
    explicit graphProcessor(Graph *graph,QObject *parent = nullptr);

public slots:
    // 在工作线程中调用
    void readEdgeFile(const QString& filepath);

signals:
    // 通知主进程处理完成
    void processingFinished(bool success, const QString& msg);

private:
    Graph* graph;
};

#endif // GRAPHPROCESSOR_H

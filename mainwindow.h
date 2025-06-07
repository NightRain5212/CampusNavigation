#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "graph.h"
#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void showCounts();
    void clearLog();
    void statusMsg(const QString& msg);

signals:
    void newLog(const QString& message,const QString& level);



private slots:
    void on_addPlace_triggered();

    void addLogMessage(const QString& message,const QString& level="INFO");

    void on_addEdge_triggered();

    void on_searchForPlacesByType_triggered();

    void on_searchForPlaceByName_triggered();

    void on_delPlace_triggered();

    void on_delEdge_triggered();

    void on_updatePlace_triggered();

    void on_updateEdge_triggered();

    void on_openPlaceFile_triggered();

    void on_openEdgeFile_triggered();

    void on_searchForEdge_triggered();

    void on_showAllPlaces_triggered();

    void on_showAllEdges_triggered();

    void on_resetGraph_triggered();

    void on_printGraph_triggered();

    void on_clearLog_triggered();

    void on_isConnected_triggered();

    void on_hasEulerPath_triggered();

    void on_showEulerPath_triggered();

    void on_shortestPath_triggered();

    void on_searchByTime_triggered();

    void on_findMST_triggered();

    void on_savefile_triggered();

private:
    Ui::MainWindow *ui;
    Graph *graph;
};
#endif // MAINWINDOW_H

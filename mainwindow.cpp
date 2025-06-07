#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPixmap>
#include <QDebug>
#include <QDateTime>
#include <QScrollBar>
#include <QTextDocument>
#include <QTextBlock>
#include <QTextCursor>
#include <QMessageBox>
#include <QFileDialog>
#include <QDir>
#include <QStandardPaths>
#include <QCoreApplication>
#include "addplacedialog.h"
#include "addedgedialog.h"
#include "searchplacebytypedialog.h"
#include "searchplacebynamedialog.h"
#include "delplacedialog.h"
#include "deledgedialog.h"
#include "updateedgedialog.h"
#include "updateplacedialog.h"
#include "searchedgedialog.h"
#include "shortestpathdialog.h"
#include "searchbytimedialog.h"
#include "graph.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    // 设置地图图片
    QPixmap maplabel;
    if(maplabel.load(":/image/assets/map.png")) {
        ui->mapLabel->setPixmap(maplabel.scaled(ui->mapLabel->size(),
                                                Qt::KeepAspectRatio,
                                                Qt::SmoothTransformation));
        ui->mapLabel->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    } else {
        qDebug() << "图片加载失败:/image/assets/map.png";
    }
    // 设置标题标签
    ui->titleLabel->setStyleSheet("QLabel {"
                         "font-weight: bold;"      // 设置粗体
                         "text-align: center;"     // 设置居中
                         "font-size: 16px;"
                         "}");
    graph = new Graph();
    connect(graph,&Graph::newLog,this,&MainWindow::addLogMessage);
    ui->countlabel->setStyleSheet("QLabel {"
                                  "font-weight: bold;"      // 设置粗体
                                  "text-align: center;"     // 设置居中
                                  "font-size: 12px;"
                                  "}");
    this->setWindowTitle("校园导航v1.0");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showCounts()
{
    QString countText = QString("地点数：%1，边数：%2").arg(graph->getPlacesCount()).arg(graph->getEdgesCount());
    ui->countlabel->setText(countText);
}

void MainWindow::clearLog()
{
    ui->Log->clear();
}

void MainWindow::statusMsg(const QString &msg)
{
    ui->statusbar->showMessage(msg);
}

void MainWindow::on_addPlace_triggered()
{
    qDebug() << "“添加地点”动作被触发了!"; // 用于调试
    AddplaceDialog dialog(this); // 创建 AddPlaceDialog 的实例，'this' 使 MainWindow 成为其父窗口
    connect(&dialog,&AddplaceDialog::newLog,this,&MainWindow::addLogMessage);
    // 以模态方式显示对话框 (会阻塞 MainWindow 直到对话框关闭):
    if (dialog.exec() == QDialog::Accepted) {
        // 如果用户点击了 "OK" (或者其他连接到 accept() 槽的按钮)，这部分代码会执行
        QString name = dialog.getName();
        QString type = dialog.getType();
        int time = dialog.getTime();

        graph->addPlace(name,time,type);
        showCounts();

    } else {
        // 如果用户点击了 "Cancel" 或关闭了对话框，这部分代码会执行
        qDebug() << "“添加地点”对话框被取消了。";
    }
}

void MainWindow::addLogMessage(const QString &message, const QString &level)
{
    // 获取当前exe所在的目录
    QString exeDir = QCoreApplication::applicationDirPath();
    QString logPath = exeDir + QDir::separator() + "log.txt";
    QFile logFile(logPath);
    // 获取时间
    QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    // 格式化
    QString log = QString("[%1] [%2]\n%3").arg(level).arg(timestamp).arg(message);
    // 追加显示
    ui->Log->appendPlainText(log);
    // 自动滚动到最下方
    QScrollBar* scrollbar = ui->Log->verticalScrollBar();
    if (scrollbar) { // 确保滚动条存在
        scrollbar->setValue(scrollbar->maximum());
    }
    if(logFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&logFile);
        stream.setEncoding(QStringConverter::Utf8);
        stream << log << Qt::endl;
        logFile.close();
         qDebug() << "内容已成功追加到文件:" << logPath;
    } else {
        qDebug() << "错误：无法打开文件进行追加:" << logPath
                 << "错误信息:" << logFile.errorString();
    }
    statusMsg(QString("日志文件已保存：%1 !").arg(logPath));
}


void MainWindow::on_addEdge_triggered()
{
    qDebug() << "“添加边”动作被触发了!"; // 用于调试
    addedgedialog dialog(this);
    connect(&dialog,&addedgedialog::newLog,this,&MainWindow::addLogMessage);
    // 以模态方式显示对话框 (会阻塞 MainWindow 直到对话框关闭):
    if (dialog.exec() == QDialog::Accepted) {
        QString start = dialog.getStartPlace();
        QString end = dialog.getEndPlace();
        int length = dialog.getLength();
        graph->addEdge(start,end,length);
        showCounts();
    } else {
        qDebug() << "“添加边”对话框被取消了。";
    }
}


void MainWindow::on_searchForPlacesByType_triggered()
{
    qDebug() << "动作被触发了!";
    searchPlaceByTypeDialog dialog(this);
    connect(&dialog,&searchPlaceByTypeDialog::newLog,this,&MainWindow::addLogMessage);
    if(dialog.exec() == QDialog::Accepted) {
        QString type = dialog.getType();

        graph->findPlacesByType(type);
    } else {
        qDebug() << "对话框被取消了。";
    }
}


void MainWindow::on_searchForPlaceByName_triggered()
{
    qDebug() << "动作被触发了!"; // 用于调试
    searchPlaceByNameDialog dialog(this);
    connect(&dialog,&searchPlaceByNameDialog::newLog,this,&MainWindow::addLogMessage);
    if(dialog.exec() == QDialog::Accepted) {
        QString name = dialog.getName();

        graph->findPlaceByName(name);
    } else {
        qDebug() << "对话框被取消了。";
    }
}


void MainWindow::on_delPlace_triggered()
{
    qDebug() << "动作被触发了!"; // 用于调试
    DelPlaceDialog dialog(this);
    if(dialog.exec() == QDialog::Accepted) {
        QString name = dialog.getPlaceName();
        graph->removePlace(name);
        showCounts();
    } else {
        qDebug() << "对话框被取消了。";
    }
}


void MainWindow::on_delEdge_triggered()
{
    qDebug() << "动作被触发了!"; // 用于调试
    delEdgeDialog dialog(this);
    if(dialog.exec() == QDialog::Accepted) {
        QString start = dialog.getStartPlace();
        QString end = dialog.getEndPlace();
        graph->removeEdge(start,end);
        showCounts();
    } else {
        qDebug() << "对话框被取消了。";
    }
}


void MainWindow::on_updatePlace_triggered()
{
    qDebug() << "动作被触发了!"; // 用于调试
    updatePlaceDialog dialog(this);
    if(dialog.exec() == QDialog::Accepted) {
        QString name = dialog.getPlaceName();
        int newTime = dialog.getNewTime();
        graph->updatePlaceRecommenedTime(name,newTime);

    } else {
        qDebug() << "对话框被取消了。";
    }
}


void MainWindow::on_updateEdge_triggered()
{
    qDebug() << "动作被触发了!"; // 用于调试
    updateEdgeDialog dialog(this);
    if(dialog.exec() == QDialog::Accepted) {
        QString start = dialog.getStartPlace();
        QString end = dialog.getEndPlace();
        int newLength = dialog.getNewLength();
        graph->updateEdgeLength(start,end,newLength);

    } else {
        qDebug() << "对话框被取消了。";
    }
}


void MainWindow::on_openPlaceFile_triggered()
{
    QString documentsPath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    QString filter = tr("CSV文件 (*.csv);;文本文件 (*.txt);;C++ 文件 (*.cpp *.h);;所有文件 (*.*)");
    QString selectedFilter; // 用来接收用户选择的过滤器

    QString filePath = QFileDialog::getOpenFileName(
        this,
        tr("打开地点文件"),
        documentsPath, // 默认打开文档目录
        filter,
        &selectedFilter // 将选择的过滤器存入这里
        );

    if (!filePath.isEmpty()) {
        qDebug() << "选择的文件路径:" << filePath;
        qDebug() << "选择的过滤器:" << selectedFilter;
        graph->clear();
        graph->readPlaceFile(filePath);
        showCounts();
    } else {
        qDebug() << "未选择任何文件。";
    }
}


void MainWindow::on_openEdgeFile_triggered()
{
    QString documentsPath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    QString filter = tr("CSV文件 (*.csv);;文本文件 (*.txt);;C++ 文件 (*.cpp *.h);;所有文件 (*.*)");
    QString selectedFilter; // 用来接收用户选择的过滤器

    QString filePath = QFileDialog::getOpenFileName(
        this,
        tr("打开道路文件"),
        documentsPath, // 默认打开文档目录
        filter,
        &selectedFilter // 将选择的过滤器存入这里
        );

    if (filePath.isEmpty()) {
        qDebug() << "未选择任何文件。";
    }
    qDebug() << "选择的文件路径:" << filePath;
    qDebug() << "选择的过滤器:" << selectedFilter;
    graph->readEdgeFile(filePath);
    showCounts();

}


void MainWindow::on_searchForEdge_triggered()
{
    qDebug() << "动作被触发了!"; // 用于调试
    searchEdgeDialog dialog(this);
    if(dialog.exec() == QDialog::Accepted) {
        QString name = dialog.getPlaceName();
        graph->fineEdgesByPlace(name);
    } else {
        qDebug() << "对话框被取消了。";
    }
}


void MainWindow::on_resetGraph_triggered()
{
    graph->clear();
    showCounts();
}


void MainWindow::on_showAllPlaces_triggered()
{
    graph->showAllPlaces();
    showCounts();
}


void MainWindow::on_showAllEdges_triggered()
{
    graph->showAllEdges();
    showCounts();
}


void MainWindow::on_printGraph_triggered()
{
    graph->printGraph();
}


void MainWindow::on_clearLog_triggered()
{
    clearLog();
}


void MainWindow::on_isConnected_triggered()
{
    graph->isConnected();
}


void MainWindow::on_hasEulerPath_triggered()
{
    graph->hasEulerPath();
}


void MainWindow::on_showEulerPath_triggered()
{
    graph->printEulerPath();
}


void MainWindow::on_shortestPath_triggered()
{
    qDebug() << "动作被触发了!"; // 用于调试
    shortestPathDialog dialog(this);
    if(dialog.exec() == QDialog::Accepted) {
        QString start = dialog.getStartPlaceName();
        QString end = dialog.getEndPlaceName();
        graph->findShortestPath(start,end);
    } else {
        qDebug() << "对话框被取消了。";
    }
}


void MainWindow::on_searchByTime_triggered()
{
    qDebug() << "动作被触发了!"; // 用于调试
    searchByTimeDialog dialog(this);
    if(dialog.exec() == QDialog::Accepted) {
        int time = dialog.getTime();
        graph->findPlacesByTime(time);
    } else {
        qDebug() << "对话框被取消了。";
    }
}


void MainWindow::on_findMST_triggered()
{
    graph->printMST();
}

void MainWindow::on_savefile_triggered()
{
    QString defaultpath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QString defaultName = QDir(defaultpath).filePath("untitled");


    QString filter = tr("文本文件(*.txt);;CSV文件(*.csv);;所有文件(*.*)");

    QString filePath = QFileDialog::getSaveFileName(
        this,
        tr("保存文件"),
        defaultName,
        filter
    );
    if (filePath.isEmpty()) {
        qDebug() << "用户取消了保存操作。";
        statusMsg("保存操作已取消。"); // 在状态栏给出提示
        return; // 提前退出函数
    }
    qDebug() << "请求将图数据保存到基本路径：" << filePath;
    graph->saveFile(filePath);
    statusMsg("保存操作已完成。");
}


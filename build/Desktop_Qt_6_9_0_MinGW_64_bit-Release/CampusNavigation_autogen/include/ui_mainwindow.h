/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *addPlace;
    QAction *addEdge;
    QAction *updatePlace;
    QAction *updateEdge;
    QAction *delPlace;
    QAction *delEdge;
    QAction *searchForEdge;
    QAction *searchForPlaceByName;
    QAction *searchForPlacesByType;
    QAction *openPlaceFile;
    QAction *openEdgeFile;
    QAction *showAllPlaces;
    QAction *showAllEdges;
    QAction *resetGraph;
    QAction *printGraph;
    QAction *clearLog;
    QAction *isConnected;
    QAction *hasEulerPath;
    QAction *showEulerPath;
    QAction *shortestPath;
    QAction *searchByTime;
    QAction *findMST;
    QAction *savefile;
    QWidget *centralwidget;
    QLabel *mapLabel;
    QLabel *titleLabel;
    QPlainTextEdit *Log;
    QLabel *countlabel;
    QMenuBar *menubar;
    QMenu *add;
    QMenu *update;
    QMenu *del;
    QMenu *menu;
    QMenu *menuchaxun;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        addPlace = new QAction(MainWindow);
        addPlace->setObjectName("addPlace");
        addEdge = new QAction(MainWindow);
        addEdge->setObjectName("addEdge");
        updatePlace = new QAction(MainWindow);
        updatePlace->setObjectName("updatePlace");
        updateEdge = new QAction(MainWindow);
        updateEdge->setObjectName("updateEdge");
        delPlace = new QAction(MainWindow);
        delPlace->setObjectName("delPlace");
        delEdge = new QAction(MainWindow);
        delEdge->setObjectName("delEdge");
        searchForEdge = new QAction(MainWindow);
        searchForEdge->setObjectName("searchForEdge");
        searchForPlaceByName = new QAction(MainWindow);
        searchForPlaceByName->setObjectName("searchForPlaceByName");
        searchForPlacesByType = new QAction(MainWindow);
        searchForPlacesByType->setObjectName("searchForPlacesByType");
        openPlaceFile = new QAction(MainWindow);
        openPlaceFile->setObjectName("openPlaceFile");
        openEdgeFile = new QAction(MainWindow);
        openEdgeFile->setObjectName("openEdgeFile");
        showAllPlaces = new QAction(MainWindow);
        showAllPlaces->setObjectName("showAllPlaces");
        showAllEdges = new QAction(MainWindow);
        showAllEdges->setObjectName("showAllEdges");
        resetGraph = new QAction(MainWindow);
        resetGraph->setObjectName("resetGraph");
        printGraph = new QAction(MainWindow);
        printGraph->setObjectName("printGraph");
        clearLog = new QAction(MainWindow);
        clearLog->setObjectName("clearLog");
        isConnected = new QAction(MainWindow);
        isConnected->setObjectName("isConnected");
        hasEulerPath = new QAction(MainWindow);
        hasEulerPath->setObjectName("hasEulerPath");
        showEulerPath = new QAction(MainWindow);
        showEulerPath->setObjectName("showEulerPath");
        shortestPath = new QAction(MainWindow);
        shortestPath->setObjectName("shortestPath");
        searchByTime = new QAction(MainWindow);
        searchByTime->setObjectName("searchByTime");
        findMST = new QAction(MainWindow);
        findMST->setObjectName("findMST");
        savefile = new QAction(MainWindow);
        savefile->setObjectName("savefile");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        mapLabel = new QLabel(centralwidget);
        mapLabel->setObjectName("mapLabel");
        mapLabel->setGeometry(QRect(30, 70, 291, 441));
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setGeometry(QRect(10, 10, 800, 32));
        titleLabel->setMinimumSize(QSize(800, 32));
        titleLabel->setMaximumSize(QSize(800, 32));
        titleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Log = new QPlainTextEdit(centralwidget);
        Log->setObjectName("Log");
        Log->setGeometry(QRect(360, 80, 371, 431));
        countlabel = new QLabel(centralwidget);
        countlabel->setObjectName("countlabel");
        countlabel->setGeometry(QRect(440, 50, 201, 31));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        countlabel->setFont(font);
        countlabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        add = new QMenu(menubar);
        add->setObjectName("add");
        update = new QMenu(menubar);
        update->setObjectName("update");
        del = new QMenu(menubar);
        del->setObjectName("del");
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menuchaxun = new QMenu(menubar);
        menuchaxun->setObjectName("menuchaxun");
        menu_2 = new QMenu(menuchaxun);
        menu_2->setObjectName("menu_2");
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName("menu_4");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(add->menuAction());
        menubar->addAction(update->menuAction());
        menubar->addAction(del->menuAction());
        menubar->addAction(menu->menuAction());
        menubar->addAction(menuchaxun->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_4->menuAction());
        add->addAction(addPlace);
        add->addAction(addEdge);
        update->addSeparator();
        update->addAction(updatePlace);
        update->addAction(updateEdge);
        del->addAction(delPlace);
        del->addAction(delEdge);
        menu->addAction(openPlaceFile);
        menu->addAction(openEdgeFile);
        menu->addAction(savefile);
        menuchaxun->addAction(menu_2->menuAction());
        menuchaxun->addAction(searchForEdge);
        menu_2->addAction(searchForPlaceByName);
        menu_2->addAction(searchForPlacesByType);
        menu_2->addAction(searchByTime);
        menu_3->addAction(showAllPlaces);
        menu_3->addAction(showAllEdges);
        menu_3->addAction(resetGraph);
        menu_3->addAction(printGraph);
        menu_3->addAction(clearLog);
        menu_4->addAction(isConnected);
        menu_4->addAction(hasEulerPath);
        menu_4->addAction(showEulerPath);
        menu_4->addAction(shortestPath);
        menu_4->addAction(findMST);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        addPlace->setText(QCoreApplication::translate("MainWindow", "\345\234\260\347\202\271", nullptr));
        addEdge->setText(QCoreApplication::translate("MainWindow", "\350\267\257\345\276\204", nullptr));
        updatePlace->setText(QCoreApplication::translate("MainWindow", "\347\211\271\345\256\232\345\234\260\347\202\271\346\216\250\350\215\220\346\270\270\347\216\251\346\227\266\351\227\264", nullptr));
        updateEdge->setText(QCoreApplication::translate("MainWindow", "\347\211\271\345\256\232\350\267\257\345\276\204\346\235\203\351\207\215", nullptr));
        delPlace->setText(QCoreApplication::translate("MainWindow", "\345\234\260\347\202\271", nullptr));
        delEdge->setText(QCoreApplication::translate("MainWindow", "\350\267\257\345\276\204", nullptr));
        searchForEdge->setText(QCoreApplication::translate("MainWindow", "\346\237\220\344\270\252\345\234\260\347\202\271\350\277\236\346\216\245\347\232\204\346\211\200\346\234\211\350\267\257\345\276\204", nullptr));
        searchForPlaceByName->setText(QCoreApplication::translate("MainWindow", "\346\214\211\345\220\215\347\247\260", nullptr));
        searchForPlacesByType->setText(QCoreApplication::translate("MainWindow", "\346\214\211\347\261\273\345\210\253", nullptr));
        openPlaceFile->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\217\226\345\234\260\347\202\271\346\226\207\344\273\266", nullptr));
        openEdgeFile->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\217\226\351\201\223\350\267\257\346\226\207\344\273\266", nullptr));
        showAllPlaces->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\346\211\200\346\234\211\345\234\260\347\202\271\344\277\241\346\201\257", nullptr));
        showAllEdges->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\346\211\200\346\234\211\351\201\223\350\267\257\344\277\241\346\201\257", nullptr));
        resetGraph->setText(QCoreApplication::translate("MainWindow", "\351\207\215\347\275\256\345\233\276\344\277\241\346\201\257", nullptr));
        printGraph->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\215\260\345\233\276\344\277\241\346\201\257", nullptr));
        clearLog->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\346\230\276\347\244\272\344\270\255\347\232\204\346\227\245\345\277\227\344\277\241\346\201\257", nullptr));
        isConnected->setText(QCoreApplication::translate("MainWindow", "\345\210\244\346\226\255\345\233\276\347\232\204\350\277\236\351\200\232\346\200\247", nullptr));
        hasEulerPath->setText(QCoreApplication::translate("MainWindow", "\345\210\244\346\226\255\346\230\257\345\220\246\345\255\230\345\234\250\346\254\247\346\213\211\350\267\257\345\276\204", nullptr));
        showEulerPath->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\215\260\346\254\247\346\213\211\350\267\257\345\276\204", nullptr));
        shortestPath->setText(QCoreApplication::translate("MainWindow", "\350\256\241\347\256\227\344\270\244\347\202\271\346\234\200\347\237\255\350\267\257\345\276\204", nullptr));
        searchByTime->setText(QCoreApplication::translate("MainWindow", "\346\214\211\345\273\272\350\256\256\346\227\266\351\227\264", nullptr));
        findMST->setText(QCoreApplication::translate("MainWindow", "\346\261\202\346\234\200\345\260\217\347\224\237\346\210\220\346\240\221", nullptr));
        savefile->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\345\233\276\344\277\241\346\201\257", nullptr));
        mapLabel->setText(QString());
        titleLabel->setText(QCoreApplication::translate("MainWindow", "WELCOME TO \346\240\241\345\233\255\345\257\274\350\210\252\347\263\273\347\273\237!!!", nullptr));
        countlabel->setText(QCoreApplication::translate("MainWindow", "\345\234\260\347\202\271\346\225\260\357\274\2320\357\274\214\350\276\271\346\225\260\357\274\2320", nullptr));
        add->setTitle(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240", nullptr));
        update->setTitle(QCoreApplication::translate("MainWindow", "\346\233\264\346\226\260", nullptr));
        del->setTitle(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menuchaxun->setTitle(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\345\234\260\347\202\271", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\346\223\215\344\275\234", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainWindow", "\347\256\227\346\263\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

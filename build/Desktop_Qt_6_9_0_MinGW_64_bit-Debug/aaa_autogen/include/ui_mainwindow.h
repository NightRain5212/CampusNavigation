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
#include <QtWidgets/QPushButton>
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
    QAction *showAllPlaces;
    QAction *showAllEdges;
    QAction *delPlace;
    QAction *delEdge;
    QAction *searchForEdge;
    QAction *searchForPlaceByName;
    QAction *searchForPlacesByType;
    QAction *openPlaceFile;
    QAction *openEdgeFile;
    QWidget *centralwidget;
    QLabel *mapLabel;
    QLabel *titleLabel;
    QPlainTextEdit *Log;
    QPushButton *showAllPlacesBtn;
    QPushButton *showAllEdgesBtn;
    QLabel *countlabel;
    QPushButton *resetBtn;
    QMenuBar *menubar;
    QMenu *add;
    QMenu *update;
    QMenu *del;
    QMenu *menu;
    QMenu *menuchaxun;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1200, 800);
        MainWindow->setMinimumSize(QSize(1200, 800));
        addPlace = new QAction(MainWindow);
        addPlace->setObjectName("addPlace");
        addEdge = new QAction(MainWindow);
        addEdge->setObjectName("addEdge");
        updatePlace = new QAction(MainWindow);
        updatePlace->setObjectName("updatePlace");
        updateEdge = new QAction(MainWindow);
        updateEdge->setObjectName("updateEdge");
        showAllPlaces = new QAction(MainWindow);
        showAllPlaces->setObjectName("showAllPlaces");
        showAllEdges = new QAction(MainWindow);
        showAllEdges->setObjectName("showAllEdges");
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
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        mapLabel = new QLabel(centralwidget);
        mapLabel->setObjectName("mapLabel");
        mapLabel->setGeometry(QRect(20, 60, 401, 701));
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setGeometry(QRect(0, 10, 1200, 20));
        titleLabel->setMinimumSize(QSize(1200, 20));
        titleLabel->setMaximumSize(QSize(1200, 20));
        titleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Log = new QPlainTextEdit(centralwidget);
        Log->setObjectName("Log");
        Log->setGeometry(QRect(440, 180, 401, 441));
        showAllPlacesBtn = new QPushButton(centralwidget);
        showAllPlacesBtn->setObjectName("showAllPlacesBtn");
        showAllPlacesBtn->setGeometry(QRect(880, 140, 111, 41));
        showAllEdgesBtn = new QPushButton(centralwidget);
        showAllEdgesBtn->setObjectName("showAllEdgesBtn");
        showAllEdgesBtn->setGeometry(QRect(1010, 140, 111, 41));
        countlabel = new QLabel(centralwidget);
        countlabel->setObjectName("countlabel");
        countlabel->setGeometry(QRect(880, 60, 241, 51));
        resetBtn = new QPushButton(centralwidget);
        resetBtn->setObjectName("resetBtn");
        resetBtn->setGeometry(QRect(880, 200, 111, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1200, 17));
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
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(add->menuAction());
        menubar->addAction(update->menuAction());
        menubar->addAction(del->menuAction());
        menubar->addAction(menu->menuAction());
        menubar->addAction(menuchaxun->menuAction());
        add->addAction(addPlace);
        add->addAction(addEdge);
        update->addSeparator();
        update->addAction(updatePlace);
        update->addAction(updateEdge);
        del->addAction(delPlace);
        del->addAction(delEdge);
        menu->addAction(openPlaceFile);
        menu->addAction(openEdgeFile);
        menuchaxun->addAction(menu_2->menuAction());
        menuchaxun->addAction(searchForEdge);
        menu_2->addAction(searchForPlaceByName);
        menu_2->addAction(searchForPlacesByType);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        addPlace->setText(QCoreApplication::translate("MainWindow", "\345\234\260\347\202\271", nullptr));
        addEdge->setText(QCoreApplication::translate("MainWindow", "\350\267\257\345\276\204", nullptr));
        updatePlace->setText(QCoreApplication::translate("MainWindow", "\345\234\260\347\202\271", nullptr));
        updateEdge->setText(QCoreApplication::translate("MainWindow", "\350\267\257\345\276\204", nullptr));
        showAllPlaces->setText(QCoreApplication::translate("MainWindow", "\346\211\200\346\234\211\345\234\260\347\202\271\344\277\241\346\201\257", nullptr));
        showAllEdges->setText(QCoreApplication::translate("MainWindow", "\346\211\200\346\234\211\351\201\223\350\267\257\344\277\241\346\201\257", nullptr));
        delPlace->setText(QCoreApplication::translate("MainWindow", "\345\234\260\347\202\271", nullptr));
        delEdge->setText(QCoreApplication::translate("MainWindow", "\350\267\257\345\276\204", nullptr));
        searchForEdge->setText(QCoreApplication::translate("MainWindow", "\350\267\257\345\276\204", nullptr));
        searchForPlaceByName->setText(QCoreApplication::translate("MainWindow", "\346\214\211\345\220\215\347\247\260", nullptr));
        searchForPlacesByType->setText(QCoreApplication::translate("MainWindow", "\346\214\211\347\261\273\345\210\253", nullptr));
        openPlaceFile->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\217\226\345\234\260\347\202\271\346\226\207\344\273\266", nullptr));
        openEdgeFile->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\217\226\351\201\223\350\267\257\346\226\207\344\273\266", nullptr));
        mapLabel->setText(QString());
        titleLabel->setText(QCoreApplication::translate("MainWindow", "WELCOME TO \346\240\241\345\233\255\345\257\274\350\210\252\347\263\273\347\273\237!!!", nullptr));
        showAllPlacesBtn->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\346\211\200\346\234\211\345\234\260\347\202\271\344\277\241\346\201\257", nullptr));
        showAllEdgesBtn->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\346\211\200\346\234\211\351\201\223\350\267\257\344\277\241\346\201\257", nullptr));
        countlabel->setText(QCoreApplication::translate("MainWindow", "\345\234\260\347\202\271\346\225\260\357\274\2320\357\274\214\350\276\271\346\225\260\357\274\2320", nullptr));
        resetBtn->setText(QCoreApplication::translate("MainWindow", "\351\207\215\347\275\256\345\233\276\344\277\241\346\201\257", nullptr));
        add->setTitle(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240", nullptr));
        update->setTitle(QCoreApplication::translate("MainWindow", "\346\233\264\346\226\260", nullptr));
        del->setTitle(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menuchaxun->setTitle(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\345\234\260\347\202\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

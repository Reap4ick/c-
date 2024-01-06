/********************************************************************************
** Form generated from reading UI file 'testqt.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTQT_H
#define UI_TESTQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_testqtClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *testqtClass)
    {
        if (testqtClass->objectName().isEmpty())
            testqtClass->setObjectName("testqtClass");
        testqtClass->resize(600, 400);
        menuBar = new QMenuBar(testqtClass);
        menuBar->setObjectName("menuBar");
        testqtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(testqtClass);
        mainToolBar->setObjectName("mainToolBar");
        testqtClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(testqtClass);
        centralWidget->setObjectName("centralWidget");
        testqtClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(testqtClass);
        statusBar->setObjectName("statusBar");
        testqtClass->setStatusBar(statusBar);

        retranslateUi(testqtClass);

        QMetaObject::connectSlotsByName(testqtClass);
    } // setupUi

    void retranslateUi(QMainWindow *testqtClass)
    {
        testqtClass->setWindowTitle(QCoreApplication::translate("testqtClass", "testqt", nullptr));
    } // retranslateUi

};

namespace Ui {
    class testqtClass: public Ui_testqtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTQT_H

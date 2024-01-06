#include "anothermenu.h"
#include "colours.h"
#include "mycanvas.h"
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QTableWidget>
#include <QInputDialog>
#include <QColorDialog>
#include <QApplication>

AnotherMenu::AnotherMenu(QWidget* parent) : QMainWindow(parent), canvas(nullptr) {
    QPixmap quitpix("quit.png");
    QAction* quit = new QAction(quitpix, "&Quit", this);

    quit->setShortcut(tr("CTRL+Q"));

    QMenu* file;
    file = menuBar()->addMenu("&File");
    file->addSeparator();
    file->addAction(quit);

    qApp->setAttribute(Qt::AA_DontShowIconsInMenus, false);

    connect(quit, &QAction::triggered, qApp, &QApplication::quit);
    toolbar = addToolBar("Toolbar");

    QAction* createTableAction = new QAction("Create Table", this);
    toolbar->addAction(createTableAction);

    connect(createTableAction, &QAction::triggered, this, &AnotherMenu::createTable);

    QAction* startDrawingAction = new QAction("Start Drawing", this);
    toolbar->addAction(startDrawingAction);

    connect(startDrawingAction, &QAction::triggered, this, &AnotherMenu::startDrawingLines);

    QAction* chooseLineColorAction = new QAction("Choose Line Color", this);
    toolbar->addAction(chooseLineColorAction);

    connect(chooseLineColorAction, &QAction::triggered, this, &AnotherMenu::chooseLineColor);

    QAction* startDrawingRectanglesAction = new QAction("Start Drawing Rectangles", this);
    toolbar->addAction(startDrawingRectanglesAction);

    connect(startDrawingRectanglesAction, &QAction::triggered, this, &AnotherMenu::startDrawingRectangles);

    QAction* startDrawingEllipsesAction = new QAction("Start Drawing Ellipses", this);
    toolbar->addAction(startDrawingEllipsesAction);

    connect(startDrawingEllipsesAction, &QAction::triggered, this, &AnotherMenu::startDrawingEllipses);

    QAction* eraseAction = new QAction("Eraser", this);
    toolbar->addAction(eraseAction);

    connect(eraseAction, &QAction::triggered, this, &AnotherMenu::startErasing);

}


void AnotherMenu::startErasing() {
    if (canvas) {
        MyCanvas* eraseCanvas = dynamic_cast<MyCanvas*>(canvas);
        if (eraseCanvas) {
            eraseCanvas->startErasing();
        }
    }
}


void AnotherMenu::createTable() {
    bool ok;
    int rowCount = QInputDialog::getInt(this, tr("Enter Row Count"), tr("Rows:"), 1, 1, 1000, 1, &ok);
    if (ok) {
        int columnCount = QInputDialog::getInt(this, tr("Enter Column Count"), tr("Columns:"), 1, 1, 1000, 1, &ok);
        if (ok) {
            QTableWidget* tableWidget = new QTableWidget(rowCount, columnCount, this);
            setCentralWidget(tableWidget);
        }
    }
}

void AnotherMenu::startDrawingLines() {
    if (!canvas) {
        canvas = new MyCanvas(this);
        setCentralWidget(canvas);
    }
    else {
        dynamic_cast<MyCanvas*>(canvas)->startDrawingLines();
    }
}

void AnotherMenu::chooseLineColor() {
    if (canvas) {
        MyCanvas* lineCanvas = dynamic_cast<MyCanvas*>(canvas);
        if (lineCanvas) {
            QColor chosenColor = QColorDialog::getColor(lineCanvas->getCurrentColor(), this, "Choose Line Color");
            if (chosenColor.isValid()) {
                lineCanvas->chooseColor(chosenColor);
            }
        }
    }
}

void AnotherMenu::startDrawingRectangles() {
    if (canvas) {
        MyCanvas* rectCanvas = dynamic_cast<MyCanvas*>(canvas);
        if (rectCanvas) {
            rectCanvas->startDrawingRectangles();
        }
    }
}

void AnotherMenu::startDrawingEllipses() {
    if (canvas) {
        MyCanvas* ellipseCanvas = dynamic_cast<MyCanvas*>(canvas);
        if (ellipseCanvas) {
            ellipseCanvas->startDrawingEllipses();
        }
}
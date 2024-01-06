#ifndef ANOTHERMENU_H
#define ANOTHERMENU_H

#include <QMainWindow>
#include <QToolBar>
#include "mycanvas.h"

class AnotherMenu : public QMainWindow
{
    Q_OBJECT

public:
    AnotherMenu(QWidget* parent = nullptr);

private slots:
    void createTable();
    void startDrawingLines();
    void chooseLineColor();
    void startDrawingRectangles();
    void startDrawingEllipses();
    void startErasing();

private:
    QToolBar* toolbar;
    MyCanvas* canvas;
};

#endif 



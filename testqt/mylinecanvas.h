#ifndef MYLINECANVAS_H
#define MYLINECANVAS_H

#include <QWidget>
#include <QColor>
#include <QList>
#include <QLineF>

enum DrawingMode {
    Freehand,
    Lines
};

class MyLineCanvas : public QWidget
{
    Q_OBJECT

public:
    MyLineCanvas(QWidget* parent = nullptr);

    void startDrawingLines();
    void chooseColor(const QColor& color);
    void clearCanvas();

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private:
    QList<QLineF> lines;
    QLineF currentLine;
    QPoint prevPos;
    QColor currentColor;
    DrawingMode currentDrawingMode;
};

#endif

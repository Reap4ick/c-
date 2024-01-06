#ifndef MYRECTANGLECANVAS_H
#define MYRECTANGLECANVAS_H

#include <QWidget>
#include <QVector>
#include <QRect>

class MyRectangleCanvas : public QWidget {
    Q_OBJECT

public:
    MyRectangleCanvas(QWidget* parent = nullptr);

    void chooseColor();

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private:
    QVector<QRect> rectanglesList;
    QVector<QColor> rectangleColors;
    QRect currentRectangle;
    QColor currentColor;

    bool isDrawingRectangle;
};

#endif

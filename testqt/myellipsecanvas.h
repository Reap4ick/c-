#ifndef MYELLIPSECANVAS_H
#define MYELLIPSECANVAS_H

#include <QWidget>
#include <QVector>
#include <QRect>
#include <QColorDialog>
#include <QPainter>

class MyEllipseCanvas : public QWidget {
    Q_OBJECT

public:
    MyEllipseCanvas(QWidget* parent = nullptr);

    void chooseColor();
    void startDrawingEllipses();

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private:
    QVector<QRect> ellipses;
    QColor currentColor;
    bool drawingEllipses;

    void drawEllipses(QPainter& painter);
};

#endif

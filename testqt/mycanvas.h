#ifndef MYCANVAS_H
#define MYCANVAS_H

#include <QWidget>
#include <QPainterPath>
#include <QColor>

class MyCanvas : public QWidget
{
    Q_OBJECT

public:
    enum DrawingMode {
        Freehand,
        Ellipses,
        Rectangles,
        Eraser
    };

    struct DrawingObject {
        QPainterPath path;
        QColor color;
    };

    MyCanvas(QWidget* parent = nullptr);
    ~MyCanvas();

    void startDrawingEllipses();
    void startDrawingRectangles();
    void startDrawingLines();
    void startErasing(); 
    void chooseColor(const QColor& color);
    void clearCanvas();
    QColor getCurrentColor() const;

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private:

    void erase(const QPoint& pos);
    void updateEllipseRect(const QPoint& endPoint);
    void updateRectangle(const QPoint& endPoint);
    void addDrawingObject(const QPainterPath& path, const QColor& color);

    QColor currentColor;
    DrawingMode currentDrawingMode;
    QPainterPath currentFreehandPath;
    QRect currentEllipseRect;
    QRect currentRectangle;
    QPoint prevPoint;
    QList<DrawingObject> drawingObjects;
};

#endif

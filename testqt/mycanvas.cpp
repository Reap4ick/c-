#include "mycanvas.h"
#include <QPainterPath>
#include <QMouseEvent>
#include <QPainter>
#include <QColorDialog>

MyCanvas::~MyCanvas() {}



MyCanvas::MyCanvas(QWidget* parent) : QWidget(parent), currentColor(Qt::black), currentDrawingMode(DrawingMode::Freehand) {
    prevPoint = QPoint();
}

void MyCanvas::startErasing() {
    currentDrawingMode = DrawingMode::Eraser;
    currentFreehandPath = QPainterPath();
    currentEllipseRect = QRect();
    currentRectangle = QRect();
}

void MyCanvas::erase(const QPoint& pos)
{
    QPainterPath erasePath;
    erasePath.addEllipse(pos, 10, 10); 
    drawingObjects.erase(std::remove_if(drawingObjects.begin(), drawingObjects.end(),
        [&](const DrawingObject& obj) { return erasePath.intersects(obj.path.boundingRect()); }),
        drawingObjects.end());
}





void MyCanvas::startDrawingEllipses() {
    currentDrawingMode = DrawingMode::Ellipses;
    currentFreehandPath = QPainterPath();
    currentRectangle = QRect();

}

void MyCanvas::startDrawingRectangles() {
    currentDrawingMode = DrawingMode::Rectangles;
    currentFreehandPath = QPainterPath();
    currentRectangle = QRect();
}

void MyCanvas::startDrawingLines() {
    currentDrawingMode = DrawingMode::Freehand;
    currentFreehandPath = QPainterPath();
}


void MyCanvas::chooseColor(const QColor& color) {
    currentColor = color;
}

void MyCanvas::clearCanvas() {
    drawingObjects.clear();
    currentFreehandPath = QPainterPath();
    currentEllipseRect = QRect();
    currentRectangle = QRect();
    update();
}

QColor MyCanvas::getCurrentColor() const {
    return currentColor;
}

void MyCanvas::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    for (const auto& obj : drawingObjects) {
        painter.setPen(QPen(obj.color, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        painter.drawPath(obj.path);
    }

    painter.setPen(QPen(currentColor, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    if (currentDrawingMode == DrawingMode::Ellipses) {
        painter.drawEllipse(currentEllipseRect.normalized());
    }
    else if (currentDrawingMode == DrawingMode::Rectangles) {
        painter.drawRect(currentRectangle.normalized());
    }
    else {
        painter.drawPath(currentFreehandPath);
    }
}


void MyCanvas::mousePressEvent(QMouseEvent* event) {
    if (currentDrawingMode == DrawingMode::Freehand) {
        currentFreehandPath.moveTo(event->pos());
    }
    prevPoint = event->pos();
    event->accept();
}










void MyCanvas::mouseMoveEvent(QMouseEvent* event) {
    if (event->buttons() & Qt::LeftButton) {
        if (currentDrawingMode == DrawingMode::Freehand) {
            currentFreehandPath.lineTo(event->pos());
        }
        else if (currentDrawingMode == DrawingMode::Ellipses) {
            updateEllipseRect(event->pos());
        }
        else if (currentDrawingMode == DrawingMode::Rectangles) {
            updateRectangle(event->pos());
        }
        else if (currentDrawingMode == DrawingMode::Eraser) {
            erase(event->pos());
        }

        update();
    }
}

void MyCanvas::mouseReleaseEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        if (currentDrawingMode == DrawingMode::Ellipses) {
            updateEllipseRect(event->pos());
            QPainterPath ellipsePath;
            ellipsePath.addEllipse(currentEllipseRect.normalized());
            addDrawingObject(ellipsePath, currentColor);
        }
        else if (currentDrawingMode == DrawingMode::Rectangles) {
            updateRectangle(event->pos());
            QPainterPath rectPath;
            rectPath.addRect(currentRectangle.normalized());
            addDrawingObject(rectPath, currentColor);
        }
        else if (currentDrawingMode == DrawingMode::Freehand) {
            currentFreehandPath.lineTo(event->pos());
            addDrawingObject(currentFreehandPath, currentColor);
        }
    }

    currentFreehandPath = QPainterPath();
    currentEllipseRect = QRect();
    currentRectangle = QRect();

    update();
}







void MyCanvas::updateEllipseRect(const QPoint& endPoint) {
    currentEllipseRect = QRect(prevPoint, endPoint).normalized();
}

void MyCanvas::updateRectangle(const QPoint& endPoint) {
    currentRectangle = QRect(prevPoint, endPoint).normalized();
}

void MyCanvas::addDrawingObject(const QPainterPath& path, const QColor& color) {
    DrawingObject drawingObject;
    drawingObject.path = path;
    drawingObject.color = color;
    drawingObjects.append(drawingObject);
}
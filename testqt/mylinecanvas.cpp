#include "mylinecanvas.h"
#include <QMouseEvent>
#include <QPainter>

MyLineCanvas::MyLineCanvas(QWidget* parent) : QWidget(parent), currentColor(Qt::black), currentDrawingMode(DrawingMode::Freehand) {
    prevPos = QPoint();
}

void MyLineCanvas::startDrawingLines() {
    currentDrawingMode = DrawingMode::Lines;
}

void MyLineCanvas::chooseColor(const QColor& color) {
    currentColor = color;
}

void MyLineCanvas::clearCanvas() {
    lines.clear();
    currentLine = QLineF();
    update();
}

void MyLineCanvas::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setPen(QPen(currentColor, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    for (const auto& line : lines) {
        painter.drawLine(line);
    }

    painter.drawLine(currentLine);
}

void MyLineCanvas::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        prevPos = event->pos();
    }
}

void MyLineCanvas::mouseMoveEvent(QMouseEvent* event) {
    if (event->buttons() & Qt::LeftButton) {
        if (currentDrawingMode == DrawingMode::Lines) {
            QPointF currentPos = event->pos();
            currentLine.setP1(prevPos);
            currentLine.setP2(currentPos);
            update();
        }
    }
}

void MyLineCanvas::mouseReleaseEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        if (currentDrawingMode == DrawingMode::Lines) {
            QPointF endPos = event->pos();
            lines.append(currentLine);
            currentLine = QLineF();
            update();
        }
    }
}

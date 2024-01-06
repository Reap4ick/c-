#include "myellipsecanvas.h"
#include <QMouseEvent>
#include <QPainter>

MyEllipseCanvas::MyEllipseCanvas(QWidget* parent)
    : QWidget(parent),
    drawingEllipses(false) {
    setMouseTracking(true);
}

void MyEllipseCanvas::chooseColor() {
    currentColor = QColorDialog::getColor(currentColor, this);
}

void MyEllipseCanvas::startDrawingEllipses() {
    drawingEllipses = true;
}

void MyEllipseCanvas::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    if (drawingEllipses) {
        drawEllipses(painter);
    }
}

void MyEllipseCanvas::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton && drawingEllipses) {
        QRect currentEllipse;
        currentEllipse.setTopLeft(event->pos());
        ellipses.append(currentEllipse);
    }
}

void MyEllipseCanvas::mouseMoveEvent(QMouseEvent* event) {
    if ((event->buttons() & Qt::LeftButton) && drawingEllipses) {
        QRect& currentEllipse = ellipses.last();
        currentEllipse.setBottomRight(event->pos());

        update(); 
    }
}

void MyEllipseCanvas::mouseReleaseEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton && drawingEllipses) {
        QRect& currentEllipse = ellipses.last();
        currentEllipse.setBottomRight(event->pos());

        update();  
    }
}

void MyEllipseCanvas::drawEllipses(QPainter& painter) {
    painter.setPen(QPen(currentColor, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    for (const QRect& ellipse : ellipses) {
        painter.drawEllipse(ellipse);
    }
}

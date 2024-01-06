#include "myrectanglecanvas.h"
#include <QPainter>
#include <QMouseEvent>
#include <QColorDialog>

MyRectangleCanvas::MyRectangleCanvas(QWidget* parent) : QWidget(parent), isDrawingRectangle(false) {
    currentColor = Qt::black;
}

void MyRectangleCanvas::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);
    QPainter painter(this);

    for (int i = 0; i < rectanglesList.size(); ++i) {
        painter.setPen(Qt::black);
        painter.setBrush(rectangleColors[i]);
        painter.drawRect(rectanglesList[i]);
    }

    painter.setPen(Qt::black);
    painter.setBrush(currentColor);

    if (isDrawingRectangle) {
        painter.drawRect(currentRectangle);
    }
}

void MyRectangleCanvas::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        if (!isDrawingRectangle) {
            currentRectangle.setTopLeft(event->pos());
            currentRectangle.setBottomRight(event->pos());
            isDrawingRectangle = true;
        }
        else {
            rectanglesList.append(currentRectangle);
            rectangleColors.append(currentColor);
            isDrawingRectangle = false;
            update();
        }
    }
}



void MyRectangleCanvas::mouseMoveEvent(QMouseEvent* event) {
    if (isDrawingRectangle && (event->buttons() & Qt::LeftButton)) {
        currentRectangle.setBottomRight(event->pos());
        update();
    }
}

void MyRectangleCanvas::mouseReleaseEvent(QMouseEvent* event) {
    if (isDrawingRectangle && (event->button() == Qt::LeftButton)) {
        rectanglesList.append(currentRectangle);
        rectangleColors.append(currentColor);
        isDrawingRectangle = false;
        update();
    }
}

void MyRectangleCanvas::chooseColor() {
    QColor newColor = QColorDialog::getColor(currentColor, this, tr("Choose Color"));
    if (newColor.isValid()) {
        currentColor = newColor;
    }
    update();
}

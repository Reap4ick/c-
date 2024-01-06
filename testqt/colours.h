#pragma once

#include <QWidget>

class Colours : public QWidget {
public:
    Colours(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* e);

private:
    void doPainting();
};

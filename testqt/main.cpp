#include "anothermenu.h"
#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    AnotherMenu w;
    w.show();
    return a.exec();
}

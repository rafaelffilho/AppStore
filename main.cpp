#include "appstore.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AppStore w;
    w.show();

    return a.exec();
}

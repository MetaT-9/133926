#include "calculatorfx.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CalculatorFX w;
    w.show();

    return a.exec();
}

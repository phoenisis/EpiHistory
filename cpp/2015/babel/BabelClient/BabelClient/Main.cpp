#include <QApplication>
#include "qbabel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QBabel w;
    w.show();
    
    return a.exec();
}

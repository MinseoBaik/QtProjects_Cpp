#include "mocknotepad.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MockNotepad w;
    w.show();
    return a.exec();
}

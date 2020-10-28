#include "todolist.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    todolist w;
    w.show();
    return a.exec();
}

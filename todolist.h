#ifndef TODOLIST_H
#define TODOLIST_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class todolist; }
QT_END_NAMESPACE

class todolist : public QMainWindow
{
    Q_OBJECT

public:
    todolist(QWidget *parent = nullptr);
    ~todolist();

private:
    Ui::todolist *ui;
};
#endif // TODOLIST_H

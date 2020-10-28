#include "todolist.h"
#include "ui_todolist.h"

todolist::todolist(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::todolist)
{
    ui->setupUi(this);
}

todolist::~todolist()
{
    delete ui;
}


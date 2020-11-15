#include "todopomo.h"
#include "ui_todopomo.h"
#include <QToolBar>
#include <QBoxLayout>
#include <QTimer>

ToDoPomo::ToDoPomo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ToDoPomo)
{
    ui->setupUi(this);
    dakika=25;
    saniye=00;

    QHBoxLayout* pHLayout = ui->horizontalLayout;
    m_pwPending = ui->listView;
    m_pwPending->setDragEnabled(true);
    m_pwPending->setAcceptDrops(true);
    m_pwPending->setDropIndicatorShown(true);
    m_pwPending->setDefaultDropAction(Qt::MoveAction);
    pHLayout->addWidget(m_pwPending);

    QHBoxLayout* pHLayout_2 = ui->horizontalLayout_2;
    m_pwCompleted = ui->listView_2;
    m_pwCompleted->setDragEnabled(true);
    m_pwCompleted->setAcceptDrops(true);
    m_pwCompleted->setDropIndicatorShown(true);
    m_pwCompleted->setDefaultDropAction(Qt::MoveAction);
    pHLayout_2->addWidget(m_pwCompleted);

    m_pwPending->setModel(new QStringListModel());
    m_pwCompleted->setModel(new QStringListModel());


    m_pwPending->setStyleSheet
    ("QListView { font-size: 20pt; font-weight: bold; }"
     "QListView::item { background-color: #E74C3C; padding: 10%;"
     "border: 1px solid #C0392B; }"
     "QListView::item::hover { background-color: #C0392B }");

    m_pwCompleted->setStyleSheet
    ("QListView { font-size: 20pt; font-weight: bold; }"
     "QListView::item { background-color: #2ECC71; padding: 10%;"
     "border: 1px solid #27AE60; }"
     "QListView::item::hover { background-color: #27AE60 }");


    QToolBar* pToolBar = ui->toolBar;
    addToolBar(pToolBar);

    m_pActAdd = new QAction(this);
    m_pActAdd->setIcon(QIcon(":/resources/add.png"));
    connect(m_pActAdd, &QAction::triggered, this, &ToDoPomo::onAdd);

    m_pActRemove = new QAction(this);
    m_pActRemove->setIcon(QIcon(":/resources/remove.png"));
    connect(m_pActRemove, &QAction::triggered, this, &ToDoPomo::onRemove);

    m_pActStart = new QAction(this);
    m_pActStart->setIcon(QIcon(":/resources/start.png"));
    connect(m_pActStart, &QAction::triggered, this, &ToDoPomo::startTimer);

    m_pActStop = new QAction(this);
    m_pActStop->setIcon(QIcon(":/resources/stop.png"));
    connect(m_pActStop, &QAction::triggered, this, &ToDoPomo::stopTimer);

    pToolBar->addAction(m_pActAdd);
    pToolBar->addAction(m_pActRemove);
    pToolBar->addAction(m_pActStart);
    pToolBar->addAction(m_pActStop);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ToDoPomo::downTimer);

    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::Window | Qt::FramelessWindowHint);
    //ui->quickWidget->setSource(QUrl::fromLocalFile("QuickForm.ui.qml"));
   // ui->quickWidget->show();

}

ToDoPomo::~ToDoPomo()
{
    delete ui;
}

void ToDoPomo::onAdd()
{
    m_pwPending = ui->listView;
    m_pwPending->model()->insertRow(m_pwPending->model()->rowCount());
    QModelIndex oIndex = m_pwPending->model()->index(m_pwPending->model()->rowCount() - 1, 0);
    ui->listView->edit(oIndex);
}

void ToDoPomo::onRemove()
{
    QModelIndex oIndex = ui->listView->currentIndex();
    ui->listView->model()->removeRow(oIndex.row());
}

void ToDoPomo::setTimer()
{

}

void ToDoPomo::startTimer()
{
    timer->start(1000);
    downTimer();
}

void ToDoPomo::stopTimer()
{
    timer->stop();
    dakika=25;
    saniye=0;
}

void ToDoPomo::downTimer()
{
    static uint16_t percentagePb;
    if(saniye==0 && dakika==0)
    {
        //UYARI VER
    }

    else if(saniye==0 && dakika!=0)
    {
        dakika-=1;
        saniye=59;
    }
    else if(saniye!=0)
    {
        saniye-=1;
    }
    ui->label_dakika->setNum(dakika);
    ui->label_saniye->setNum(saniye);

    percentagePb=(saniye+dakika*60)*100/1500;
    ui->progressBar->setValue(percentagePb);
}




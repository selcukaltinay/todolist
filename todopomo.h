#ifndef TODOPOMO_H
#define TODOPOMO_H

#include <QMainWindow>
#include <QListView>
#include <QStringListModel>
#include <QLabel>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class ToDoPomo; }
QT_END_NAMESPACE

class ToDoPomo : public QMainWindow
{
    Q_OBJECT

public:
    ToDoPomo(QWidget *parent = nullptr);
    ~ToDoPomo();
    int dakika, saniye;

protected slots:
    void onAdd();
    void onRemove();
    void setTimer();
    void startTimer();
    void stopTimer();
    void downTimer();
private:
    QListView* m_pwPending = nullptr;
    QListView* m_pwCompleted = nullptr;
    QTimer *timer = nullptr;
    QAction* m_pActAdd = nullptr;
    QAction* m_pActRemove = nullptr;
    QAction* m_pActStart = nullptr;
    QAction* m_pActStop = nullptr;

    Ui::ToDoPomo *ui;

};
#endif // TODOPOMO_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFont>
#include <QTimer>
#include <QTime>
#include <QLabel>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    /* Будем использовать только один слот */
private slots:
    void slotTimerAlarm();

private:
    Ui::MainWindow *ui;
    /* Да сам объект QTimer */
    QTimer *timer;
};

#endif // MAINWINDOW_H

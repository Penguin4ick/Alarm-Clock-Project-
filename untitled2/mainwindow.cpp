#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /* Немножко подшаманим QLabel, чтобы он был больше,
     * и заметнее в пустующем окне
     * */
    QFont font("Times", 28, QFont::Bold);
    ui->label->setFont(font);

    /* При первом запуске приложения поместим текущее время в QLabel
     * */
    ui->label->setText(QTime::currentTime().toString("hh:mm:ss"));

    /* Инициализируем Таймер и подключим его к слоту,
     * который будет обрабатывать timeout() таймера
     * */
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));
    timer->start(1000); // И запустим таймер
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* Слот для обработки timeout() таймера
 * */
void MainWindow::slotTimerAlarm()
{
    /* Ежесекундно обновляем данные по текущему времени
     * Перезапускать таймер не требуется
     * */
    ui->label->setText(QTime::currentTime().toString("hh:mm:ss"));
}

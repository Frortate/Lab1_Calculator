#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QLabel"
#include "QLineEdit"
#include "QSlider"
#include "QPushButton"
#include "QTextEdit"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private:
    Ui::MainWindow *ui;
    QLineEdit *lan;
    QPushButton *btnPlus;
    QPushButton *btnMinus;
    QPushButton *btnRavn;
    QPushButton *btnUmnoj;
    QPushButton *btnRazdel;
    QPushButton *btnFD;
    QPushButton *btnHD;
    QPushButton *btnD;
    QLabel *history;

private slots:
    void textLabel();
    void Operation();
    void Result();
    void Clear();
};
#endif // MAINWINDOW_H

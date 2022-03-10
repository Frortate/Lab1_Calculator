#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPushButton"
#include "QGridLayout"
#include "QLabel"
#include "QSlider"
#include "QLineEdit"


// -----> переменная для хранения первого числа <-----
double fNum;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

QWidget *window = new QWidget;

this->setWindowTitle("Калькулятор QT");
this->setFixedSize(280,255);
QString i1 = "1";
QString i2 = "2";

history = new QLabel();
history->show();
history->setWindowTitle("История");
history->setFixedSize(200,255);





// -----> Кнопки и поле ввода <-----
         QPushButton *btn1 = new QPushButton("1");
         QPushButton *btn2 = new QPushButton("2");
         QPushButton *btn3 = new QPushButton("3");
         QPushButton *btn4 = new QPushButton("4");
         QPushButton *btn5 = new QPushButton("5");
         QPushButton *btn6 = new QPushButton("6");
         QPushButton *btn7 = new QPushButton("7");
         QPushButton *btn8 = new QPushButton("8");
         QPushButton *btn9 = new QPushButton("9");
         QPushButton *btn0 = new QPushButton("0");

         btnPlus = new QPushButton("+");
         btnMinus = new QPushButton( "-");
         btnRavn = new QPushButton("=");
         btnUmnoj = new QPushButton("*");
         btnRazdel = new QPushButton("÷");

         btnFD = new QPushButton("All Cleen");
         btnHD = new QPushButton("Hist CL");
         btnD = new QPushButton("Cleen");

         lan = new QLineEdit();
         lan->setReadOnly(true);


// -----> Размеры кнопок и поля ввода <-----
         btn1->setFixedSize(50,50);
         QPalette col = btn1->palette();
         col.setColor(btn1->backgroundRole(), QColor(255,255,255));
         btn1->setPalette(col);
         btn2->setFixedSize(50,50);
         btn3->setFixedSize(50,50);
         btn4->setFixedSize(50,50);
         btn5->setFixedSize(50,50);
         btn6->setFixedSize(50,50);
         btn7->setFixedSize(50,50);
         btn8->setFixedSize(50,50);
         btn9->setFixedSize(50,50);
         btn0->setFixedSize(50,50);

         btnPlus->setFixedSize(50,50);
         btnMinus->setFixedSize(50,50);
         btnRavn->setFixedSize(50,50);
         btnUmnoj->setFixedSize(50,50);
         btnRazdel->setFixedSize(50,50);

         btnFD->setFixedSize(70,40);
         btnHD->setFixedSize(70,40);
         btnD->setFixedSize(100,40);

         lan->setFixedSize(257,30);



// -----> Слои QHBoxLayout <-----
         QHBoxLayout *layDP = new QHBoxLayout;
         layDP->addWidget(btnFD);
         layDP->addWidget(btnHD);

         QHBoxLayout *lay1 = new QHBoxLayout;
         lay1->addWidget(btn1);
         lay1->addWidget(btn2);
         lay1->addWidget(btn3);

         QHBoxLayout *lay2 = new QHBoxLayout;
         lay2->addWidget(btn4);
         lay2->addWidget(btn5);
         lay2->addWidget(btn6);

         QHBoxLayout *lay3 = new QHBoxLayout;
         lay3->addWidget(btn7);
         lay3->addWidget(btn8);
         lay3->addWidget(btn9);

         QHBoxLayout *lay11 = new QHBoxLayout;
         lay11->addWidget(btnPlus);
         lay11->addWidget(btnMinus);

         QHBoxLayout *lay21 = new QHBoxLayout;
         lay21->addWidget(btnUmnoj);
         lay21->addWidget(btnRazdel);

         QHBoxLayout *lay31 = new QHBoxLayout;
         lay31->addWidget(btn0);
         lay31->addWidget(btnRavn);


// -----> Сетка <-----
         QGridLayout* glayout1 = new QGridLayout();
         glayout1->addWidget(lan,1,1,1,2);
         glayout1->addItem(layDP,2,1);
         glayout1->addWidget(btnD,2,2);
         glayout1->addItem(lay1,3,1);
         glayout1->addItem(lay2,4,1);
         glayout1->addItem(lay3,5,1);
         glayout1->addItem(lay11,3,2);
         glayout1->addItem(lay21,4,2);
         glayout1->addItem(lay31,5,2);



// -----> Connect <-----
        QObject::connect(btn0,SIGNAL(clicked()),this, SLOT(textLabel()));
        QObject::connect(btn1,SIGNAL(clicked()),this, SLOT(textLabel()));
        QObject::connect(btn2,SIGNAL(clicked()),this, SLOT(textLabel()));
        QObject::connect(btn3,SIGNAL(clicked()),this, SLOT(textLabel()));
        QObject::connect(btn4,SIGNAL(clicked()),this, SLOT(textLabel()));
        QObject::connect(btn5,SIGNAL(clicked()),this, SLOT(textLabel()));
        QObject::connect(btn6,SIGNAL(clicked()),this, SLOT(textLabel()));
        QObject::connect(btn7,SIGNAL(clicked()),this, SLOT(textLabel()));
        QObject::connect(btn8,SIGNAL(clicked()),this, SLOT(textLabel()));
        QObject::connect(btn9,SIGNAL(clicked()),this, SLOT(textLabel()));

        QObject::connect(btnPlus,SIGNAL(clicked()),this, SLOT(Operation()));
        QObject::connect(btnMinus,SIGNAL(clicked()),this, SLOT(Operation()));
        QObject::connect(btnUmnoj,SIGNAL(clicked()),this, SLOT(Operation()));
        QObject::connect(btnRazdel,SIGNAL(clicked()),this, SLOT(Operation()));
        QObject::connect(btnRavn,SIGNAL(clicked()),this, SLOT(Result()));

        QObject::connect(btnD,SIGNAL(clicked()),this, SLOT(Clear()));
        QObject::connect(btnFD,SIGNAL(clicked()),this, SLOT(Clear()));
        QObject::connect(btnHD,SIGNAL(clicked()),this, SLOT(Clear()));


// -----> Установка bool для кнопок операции <-----
        btnPlus->setCheckable(true);
        btnMinus->setCheckable(true);
        btnUmnoj->setCheckable(true);
        btnRazdel->setCheckable(true);
        btnFD->setCheckable(true);
        btnHD->setCheckable(true);
        btnD->setCheckable(true);


         window->setLayout(glayout1);
         this->setCentralWidget(window);
}


MainWindow::~MainWindow()
{

}

void MainWindow::textLabel()
{

// -----> Переменные <-----
    double i;
    QString lanNum;
    QPushButton *btn = (QPushButton *)sender();


// -----> Преобразование числа для того чтоб они писались вместе <-----
    i=(lan->text()+btn->text()).toDouble();
    lanNum=QString::number(i, 'g' , 20);


// -----> Вывод чисел в Label <-----
    lan->setText(lanNum);

}

void MainWindow::Clear()
{

// -----> Удаление одного символа <-----
    if(btnD->isChecked())
    {
        QString txt = lan->text();
        txt.chop(1);
        lan->setText(txt);
        btnD->setChecked(false);
    }

// -----> Удаление всей строки <-----
    else if(btnFD->isChecked())
    {
        lan->setText("");
        btnFD->setChecked(false);
    }

// -----> Удаление истории <-----
    else if(btnHD->isChecked())
    {
        history->setText(" Вы польностью очистили поле и\n историю!\n--------------------------------------\n");
        btnHD->setChecked(false);
    }
}

void MainWindow::Operation()
{

// -----> Переменные <-----
    QPushButton *btn = (QPushButton *)sender();
    fNum = lan->text().toDouble();


    lan->setText("");
 // -----> Проверка для какого числа было нажато <-----
    btn->setChecked(true);
}


void MainWindow::Result()
{
// -----> Переменные <-----
     double lNum;
     double sNum;
     QString lanNum;
     QString i;
     QString hisNum;
     QString hisFNum;
     QString hisSNum;
     QString hisLNum;


// -----> Последнее число <-----
     sNum=lan->text().toDouble();


// -----> Обработчик операции сложения <-----
     if(btnPlus->isChecked())
     {
         lNum=fNum + sNum;
         lanNum=QString::number(lNum, 'g' , 20);

         hisFNum=QString::number(fNum, 'g' , 20);
         hisSNum=QString::number(sNum, 'g' , 20);

         hisNum = " " + hisFNum + " + " + hisSNum + " = " + lanNum + "\n";

         i = history->text() + hisNum;

         history->setText(i);

         lan->setText(lanNum);
         btnPlus->setChecked(false);
     }

     // -----> Обработчик операции вычитания <-----
        else if(btnMinus->isChecked())
        {
             lNum=fNum - sNum;
             lanNum=QString::number(lNum, 'g' , 20);

             hisFNum=QString::number(fNum, 'g' , 20);
             hisSNum=QString::number(sNum, 'g' , 20);

             hisNum = " " + hisFNum + " - " + hisSNum + " = " + lanNum + "\n";

             i = history->text() + hisNum;

             history->setText(i);

             lan->setText(lanNum);
             btnMinus->setChecked(false);
        }

     // -----> Обработчик операции умножения <-----
            else if(btnUmnoj->isChecked())
            {
                 lNum=fNum * sNum;
                 lanNum=QString::number(lNum, 'g' , 20);

                 hisFNum=QString::number(fNum, 'g' , 20);
                 hisSNum=QString::number(sNum, 'g' , 20);

                 hisNum = " " + hisFNum + " * " + hisSNum + " = " + lanNum + "\n";

                 i = history->text() + hisNum;

                 history->setText(i);

                 lan->setText(lanNum);
                 btnUmnoj->setChecked(false);
            }

     // -----> Обработчик операции деления <-----
                else if(btnRazdel->isChecked())
                {
                     if(sNum == 0)
                     {
                         lan->setText("Нет результата");
                     }
                        else
                        {
                            lNum=fNum / sNum;
                            lanNum=QString::number(lNum, 'g' , 20);

                            hisFNum=QString::number(fNum, 'g' , 20);
                            hisSNum=QString::number(sNum, 'g' , 20);

                            hisNum = " " + hisFNum + " ÷ " + hisSNum + " = " + lanNum + "\n";

                            i = history->text() + hisNum;

                            history->setText(i);

                            lan->setText(lanNum);
                        }

                     btnRazdel->setChecked(false);
                }

}


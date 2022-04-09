#include "win.h"
#include <QTextCodec>
#include <QBoxLayout>

void Counter::add_one()                                          // Слот, добавляющий 1 к счетчику
{
    QString str = text();                                    // Считываем текст из счетчика
    int r = str.toInt();                          // Конвертация текста в число

    if (r !=0 && r % 5 == 0)                 // Если счетчик кратен 5, то вызывается соответсвующий сигнал
    {
        emit tick_signal();
    }

    r++;
    str.setNum(r);                                // Конвертируем это число обратно в строку
    setText(str);                                            // Записываем строку в счетчик
}

Win::Win(QWidget *parent): QWidget(parent)                    // Конструктор создания виджета
{
     QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));       // Установка кодека для русификации виджета

     this->setWindowTitle("Счетчик");                               // Заголовок
     label1 = new QLabel("Cчет по 1",this);                     // Заголовок счётчика по 1
     label2 = new QLabel("Cчет по 5",this);               // Заголовок счётчика по 2
     edit1 = new Counter("0",this);                         // Создание 2-х счетчиков - для счета по 1 и по 5
     edit2 = new Counter("0",this);

     calcbutton=new QPushButton("+1",this);                       // Кнопка +1
     exitbutton=new QPushButton("Выход",this);                      // Кнопка Выход

     QHBoxLayout *layout1 = new QHBoxLayout();                // Создание разметки для заголовков
     layout1->addWidget(label1);
     layout1->addWidget(label2);

     QHBoxLayout *layout2 = new QHBoxLayout();           // Создание разметки для счетчиков
     layout2->addWidget(edit1);
     layout2->addWidget(edit2);

     QHBoxLayout *layout3 = new QHBoxLayout();               // Создание разметки для кнопок
     layout3->addWidget(calcbutton);
     layout3->addWidget(exitbutton);

     QVBoxLayout *layout4 = new QVBoxLayout(this);               // Создание главной разметки для виджета
     layout4->addLayout(layout1);
     layout4->addLayout(layout2);
     layout4->addLayout(layout3);
     layout4->addStretch();                                      // Добавление отступа в главный виджет для корректного отображения при масштабировании окна

     // Cвязь сигнала нажатия кнопки и слота закрытия окна
     connect(calcbutton,SIGNAL(clicked(bool)), edit1,SLOT(addOne()));
     connect(edit1,SIGNAL(multipleFiveSignal()), edit2,SLOT(addOne()));
     connect(exitbutton,SIGNAL(clicked(bool)), this,SLOT(close()));
}



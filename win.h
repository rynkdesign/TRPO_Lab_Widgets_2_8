#ifndef WIN_H
#define WIN_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

class Counter:public QLineEdit                              // Класс виджета строки счетчика
{
    Q_OBJECT                                                    // Макрос подключения слотов и сигналов к классу
public:
    Counter(const QString & contents, QWidget *parent=0):   // Конструктор
    QLineEdit(contents,parent){}

signals:
    void tick_signal();                                  // Сигнал, срабатывает когда счетчик кратен 5

public slots:
    void add_one();                                              // Слот, добавляющий 1 к счетчику

};

class Win : public QWidget                            // Класс виджета для счетчика
{
    Q_OBJECT                                                    // Макрос подключения сигналов и слотов к классу

protected:
    QLabel *label1,*label2;                       // Заголовки над счетчиками
    Counter *edit1,*edit2;                        // Счетчики
    QPushButton *calcbutton;                                  // Кнопка добавления 1 к счетчику
    QPushButton *exitbutton;                                    // Кнопка Выход

public:
    Win(QWidget *parent = nullptr);
};
#endif // WIN_H

#include "form_task.h"
#include "ui_form_task.h"

/**
 * @brief конструктор, создание формы задания
 * @param parent
 */
Form_task::Form_task(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_task)
{
    ui->setupUi(this);
}

/**
 * @brief деструктор, для закрытия формы задания
 */
Form_task::~Form_task()
{
    delete ui;
}

/**
 * @brief переход к проверке задания из формы задания
 */
void Form_task::clear_all()
{
    ui->lineEdit->clear();
}

/**
 * @brief Form_task::on_pushButton_ok_clicked заполнение вектора ответами пользователя и последующая проверка
 */
void Form_task::on_pushButton_ok_clicked()
{
    QString answer = ui->lineEdit->text();
    qDebug() << answer;

    bool solv = check_task(task_num, answer, input);
    if (solv)
    {
        switch(task_num)
        {
        case 1:
            emit solved_now_1();
            break;
        case 2:
            emit solved_now_2();
            break;
        case 3:
            emit solved_now_3();
            break;
        case 4:
            emit solved_now_4();
            break;
        }
    }
    else if (!solv)
    {
        switch(task_num)
        {
        case 1:
            emit not_solved_now_1();
            break;
        case 2:
            emit not_solved_now_2();
            break;
        case 3:
            emit not_solved_now_3();
            break;
        case 4:
            emit not_solved_now_4();
            break;
        }
    }

    clear_all();
    hide();
}

/**
 * @brief выбор задания по номеру
 * @param n - номер задания
 */
void Form_task::set_task(int n)
{
    task_num = n;
    QString task = "";

    switch(task_num)
    {
    //10 | рандом | ответ(Да/Нет)
    case 1:
        ui->egg->hide();
        ui->sun->show();
        input = gen_task1();
        task = "Является ли граф планарным?\n" + input;
        break;
    //19 +картинка | ответ в виде: (?,?,?,...,?), где ? - цифра
    case 2:
        ui->egg->hide();
        ui->sun->hide();
        input = gen_task2();
        task = "Найти код Прюфера для дерева:\n" + input;
        break;
    //2 | ответ в виде числа(веса)
    case 3:
        ui->egg->hide();
        ui->sun->show();
        input = gen_task3();
        task = "Найти кратчайший путь между вершинами s=v1, t=v4 в нагруженном связном ориентированном графе:\n"
                + input
                + "\nНеориентированные ребра (проходимые в обоих направлениях) указаны в фигурных скобках. Ориентированные ребра указаны в круглых скобках.\n"
               "Третья координата ребра есть его вес.";
        break;
    //15 | ответ в виде числа
    case 4:
        ui->egg->hide();
        ui->sun->show();
        input = gen_task4();
        task = "Найти хроматическое число графа:\n" + input;
        break;
    }

    ui->textBrowser_task->setText(task);
}

void Form_task::on_secret_clicked()
{
    static int count = 1;
    if (count > 5)
    {
        ui->egg->hide();
        ui->horror->show();
        ui->sun->show();
        count = 1;

        return;
    }

    if (count == 5)
    {
        ui->sun->hide();
        ui->horror->hide();
        ui->egg->show();
    }

    count++;
}

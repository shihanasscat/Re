#ifndef FORM_TASK_H
#define FORM_TASK_H
#include "client.h"
#include "serverfunctions.h"
#include <QWidget>

namespace Ui
    {
    class Form_task;
    }

class Form_task : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор окна задания
     * @param parent
     */
    explicit Form_task(QWidget* parent = nullptr);

    ~Form_task();
    /**
     * @brief Функция выбора задания по номеру
     * @param n - номер задания
     */
    void set_task(int n);

private slots:
    /**
     * @brief Функция проверки задания после нажатия кнопки оk
     */
    void on_pushButton_ok_clicked();

    void on_secret_clicked();

private:
    /**
     * @brief Окно задания
     */
    Ui::Form_task *ui;
    /**
     * @brief Номер задания
     */
    void clear_all();
    int task_num;
    QString input;
signals:
    void solved_now_1();
    void solved_now_2();
    void solved_now_3();
    void solved_now_4();

    void not_solved_now_1();
    void not_solved_now_2();
    void not_solved_now_3();
    void not_solved_now_4();
};

#endif // FORM_TASK_H

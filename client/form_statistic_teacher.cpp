#include "form_statistic_teacher.h"
#include "ui_form_statistic_teacher.h"
#include "serverfunctions.h"
#include "not_allowed.h"

/**
 * @brief Form_statistic_teacher::Form_statistic_teacher конструктор, создание формы статистики для преподавателя
 * @param parent
 */
Form_statistic_teacher::Form_statistic_teacher(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_statistic_teacher)
{
    not_all = new not_allowed;
    ui->setupUi(this);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->lineEdit->setFocus(Qt::TabFocusReason);
    ui->tableWidget->setVisible(false);
    ui->label_2->setVisible(false);
}
/**
 * @brief Form_statistic_teacher::~Form_statistic_teacher закрытие окна статистики
 */
Form_statistic_teacher::~Form_statistic_teacher()
{
    ui->tableWidget->setVisible(false);
    delete ui;
}
/**
 * @brief Form_statistic_teacher::pars вывод информации о группе в таблицу
 * @param data
 */
void Form_statistic_teacher::pars(QString data){
    qDebug() << data;
    ui->tableWidget->setVisible(true);
    ui->tableWidget->clear();
    QStringList list = data.split("Q", Qt::SkipEmptyParts);
    qDebug() << list.size();
    for (int j = 0; j < list.size(); ++j){
        QStringList now = list[j].split("&", Qt::SkipEmptyParts);
        //qDebug() << j << now;
        for (int i = 0; i < now.size(); ++i){
            qDebug() << now[i];
            ui->tableWidget->setItem(j, i, new QTableWidgetItem(now[i]));
        }
    }
}
/**
 * @brief Form_statistic_teacher::show_statistic получение статистики по группе
 */
void Form_statistic_teacher::show_statistic(){
    ui->tableWidget->setVisible(true);
    get_info(group_num);
    connect(Client::GetInstance(),&Client::get_it,this, &Form_statistic_teacher::pars);
}
/**
 * @brief Form_statistic_teacher::no_access форма предупреждения, что доступа к группе нет
 */
void Form_statistic_teacher::no_access(){
    not_all->show();
    ui->lineEdit->setText("");
}
/**
 * @brief Form_statistic_teacher::on_pushButton_clicked контроль ввода номера группы
 */
void Form_statistic_teacher::on_pushButton_clicked()
{
    ui->label_2->setVisible(false);
    group_num = ui->lineEdit->text();
    QRegularExpression re("[1-9]{3}-[1-9]{3}");
    QRegularExpressionMatch match = re.match(group_num);
    if(match.hasMatch()){
        qDebug() << "true";
        check_access(group_num);
        connect(Client::GetInstance(),&Client::allowed,this, &Form_statistic_teacher::show_statistic);
        connect(Client::GetInstance(),&Client::not_allow,this, &Form_statistic_teacher::no_access);
    }
    else{
        qDebug() << "no";
        ui->label_2->setVisible(true);
        ui->lineEdit->setText("");
    }

}


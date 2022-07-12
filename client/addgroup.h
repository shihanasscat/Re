#ifndef ADDGROUP_H
#define ADDGROUP_H

#include <QWidget>
#include <QRegularExpression>
#include <QMap>
#include <QRegularExpressionMatch>

#include "serverfunctions.h"
#include "cannotchanged.h"

namespace Ui
{
    class addGroup;
}

class addGroup : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief add_group::add_group конструктор, создание формы
     * @param parent
     */
    explicit addGroup(QWidget *parent = nullptr);
    /**
     * @brief add_group::~add_group деструктор, закрытие формы
     */
    ~addGroup();
    /**
     * @brief add_group::clean очищает поля
     */
    void clean();

private slots:
    /**
     * @brief add_group::on_pushButton_clicked добавление группы
     */
    void on_pushButton_clicked();
    /**
     * @brief add_group::no_changes вызов флрмы предупреждения
     */
    void no_changes();

private:
    Ui::addGroup* ui;
    CannotChanged* changes;
};

#endif // ADDGROUP_H

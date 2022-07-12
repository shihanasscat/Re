#include "cannotchange.h"
#include "ui_cannot_change.h"
/**
 * @brief cannot_change::cannot_change конструктор, открытие формы предупреждения
 * @param parent
 */
CannotChange::CannotChanged(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CannotChange)
{
    ui->setupUi(this);
}
/**
 * @brief cannot_change::~cannot_change деструктор, закрытие формы
 */
CannotChange::~CannotChange()
{
    delete ui;
}

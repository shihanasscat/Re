#include "cannotchanged.h"
#include "ui_cannotchanged.h"
/**
 * @brief cannotchange::cannot_change конструктор, открытие формы предупреждения
 * @param parent
 */
CannotChanged::CannotChanged(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cannotchanged)
{
    ui->setupUi(this);
}
/**
 * @brief cannot_change::~cannot_change деструктор, закрытие формы
 */
CannotChanged::~CannotChanged()
{
    delete ui;
}

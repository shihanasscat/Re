#ifndef CANNOTCHANGED_H
#define CANNOTCHANGED_H

#include <QWidget>

namespace Ui
{
    class cannotchanged;
}

class CannotChanged : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief cannot_change::cannot_change конструктор, открытие формы предупреждения
     * @param parent
     */
    explicit CannotChanged(QWidget *parent = nullptr);

    /**
     * @brief cannot_change::~cannot_change деструктор, закрытие формы
     */
    ~CannotChanged();

private:
    Ui::cannotchanged *ui;
};

#endif // CANNOTCHANGED_H

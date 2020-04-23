#ifndef PLAYERUI_H
#define PLAYERUI_H

#include <QDialog>

namespace Ui {
class PlayerUI;
}

class PlayerUI : public QDialog
{
    Q_OBJECT

public:
    explicit PlayerUI(QWidget *parent = nullptr);
    ~PlayerUI();

private:
    Ui::PlayerUI *ui;
};

#endif // PLAYERUI_H

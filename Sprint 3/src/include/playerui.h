#ifndef PLAYERUI_H
#define PLAYERUI_H

#include <QDialog>

class Player;

namespace Ui {
class PlayerUI;
}

class PlayerUI : public QDialog
{
    Q_OBJECT

public:
    explicit PlayerUI(QWidget *parent = nullptr);
    PlayerUI(QWidget *parent , Player* player);
    ~PlayerUI();

private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_order_clicked();

private:
    Ui::PlayerUI *ui;
    Player* Player_instance;
};

#endif // PLAYERUI_H

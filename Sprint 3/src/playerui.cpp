#include "include/playerui.h"
#include "ui_playerui.h"
#include "ui_mainwindow.h"
#include "include/player.h"
#include "include/game.h"
#include <QPixmap>
#include <QMessageBox>
#include <QTimer>


PlayerUI::PlayerUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayerUI)
{
    ui->setupUi(this);
    Player_instance = new Player;
    ui->label_intro->setText("You are logged in as Factory");
    ui->label_Incomingorder->setText(QString::number( Player_instance->getDemand()));
    ui->label_Outgoingorder->setText(QString::number(Player_instance->getOrderPlaced()));
    ui->label_Backorder->setText(QString::number(Player_instance->getBackorder()));
    ui->label_Inventory->setText(QString::number(Player_instance->getInventory()));
    ui->label_Totalcost->setText(QString::number(Player_instance->getCost()));
    ui->pushButton_order->setDisabled(true);
}

PlayerUI::PlayerUI(QWidget *parent, Player *player):
    QDialog(parent),
    ui(new Ui::PlayerUI),
    Player_instance(player)
{
    ui->setupUi(this);
    int role = Player_instance->getRole();
    QString PlayerRole;
    switch(role) {
        case 1 : PlayerRole = "You are logged in as Factory";
                 break;
        case 2 : PlayerRole = "You are logged in as Distributor";
                 break;
        case 3 : PlayerRole = "You are logged in as Wholeseller";
             break;
        case 4 : PlayerRole = "You are logged in as Retailer";
             break;
    }

    ui->label_intro->setText(PlayerRole);
    ui->label_Incomingorder->setText(QString::number( Player_instance->getDemand()));
    ui->label_Outgoingorder->setText(QString::number(Player_instance->getOrderPlaced()));
    ui->label_Backorder->setText(QString::number(Player_instance->getBackorder()));
    ui->label_Inventory->setText(QString::number(Player_instance->getInventory()));
    ui->label_Totalcost->setText(QString::number(Player_instance->getCost()));

}

PlayerUI::~PlayerUI()
{
    delete ui;
}

void PlayerUI::on_pushButton_back_clicked()
{
    hide();
    QWidget *parent = this->parentWidget();
    parent->show();
    this->close();
}

void PlayerUI::on_pushButton_order_clicked()
{
    Player_instance->getGame()->updatePlayerInventories();
    int role = Player_instance->getRole();
    QString PlayerRole;
    switch(role) {
        case 1 : PlayerRole = "You are logged in as Factory";
                 break;
        case 2 : PlayerRole = "You are logged in as Distributor";
                 break;
        case 3 : PlayerRole = "You are logged in as Wholeseller";
             break;
        case 4 : PlayerRole = "You are logged in as Retailer";
             break;
    }

    ui->label_intro->setText(PlayerRole);
    Player_instance->getGame()->updatePlayerInventories();

    ui->label_Incomingorder->setText(QString::number( Player_instance->getDemand()));
    ui->label_Outgoingorder->setText(QString::number(Player_instance->getOrderPlaced()));
    ui->label_Backorder->setText(QString::number(Player_instance->getBackorder()));
    ui->label_Inventory->setText(QString::number(Player_instance->getInventory()));
    ui->label_Totalcost->setText(QString::number(Player_instance->getCost()));


    int order = ui->lineEdit_order->text().toUInt();
    if(!Player_instance->getOrderPlaced()){
        Player_instance->placeOrder(order);
        Player_instance->setOrderPlaced(true);
    }

    if(!Player_instance->getShipmentPlaced()){
        int shipment = Player_instance->getAvailableShipment(Player_instance->getDemand());
        Player_instance->placeShipment(shipment);
        Player_instance->setShipmentPlaced(true);
    }



}

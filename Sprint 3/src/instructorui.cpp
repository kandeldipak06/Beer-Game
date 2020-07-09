#include "include/instructorui.h"
#include "ui_instructorui.h"
#include "ui_mainwindow.h"
#include "include/instructor.h"
#include "include/game.h"
#include <QPixmap>
#include <QMessageBox>
#include <QTimer>

InstructorUI::InstructorUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InstructorUI)
{
    ui->setupUi(this);
    QPixmap pix(":/resource/img/beer.jpg");
    int w = ui->label_pic->height();
    int h = ui->label_pic->width();
    ui->label_pic->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));

    m_typingTimer = new QTimer(this);
    m_typingTimer->setSingleShot(true);
    connect(m_typingTimer, &QTimer::timeout, this, &InstructorUI::on_lineEdit_numOfPlayer_editingFinished);


    ui->lineEdit_numOfPlayer->setText("4");
    ui->lineEdit_BackCost->setText("1");
    ui->lineEdit_HoldCost->setText("0.5");
    ui->lineEdit_FactDelay->setText("1");
    ui->lineEdit_ShipDelay->setText("2");
    ui->lineEdit_WeeksPlayed->setText("26");
    ui->lineEdit_StartInventory->setText("12");
    ui->lineEdit_OrderDelay->setText("2");
    ui->lineEdit_currentWeek->setText("1");

    instructor_instance = new Instructor;

    ui->pushButton_PlayerPass->setDisabled(true);
    ui->pushButton_Proceed->setDisabled(true);


}

InstructorUI::~InstructorUI()
{
    delete ui;
    delete instructor_instance;
}

void InstructorUI::on_pushButton_back_clicked()
{
    hide();
    QWidget *parent = this->parentWidget();
    parent->show();
    this->close();
}

void InstructorUI::on_pushButton_Proceed_clicked()
{
    Game *game_instance = (instructor_instance->getGames()).front();

    game_instance->startGame();

}



void InstructorUI::on_lineEdit_numOfPlayer_editingFinished()
{
    int numbersOfPlayer = ui->lineEdit_numOfPlayer->text().toUInt();
    if (numbersOfPlayer < 3 || numbersOfPlayer > 4) {
        QMessageBox::warning(this,"Error","Invalid number of players");
        numbersOfPlayer = ui->lineEdit_numOfPlayer->text().toUInt();
    }
    Game *game_instance = (instructor_instance->getGames()).front();

    game_instance->setNumberOfPlayers(numbersOfPlayer);

}



void InstructorUI::on_pushButton_PlayerPass_clicked()
{
    Game *game_instance = (instructor_instance->getGames()).front();
    
   (void)game_instance->generatePasswords();
    std::vector<std::string> it = game_instance->getPassword();
    QString pass, a, b, c, d;
    a = QString::fromStdString(it[0]);
    b = QString::fromStdString(it[1]);
    c = QString::fromStdString(it[2]);
    d = QString::fromStdString(it[3]);

    pass = "Factory: %1 \nDistributor: %2 \n Wholeseller: %3 \n Retailer: %4\n";
    QMessageBox::information(this,"Passowrds:",pass.arg(a, b, c, d));
}

void InstructorUI::on_pushButton_createGame_clicked()
{
    int orderDelay = ui->lineEdit_OrderDelay->text().toUInt();
    int shipmentDelay = ui->lineEdit_ShipDelay->text().toUInt();
    double holdingCost = ui->lineEdit_HoldCost->text().toDouble();
    double backorderCost = ui->lineEdit_BackCost->text().toDouble();
    int startingInventory = ui->lineEdit_StartInventory->text().toUInt();
    int weeksToBePlayed = ui->lineEdit_WeeksPlayed->text().toUInt();
    int factoryDelay = ui->lineEdit_FactDelay->text().toUInt();
    int numbersOfPlayer = ui->lineEdit_numOfPlayer->text().toUInt();
    int currentWeek = ui->lineEdit_currentWeek->text().toUInt();

    (void) instructor_instance->createGame();

    Game *game_instance = (instructor_instance->getGames()).front();

    game_instance->setOrderDelay(orderDelay);
    game_instance->setShipmentDelay(shipmentDelay);
    game_instance->setHoldingCost(holdingCost);
    game_instance->setBackorderCost(backorderCost);
    game_instance->setStartingInventory(startingInventory);
    game_instance->setWeeksToBePlayed(weeksToBePlayed);
    game_instance->setFactoryDelay(factoryDelay);
    game_instance->setNumberOfPlayers(numbersOfPlayer);
    game_instance->setCurrentWeek(currentWeek);

    ui->pushButton_PlayerPass->setDisabled(false);
    ui->pushButton_Proceed->setDisabled(false);
    game_instance->setParent_ui(this);

}

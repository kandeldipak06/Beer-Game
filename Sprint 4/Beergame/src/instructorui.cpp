#include "include/instructorui.h"
#include "ui_instructorui.h"
#include <QTimer>
#include <QPixmap>
#include <QMessageBox>

InstructorUI::InstructorUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InstructorUI)
{
    ui->setupUi(this);

    QPixmap pix(":/img/beer.jpg");
    int h = ui->label_pic->height();
    int w = ui->label_pic->width();
    ui->label_pic->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));

    ui->lineEdit_OrderDelay->setText("4");
    ui->lineEdit_HoldingCost->setText("0.5");
    ui->lineEdit_BackOrderCost->setText("1");
    ui->lineEdit_ShipmentDelay->setText("2");
    ui->lineEdit_NumberOfPlayer->setText("4");
    ui->lineEdit_StartInventory->setText("12");
    ui->lineEdit_FactoryDelay->setText("1");

    m_typingTimer = new QTimer(this);
    m_typingTimer->setSingleShot(true);
    connect(m_typingTimer, &QTimer::timeout, this, &InstructorUI::on_lineEdit_OrderDelay_editingFinished);
    connect(m_typingTimer, &QTimer::timeout, this, &InstructorUI::on_lineEdit_HoldingCost_editingFinished);
    connect(m_typingTimer, &QTimer::timeout, this, &InstructorUI::on_lineEdit_FactoryDelay_editingFinished);
    connect(m_typingTimer, &QTimer::timeout, this, &InstructorUI::on_lineEdit_BackOrderCost_editingFinished);
    connect(m_typingTimer, &QTimer::timeout, this, &InstructorUI::on_lineEdit_ShipmentDelay_editingFinished);
    connect(m_typingTimer, &QTimer::timeout, this, &InstructorUI::on_lineEdit_NumberOfPlayer_editingFinished);
    connect(m_typingTimer, &QTimer::timeout, this, &InstructorUI::on_lineEdit_StartInventory_editingFinished);
}

InstructorUI::~InstructorUI()
{
    delete ui;
}

void InstructorUI::on_lineEdit_NumberOfPlayer_editingFinished()
{
    int n = ui->lineEdit_NumberOfPlayer->text().toUInt();
    if(n < 2 || n > 4){
        QMessageBox::warning(this,"Error","Invalid number of Players \nNumber Of Players must be between [2..4]");
        n = ui->lineEdit_NumberOfPlayer->text().toUInt();
    }
}

void InstructorUI::on_lineEdit_OrderDelay_editingFinished()
{
    int n = ui->lineEdit_OrderDelay->text().toUInt();
    if(n < 0){
        QMessageBox::warning(this,"Error","Invalid Order Delay \nOrder Delay must be >= 0");
        n = ui->lineEdit_OrderDelay->text().toUInt();
    }
}

void InstructorUI::on_lineEdit_ShipmentDelay_editingFinished()
{
    int n = ui->lineEdit_ShipmentDelay->text().toUInt();
    if(n < 0){
        QMessageBox::warning(this,"Error","Invalid Shipment Delay \nOrder Delay must be >= 0");
        n = ui->lineEdit_ShipmentDelay->text().toUInt();
    }

}


void InstructorUI::on_lineEdit_HoldingCost_editingFinished()
{
    int n = ui->lineEdit_HoldingCost->text().toUInt();
    if(n < 0){
        QMessageBox::warning(this,"Error","Invalid Holding Cost\nHolding cost must be >= 0");
        n = ui->lineEdit_HoldingCost->text().toUInt();
    }
}

void InstructorUI::on_lineEdit_BackOrderCost_editingFinished()
{
    int n = ui->lineEdit_BackOrderCost->text().toUInt();
    if(n < 0){
        QMessageBox::warning(this,"Error","Invalid BackOrder Cost\nBackOrder cost must be >= 0");
        n = ui->lineEdit_BackOrderCost->text().toUInt();
    }
}


void InstructorUI::on_lineEdit_StartInventory_editingFinished()
{
    int n = ui->lineEdit_StartInventory->text().toUInt();
    if(n < 0){
        QMessageBox::warning(this,"Error","Invalid Starting Inventory \nStarting Inventory must be >= 0");
        n = ui->lineEdit_StartInventory->text().toUInt();
    }
}

void InstructorUI::on_lineEdit_FactoryDelay_editingFinished()
{
    int n = ui->lineEdit_FactoryDelay->text().toUInt();
    if(n < 0){
        QMessageBox::warning(this,"Error","Invalid Factory Delay \nFactory Delay must be >= 0");
        n = ui->lineEdit_FactoryDelay->text().toUInt();
    }
}

void InstructorUI::on_pushButton_createGame_clicked()
{

}

void InstructorUI::on_pushButton_Back_clicked()
{
    hide();
    QWidget *parent = this->parentWidget();
    parent->show();
    this->close();
}

void InstructorUI::on_pushButton_ezit_clicked()
{
    this->close();
}

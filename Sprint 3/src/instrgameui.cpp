#include "include/instrgameui.h"
#include "ui_instrgameui.h"

InstrGameUI::InstrGameUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InstrGameUI)
{
    ui->setupUi(this);
}

InstrGameUI::~InstrGameUI()
{
    delete ui;
}

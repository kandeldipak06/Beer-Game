#include "include/mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QtDebug>
#include <QPixmap>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *m_typingTimer;
    m_typingTimer = new QTimer(this);
    m_typingTimer->setSingleShot(true);
    connect(m_typingTimer, &QTimer::timeout, this, &MainWindow::on_lineEdit_PlayerRole_editingFinished);

//    QPixmap pix(":/resource/img/beer.jpg");
//    int w = ui->label_pic->width();
//    int h = ui->label_pic->width();
//    ui->label_pic->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));


}

MainWindow::~MainWindow()
{
    delete ui;
}


//void MainWindow::on_pushButton_InstrLogin_clicked()
//{
//    QString email = ui->lineEditInstrEmail->text();
//    QString pass = ui->lineEditInstrPass->text();
//    //if(email == "default@abc.com" && pass == "0000"){
//        hide();
//        instrWindow = new InstructorUI (this);
//        instrWindow->show();
////    }else{
////        QMessageBox::warning(this,"Login","Username and password is not correct");
////    }

//}


//void MainWindow::on_pushButton_PlayerSubmit_clicked()
//{
//    QString pass = ui->lineEditPlayerPass->text();
//    int role = ui->lineEditPlayerRole->text().toUInt();
//    //if(pass == "1111"){
//        hide();
//        playerWindow = new PlayerUI (this);

//        playerWindow->show();
////    }else{
////        QMessageBox::warning(this,"Login","Password is not correct");
////    }
//}

void MainWindow::on_pushButton_exit_clicked()
{
    QMessageBox::StandardButton check = QMessageBox::question(this,"Exit", "Do you want to close Beergame?", QMessageBox::Yes | QMessageBox::No);

    if(check == QMessageBox::Yes){
        QApplication::quit();
    }else{
        qDebug() << "exit is negeted";
    }


}



void MainWindow::on_lineEdit_PlayerRole_editingFinished()
{
    int role = ui->lineEdit_PlayerRole->text().toUInt();
    if(role < 1 || role > 4){
        QMessageBox::warning(this,"Error","Invalid Role \n Role must be between [1..4]");
        role = ui->lineEdit_PlayerRole->text().toUInt();
    }
}

void MainWindow::on_pushButton_InstrSubmit_clicked()
{
    QString pass = ui->lineEdit_instrPassword->text();
    QString email = ui->lineEdit_instrEmail->text();
    hide();
    instructor_window = new InstructorUI (this);
    instructor_window->show();
}

void MainWindow::on_pushButton_playerSubmit_clicked()
{

}

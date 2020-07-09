#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "instructorui.h"
#include "playerui.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Exit_clicked();

    void on_pushButton_InstrLogin_clicked();

    void on_pushButton_PlayerSubmit_clicked();

private:
    Ui::MainWindow *ui;
    InstructorUI *instrWindow;
    PlayerUI *playerWindow;

};
#endif // MAINWINDOW_H

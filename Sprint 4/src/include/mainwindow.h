#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "playerui.h"
#include "instructorui.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;
              }
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

    void on_pushButton_exit_clicked();

    void on_lineEdit_PlayerRole_editingFinished();

    void on_pushButton_InstrSubmit_clicked();

    void on_pushButton_playerSubmit_clicked();

private:
    Ui::MainWindow *ui;
    InstructorUI *instructor_window;
    PlayerUI *player_window;

    QTimer *m_typingTimer;

};
#endif // MAINWINDOW_H

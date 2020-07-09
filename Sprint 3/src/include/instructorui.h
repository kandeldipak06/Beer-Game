#ifndef INSTRUCTORUI_H
#define INSTRUCTORUI_H

#include <QDialog>

class Instructor;
namespace Ui {
class InstructorUI;
}

class InstructorUI : public QDialog
{
    Q_OBJECT

public:
    explicit InstructorUI(QWidget *parent = nullptr);
    ~InstructorUI();

private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_Proceed_clicked();

    void on_lineEdit_numOfPlayer_editingFinished();

    void on_pushButton_PlayerPass_clicked();

    void on_pushButton_createGame_clicked();

private:
    Ui::InstructorUI *ui;
    Instructor *instructor_instance;

    QTimer *m_typingTimer;
    QString *m_filtertext;
    //Ui::MainWindow *mainWindow;
};

#endif // INSTRUCTORUI_H

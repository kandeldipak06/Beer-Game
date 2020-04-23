#ifndef INSTRUCTORUI_H
#define INSTRUCTORUI_H

#include <QDialog>

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
    void on_lineEdit_NumberOfPlayer_editingFinished();

    void on_lineEdit_OrderDelay_editingFinished();

    void on_lineEdit_ShipmentDelay_editingFinished();

    void on_lineEdit_HoldingCost_editingFinished();

    void on_lineEdit_BackOrderCost_editingFinished();

    void on_lineEdit_StartInventory_editingFinished();

    void on_lineEdit_FactoryDelay_editingFinished();

    void on_pushButton_createGame_clicked();

    void on_pushButton_Back_clicked();

    void on_pushButton_ezit_clicked();

private:
    Ui::InstructorUI *ui;

    QTimer *m_typingTimer;
};

#endif // INSTRUCTORUI_H

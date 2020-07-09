#ifndef INSTRGAMEUI_H
#define INSTRGAMEUI_H

#include <QDialog>

namespace Ui {
class InstrGameUI;
}

class InstrGameUI : public QDialog
{
    Q_OBJECT

public:
    explicit InstrGameUI(QWidget *parent = nullptr);
    ~InstrGameUI();

private:
    Ui::InstrGameUI *ui;
};

#endif // INSTRGAMEUI_H

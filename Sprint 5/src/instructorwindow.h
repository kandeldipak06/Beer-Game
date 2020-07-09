#ifndef INSTRUCTORWINDOW_H
#define INSTRUCTORWINDOW_H

/**
  * \class InstructorWindow
  * \brief Window Screen for Instructor to login/signup and modify parameters for the game
  */

#include <QDialog>

#include "instructor.h"

class Instructor;

namespace Ui
{
class InstructorWindow;
}

class InstructorWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * \brief constructor for Instructor Window Screen
    */
    explicit InstructorWindow(QWidget *parent = nullptr);
    /**
     * \brief destructor for Instructuo Window Screen
    */
    ~InstructorWindow();
    /**
     * \brief Parent QWidget Object
    */
    QWidget *parent;

private slots:
    /**
     * \brief features to be accomplished after button click
    */
    void on_startBtn_clicked();

private:
    /**
     * \brief Instructor object
     */
    Instructor *instructor;
    /**
     * \brief Ui object
     */
    Ui::InstructorWindow *ui;
};

#endif // INSTRUCTORWINDOW_H

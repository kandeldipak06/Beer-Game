/** 
 *  \class ShowGraph
 *  \brief This is to show graph summary of the game
 */

#ifndef SHOWGRAPH_H
#define SHOWGRAPH_H

#include <QWidget>

namespace Ui {
class ShowGraph;
}

class ShowGraph : public QWidget
{
    Q_OBJECT

public:
    /**
     * \brief Constructor for ShowGraph class 
     * \param parent
     */
    explicit ShowGraph(QWidget *parent = nullptr);
    /**
     * \brief Constructor for ShowGraph class 
     */
    ~ShowGraph();

private:
    /**
     * \brief UI object for ShowGraph
     */
    Ui::ShowGraph *ui;
};

#endif // SHOWGRAPH_H
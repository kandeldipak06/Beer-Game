#include "showgraph.h"
#include "ui_showgraph.h"
#include "playerclient.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QLineSeries>
#include <QDebug>

QT_CHARTS_USE_NAMESPACE

ShowGraph::ShowGraph(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowGraph)
{
    ui->setupUi(this);
    //![1]
//        QBarSet *set0 = new QBarSet("Jane");
//        QBarSet *set1 = new QBarSet("John");
//        QBarSet *set2 = new QBarSet("Axel");
//        QBarSet *set3 = new QBarSet("Mary");
//        QBarSet *set4 = new QBarSet("Sam");

//        int barlist[] = {5,0,3,4,0,7};

//        *set1 << barlist[0] << barlist[1] << barlist[2] << barlist[3] << barlist[4] << barlist[5];
//        *set2 << 3 << 5 << 8 << 13 << 8 << 5;
//        *set3 << 5 << 6 << 7 << 3 << 4 << 5;
//        *set4 << 9 << 7 << 5 << 3 << 1 << 2;
//        *set0 << 1 << 16 << 3 << 4 << 5 << 6;

//    //![1]

//    //![2]
//        QBarSeries *barseries = new QBarSeries();
//        barseries->append(set0);
//        barseries->append(set2);
//        barseries->append(set3);
//        barseries->append(set4);
//        barseries->append(set1);
//    //![2]

    //![8]
        QLineSeries *lineseries = new QLineSeries();
        lineseries->setName("trend");
        PlayerClient *pclient = new PlayerClient();
        std::vector<int> listBeer = pclient->getBeerlist();
        qDebug() << listBeer[0];
        for(int i=0; i<listBeer.size(); i++){
            lineseries->append(QPoint(i, listBeer[i]));
        }
    //![8]

    //![3]
        QChart *chart = new QChart();
        // chart->addSeries(barseries);
        chart->addSeries(lineseries);
        chart->setTitle("Line and barchart example");
    //![3]

    //![4]
        QStringList categories;
        categories << "One" << "Two" << "Three" << "Four" << "Five" << "Six";
        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        chart->addAxis(axisX, Qt::AlignBottom);
        lineseries->attachAxis(axisX);
        // barseries->attachAxis(axisX);
        axisX->setRange(QString("One"), QString("Six"));

        QValueAxis *axisY = new QValueAxis();
        chart->addAxis(axisY, Qt::AlignLeft);
        lineseries->attachAxis(axisY);
        // barseries->attachAxis(axisY);
        axisY->setRange(0, 25);
    //![4]

    //![5]
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);
    //![5]

    //![6]
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
    //![6]
    ui->verticalLayout->addWidget(chartView);
}

ShowGraph::~ShowGraph()
{
    delete ui;
}

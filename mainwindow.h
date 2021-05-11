#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<iostream>
#include<string.h>
#include<QtCharts/QChartView>
#include<QtCharts/QBarSeries>
#include<QtCharts/QBarSet>
#include<QtCharts/QLegend>
#include<QtCharts/QBarCategoryAxis>
#include<QtCharts/QHorizontalStackedBarSeries>
#include<QtCharts/QLineSeries>
#include<QtCharts/QCategoryAxis>
#include<QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QDial>
#include<QScatterSeries>
#include<QtDebug>
#include<QLineSeries>
using namespace std;
QT_CHARTS_USE_NAMESPACE


#include <QMainWindow>

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
    void on_Select_clicked();

    void on_select_1_clicked();

    void on_select_2_clicked();

    void on_searchButton_clicked();

    //void on_comboBox_4_activated(const QString &arg1);

  //  void on_adjustKey1_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

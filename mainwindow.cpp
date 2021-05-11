#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<datastructure_to_read_data.h>
#include<Read_data_for_graph.h>

#include <QMessageBox>


Read_data_for_graph Re;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    Re.read_csv();
    Re.R.find_highest();
    Re.R.copy_country();
   // Re.R.bubble_sort();
//    cout<<Re.R.country_sorted[11].highest_totalcase<<endl;
//    cout<<Re.R.country_sorted[11].country_name<<endl;

//   cout<< Re.R.country[7].highest_totalcase<<endl;
//    cout<<Re.R.country[7].country_name<<endl;
   // cout<<"HIG  "<<  Re.R.country[12].root->total_deaths;
    for(int i=0;i<13;i++)
    {
        QString s = QString::fromStdString(Re.R.country[i].country_name);
        ui->comboBox->addItem(s);

    }

    {
        ui->world_data_combox_1->addItem("Total No of Cases");
        ui->world_data_combox_1->addItem("Total No of Deaths");
        ui->world_data_combox_1->addItem("Highest new cases in single day");
        ui->world_data_combox_1->addItem("Highest new deaths in single day");

        ui->world_data_combox_2->addItem("Total No of Deaths");
        ui->world_data_combox_2->addItem("Total No of Cases");
        ui->world_data_combox_2->addItem("Highest new cases in single day");
        ui->world_data_combox_2->addItem("Highest new deaths in single day");

    }



        QBarSet *set_bar_2=new QBarSet("Total No of Cases");
        QBarSet *set_bar_3=new QBarSet("Total No of Deaths");
        QStringList categories_2;

        for(int i=0;i<12;i++)
        {
            *set_bar_2<<Re.R.country[i].highest_totalcase;
            *set_bar_3<<Re.R.country[i].highest_totalDeath;
             QString qstr = QString::fromStdString(Re.R.country[i].country_name);
             categories_2<<qstr;

        }

        QBarSeries *series_bar_2=new QBarSeries();
        set_bar_2->setColor(QColor(255, 0, 0, 127));
      // series_bar_2->setBarWidth(0.3);
        series_bar_2->append(set_bar_2);

         QChart *chart=new QChart();
        chart->addSeries(series_bar_2);
        chart->setTitle("Covid-19 World Report");
        chart->setAnimationOptions(QChart::AllAnimations);
        QBarCategoryAxis *axis=new QBarCategoryAxis();
        axis->append(categories_2);
        chart->createDefaultAxes();
        chart->setAxisX(axis,series_bar_2);
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

       QChartView *chartView=new QChartView(chart);
      // chartView->setFixedSize(600,500);
       chartView->setRenderHint(QPainter::Antialiasing);
       chartView->setParent(ui->frame_1);




       QBarSeries *series_bar_3=new QBarSeries();
       set_bar_3->setColor(QColor(0, 0, 255, 127));
     // series_bar_2->setBarWidth(5);
       series_bar_3->append(set_bar_3);

        QChart *chart3=new QChart();
       chart3->addSeries(series_bar_3);
       chart->setTitle("Covid-19 World Report");
       chart3->setAnimationOptions(QChart::AllAnimations);
       QBarCategoryAxis *axis3=new QBarCategoryAxis();
       axis3->append(categories_2);
       chart3->createDefaultAxes();
       chart3->setAxisX(axis3,series_bar_3);
       chart3->legend()->setVisible(true);
       chart3->legend()->setAlignment(Qt::AlignBottom);

      QChartView *chartView3=new QChartView(chart3);
     // chartView->setFixedSize(600,500);
      chartView3->setRenderHint(QPainter::Antialiasing);
      chartView3->setParent(ui->frame_2);

      ui->comboBox_4->addItem("New Case");
      ui->comboBox_4->addItem("New deaths");
      ui->comboBox_4->addItem("Total deaths");
      ui->comboBox_4->addItem("Total Case");
      ui->comboBox_4->setCurrentIndex(0);

      ui->comboBox_2->addItem("Day");
      ui->comboBox_3->addItem("Month");

      for (int i=1; i<=30; i++)
      {
          ui->comboBox_2->addItem(QString::number(i));
      }
      for (int j=1; j<=12; j++)
      {
          ui->comboBox_3->addItem(QString::number(j));
      }


      cout<<"TOTAL  "<<Re.R.country[0].root->total_cases;
      cout<<"TOTAL  "<<Re.R.country[0].root->total_deaths;

      ui->text_label->hide();
      ui->comboBox_2->hide();
      ui->comboBox_3->hide();
      ui->searchButton->hide();



}

MainWindow::~MainWindow()
{
    delete ui;
}

//void traverse_tree(read::Node* node,QLineSeries *line_series,QScatterSeries *scatter_series)
//{

//      if (node == NULL)
//            return;

//      traverse_tree(node->left,line_series,scatter_series);

//         line_series->append(node->key, node->new_cases);
//         scatter_series->append(node->key,node->new_cases);


//      traverse_tree(node->right,line_series,scatter_series);
//}


//void MainWindow::on_Select_clicked()
//{

//        QLineSeries *line_series1 = new QLineSeries();
//        QLineSeries *line_series2 = new QLineSeries();
//        line_series2->setColor(QColor(255, 0, 0, 127));


//      QScatterSeries* scatter_series = new QScatterSeries();
//      QScatterSeries* scatter_series_2 = new QScatterSeries();

//      scatter_series->setBorderColor(QColor(255, 0, 0, 127));
//     scatter_series->setColor(QColor(255, 0, 0, 127));


//      scatter_series->setMarkerSize(7.0);

//        traverse_tree(Re.R.country[ui->comboBox->currentIndex()].root,line_series1,scatter_series);
//        if(ui->check_box->isChecked())
//        traverse_tree(Re.R.country[7].root,line_series2,scatter_series_2);


//        QChart *line_chart1 = new QChart();
//         line_chart1->legend()->hide();
//         line_chart1->addSeries(line_series1);
//         line_chart1->addSeries(line_series2);

//         line_chart1->createDefaultAxes();
//         line_chart1->setTitle("Covid data");


//         QChart *scatter_chart1 = new QChart();

//         // scatter_chart1->legend()->hide();
//          scatter_chart1->addSeries(scatter_series);
//         scatter_chart1->createDefaultAxes();
//          scatter_chart1->setTitle("Covid data");

//         QChartView *line_chartView1 = new QChartView(line_chart1);
//         line_chartView1->setRenderHint(QPainter::Antialiasing);
//         line_chartView1->setParent(ui->frame_1);
//         line_chartView1->show();

//         QChartView *scatter_chartView1 = new QChartView(scatter_chart1);
//         scatter_chartView1->setRenderHint(QPainter::Antialiasing);
//         scatter_chartView1->setParent(ui->frame_2);
//         scatter_chartView1->show();


//}


void traverse_tree(read::Node* node,QLineSeries *line_series,QScatterSeries *scatter_series, int axisKey)
{

      if (node == NULL)
            return;


//      switch (axisKey) {
//      case 1:
//                traverse_tree(node->left,line_series,scatter_series, 1);

//                line_series->append(node->key, node->new_cases);
//                scatter_series->append(node->key,node->new_cases);


//                traverse_tree(node->right,line_series,scatter_series, 1);

//      case 2:
//                traverse_tree(node->left,line_series,scatter_series, 2);

//                line_series->append(node->key, node->new_deaths);
//                scatter_series->append(node->key,node->new_deaths);


//                traverse_tree(node->right,line_series,scatter_series, 2);

//      case 3:
//                traverse_tree(node->left,line_series,scatter_series, 3);

//                line_series->append(node->key, node->total_deaths);
//                scatter_series->append(node->key, node->total_deaths);


//                traverse_tree(node->right,line_series,scatter_series, 3);

//      case 4:
//                traverse_tree(node->left,line_series,scatter_series, 4);

//                line_series->append(node->key, node->total_cases);
//                scatter_series->append(node->key,node->total_cases);


//                traverse_tree(node->right,line_series,scatter_series, 4);
//      }


      /// Draw the graphs based on the nation and axis-value
      if (axisKey==0){

        traverse_tree(node->left,line_series,scatter_series, 0);

        line_series->append(node->key, node->new_cases);
        scatter_series->append(node->key,node->new_cases);


        traverse_tree(node->right,line_series,scatter_series, 0);
      }

      if (axisKey==1){
          traverse_tree(node->left,line_series,scatter_series, 1);

          line_series->append(node->key, node->new_deaths);
          scatter_series->append(node->key,node->new_deaths);


          traverse_tree(node->right,line_series,scatter_series, 1);
      }

      if (axisKey==2){
          traverse_tree(node->left,line_series,scatter_series, 2);

          line_series->append(node->key, node->total_deaths);
          scatter_series->append(node->key, node->total_deaths);


          traverse_tree(node->right,line_series,scatter_series, 2);
      }

      if (axisKey==3){
          traverse_tree(node->left,line_series,scatter_series, 3);

          line_series->append(node->key, node->total_cases);
          scatter_series->append(node->key,node->total_cases);


          traverse_tree(node->right,line_series,scatter_series, 3);
      }
}


void MainWindow::on_Select_clicked()
{

        QLineSeries *line_series1 = new QLineSeries();
        QScatterSeries* scatter_series = new QScatterSeries();


        QLineSeries *line_series2 = new QLineSeries();
        QScatterSeries* scatter_series_2 = new QScatterSeries();
        scatter_series->setBorderColor(QColor(0, 0, 0, 127));
        line_series2->setColor(QColor(255, 0, 0, 127));
        scatter_series_2->setBorderColor(QColor(0, 0, 0, 127));
        scatter_series_2->setColor(QColor(255, 0, 0, 127));



    //  scatter_series->setColor(QColor(255, 0, 0, 127));


        scatter_series->setMarkerSize(7.0);
        scatter_series_2->setMarkerSize(7.0);


        traverse_tree(Re.R.country[ui->comboBox->currentIndex()].root,line_series1,scatter_series, ui->comboBox_4->currentIndex());
        if(ui->check_box->isChecked())
        traverse_tree(Re.R.country[7].root,line_series2,scatter_series_2,ui->comboBox_4->currentIndex());

        QChart *line_chart1 = new QChart();
         line_chart1->legend()->hide();
         line_chart1->addSeries(line_series1);
         line_chart1->addSeries(line_series2);
         line_chart1->createDefaultAxes();
       //  line_chart1->setTitle("Covid data");



         QChart *scatter_chart1 = new QChart();

         // scatter_chart1->legend()->hide();
         scatter_series->setName(ui->comboBox->currentText());
          scatter_chart1->addSeries(scatter_series);
          scatter_series_2->setName("Nepal");
          if(ui->check_box->isChecked())
          scatter_chart1->addSeries(scatter_series_2);


         scatter_chart1->createDefaultAxes();
        //  scatter_chart1->setTitle("Covid data");

         QChartView *line_chartView1 = new QChartView(line_chart1);
         line_chartView1->setRenderHint(QPainter::Antialiasing);
         line_chartView1->setParent(ui->frame_1);
         line_chartView1->show();

         QChartView *scatter_chartView1 = new QChartView(scatter_chart1);
         scatter_chartView1->setRenderHint(QPainter::Antialiasing);
         scatter_chartView1->setParent(ui->frame_2);
         scatter_chartView1->show();
         ui->world_data_combox_1->hide();
         ui->world_data_combox_2->hide();
         ui->sort_1->hide();
         ui->sort_2->hide();
         ui->select_1->hide();
         ui->select_2->hide();

         ui->comboBox_2->show();
         ui->comboBox_3->show();
         ui->searchButton->show();




}
void getSearchText(string day_char, string month_char)
{
    //read::Node* root;
    int day = std::stoi( day_char );
    int month = std::stoi( month_char );
    //Re.R.search_by_date(Re.R.country[ui->comboBox->currentIndex()].root, day, month);
}

void MainWindow::on_searchButton_clicked()
{
   // QMessageBox::information(this, "title", ui->comboBox_2->currentText(), ui->comboBox_3->currentText());

    std::string str = ui->comboBox_2->currentText().toStdString();
    std::string str1 = ui->comboBox_3->currentText().toStdString();
    int day = std::stoi( str );
    int month = std::stoi( str1 );


    read::Node* display_node= Re.R.search_by_date(Re.R.country[ui->comboBox->currentIndex()].root, day, month);

    QString temp_new_case = QString::number(display_node->new_cases);
    QString temp_new_deaths = QString::number(display_node->new_deaths);
    QString temp_total_case = QString::number(display_node->total_cases);
    QString temp_total_death = QString::number(display_node->total_deaths);


    QString *labelText =new QString();
    labelText->append( "<P><b>");
    labelText ->append("New Case :");
    labelText ->append(temp_new_case);
    labelText->append("<br>");
    labelText ->append("New Deaths :");
    labelText ->append(temp_new_deaths);
    labelText->append("<br>");
    labelText ->append("Total Case :");
    labelText ->append(temp_total_case);
    labelText->append("<br>");
    labelText ->append("Total Deaths :");
    labelText ->append(temp_total_death);
    labelText->append("<br>");
    labelText ->append("</b></P></br>");
    //QLabel label->setText(labelText);

    ui->text_label->setText(*labelText);
    ui->text_label->show();

    //getSearchText(str, str1);
}

//void MainWindow::getSearchText(read::Node* node, ui->comboBox_2->currentText(), ui->comboBox_3->currentText());





//void MainWindow::on_adjustKey1_clicked()
//{
//    QLineSeries *line_series2 = new QLineSeries();
//    QScatterSeries* scatter_series2 = new QScatterSeries();
//    scatter_series2->setBorderColor(QColor(255, 0, 0, 127));
////  scatter_series->setColor(QColor(255, 0, 0, 127));


//    scatter_series2->setMarkerSize(7.0);

//    traverse_tree(Re.R.country[ui->comboBox->currentIndex()].root,line_series2,scatter_series2, (ui->comboBox_4->currentIndex()));
//    QChart *line_chart2 = new QChart();
//     line_chart2->legend()->hide();
//     line_chart2->addSeries(line_series2);
//     line_chart2->createDefaultAxes();
//     line_chart2->setTitle("Covid data");


//     QChart *scatter_chart2 = new QChart();

//     // scatter_chart1->legend()->hide();
//      scatter_chart2->addSeries(scatter_series2);
//     scatter_chart2->createDefaultAxes();
//      scatter_chart2->setTitle("Covid data");

//     QChartView *line_chartView2 = new QChartView(line_chart2);
//     line_chartView2->setRenderHint(QPainter::Antialiasing);
//     line_chartView2->setParent(ui->frame_1);
//     line_chartView2->show();

//     QChartView *scatter_chartView2 = new QChartView(scatter_chart2);
//     scatter_chartView2->setRenderHint(QPainter::Antialiasing);
//     scatter_chartView2->setParent(ui->frame_2);
//     scatter_chartView2->show();
//}

void MainWindow::on_select_1_clicked()
{
    int index=ui->world_data_combox_1->currentIndex();
    QBarSet *set_bar_2=new QBarSet("Total No of Cases");
    QBarSet *set_bar_3=new QBarSet("Total No of Deaths");
    QStringList categories_2;

    cout<<"Index " <<index;

    if(ui->sort_1->isChecked())

    {
        switch (index) {
    case 0:

            Re.R.sort_country_by_total_case();

        for(int i=0;i<12;i++)
        {
            *set_bar_2<<Re.R.country_sorted[i].highest_totalcase;
             QString qstr = QString::fromStdString(Re.R.country_sorted[i].country_name);
             categories_2<<qstr;
             set_bar_2->setLabel("Total Case");

        }
        break;
    case 1:
            Re.R.sort_country_by_total_death();

        for(int i=0;i<12;i++)
        {
            *set_bar_2<<Re.R.country_sorted[i].highest_totalDeath;
             QString qstr = QString::fromStdString(Re.R.country_sorted[i].country_name);
             categories_2<<qstr;
             set_bar_2->setLabel("Total Deaths");

        }
        break;
    case 2:

            Re.R.sort_country_by_highest_newCase();

        for(int i=0;i<12;i++)
        {

            *set_bar_2<<Re.R.country_sorted[i].highest_newcases;
             QString qstr = QString::fromStdString(Re.R.country_sorted[i].country_name);
             categories_2<<qstr;
             set_bar_2->setLabel("Highest New Cases");

        }
        break;
    case 3:

            Re.R.sort_country_by_highest_newDeath();

        for(int i=0;i<12;i++)
        {

            *set_bar_2<<Re.R.country_sorted[i].highest_newdeaths;
             QString qstr = QString::fromStdString(Re.R.country_sorted[i].country_name);
             categories_2<<qstr;
             set_bar_2->setLabel("Highest New Deaths");

        }
        break;

}
    }
    else
    {
        switch (index) {
        case 0:


            for(int i=0;i<12;i++)
            {
                *set_bar_2<<Re.R.country[i].highest_totalcase;
                 QString qstr = QString::fromStdString(Re.R.country[i].country_name);
                 categories_2<<qstr;
                 set_bar_2->setLabel("Total Case");

            }
            break;
        case 1:
            for(int i=0;i<12;i++)
            {
                *set_bar_2<<Re.R.country[i].highest_totalDeath;
                 QString qstr = QString::fromStdString(Re.R.country[i].country_name);
                 categories_2<<qstr;
                 set_bar_2->setLabel("Total Deaths");

            }
            break;
        case 2:

            for(int i=0;i<12;i++)
            {
                *set_bar_2<<Re.R.country[i].highest_newcases;
                 QString qstr = QString::fromStdString(Re.R.country[i].country_name);
                 categories_2<<qstr;
                 set_bar_2->setLabel("Highest New Cases");

            }
            break;
        case 3:

            for(int i=0;i<12;i++)
            {
                *set_bar_2<<Re.R.country[i].highest_newdeaths;
                 QString qstr = QString::fromStdString(Re.R.country[i].country_name);
                 categories_2<<qstr;
                 set_bar_2->setLabel("Highest New Deaths");

            }
            break;


        }
    }

    QBarSeries *series_bar_2=new QBarSeries();
    set_bar_2->setColor(QColor(255, 0, 0, 127));
    series_bar_2->append(set_bar_2);

     QChart *chart=new QChart();
    chart->addSeries(series_bar_2);
    chart->setTitle("Covid-19 World Report");
    chart->setAnimationOptions(QChart::AllAnimations);
    QBarCategoryAxis *axis=new QBarCategoryAxis();
    axis->append(categories_2);
    chart->createDefaultAxes();
    chart->setAxisX(axis,series_bar_2);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
   QChartView *chartView=new QChartView(chart);
  // chartView->setFixedSize(600,500);
   chartView->setRenderHint(QPainter::Antialiasing);
   chartView->setParent(ui->frame_1);
   chartView->show();



}

void MainWindow::on_select_2_clicked()
{

    int index=ui->world_data_combox_2->currentIndex();
    QBarSet *set_bar_2=new QBarSet("Total No of Deaths");
    QStringList categories_2;

    cout<<"Index " <<index;


    if(ui->sort_2->isChecked())

    {
        switch (index) {
    case 1:

        Re.R.sort_country_by_total_case();
        for(int i=0;i<12;i++)
        {
            *set_bar_2<<Re.R.country_sorted[i].highest_totalcase;
             QString qstr = QString::fromStdString(Re.R.country_sorted[i].country_name);
             categories_2<<qstr;
             set_bar_2->setLabel("Total Case");

        }
        break;
    case 0:
            Re.R.sort_country_by_total_death();

        for(int i=0;i<12;i++)
        {
            *set_bar_2<<Re.R.country_sorted[i].highest_totalDeath;
             QString qstr = QString::fromStdString(Re.R.country_sorted[i].country_name);
             categories_2<<qstr;
             set_bar_2->setLabel("Total Deaths");

        }
        break;
    case 2:
            Re.R.sort_country_by_highest_newCase();

        for(int i=0;i<12;i++)
        {
            *set_bar_2<<Re.R.country_sorted[i].highest_newcases;
             QString qstr = QString::fromStdString(Re.R.country_sorted[i].country_name);
             categories_2<<qstr;
             set_bar_2->setLabel("Highest New Cases");

        }
        break;
    case 3:
            Re.R.sort_country_by_highest_newDeath();

        for(int i=0;i<12;i++)
        {
            *set_bar_2<<Re.R.country_sorted[i].highest_newdeaths;
             QString qstr = QString::fromStdString(Re.R.country_sorted[i].country_name);
             categories_2<<qstr;
             set_bar_2->setLabel("Highest New Deaths");

        }
        break;

}
    }


    else {
        switch (index) {
        case 1:


            for(int i=0;i<12;i++)
            {
                *set_bar_2<<Re.R.country[i].highest_totalcase;
                 QString qstr = QString::fromStdString(Re.R.country[i].country_name);
                 categories_2<<qstr;
                 set_bar_2->setLabel("Total Case");

            }
            break;
        case 0:
            for(int i=0;i<12;i++)
            {
                *set_bar_2<<Re.R.country[i].highest_totalDeath;
                 QString qstr = QString::fromStdString(Re.R.country[i].country_name);
                 categories_2<<qstr;
                 set_bar_2->setLabel("Total Deaths");

            }
            break;
        case 2:

            for(int i=0;i<12;i++)
            {
                *set_bar_2<<Re.R.country[i].highest_newcases;
                 QString qstr = QString::fromStdString(Re.R.country[i].country_name);
                 categories_2<<qstr;
                 set_bar_2->setLabel("Highest New Cases");

            }
            break;
        case 3:

            for(int i=0;i<12;i++)
            {
                *set_bar_2<<Re.R.country[i].highest_newdeaths;
                 QString qstr = QString::fromStdString(Re.R.country[i].country_name);
                 categories_2<<qstr;
                 set_bar_2->setLabel("Highest New Deaths");

            }
            break;


        }
    }

    QBarSeries *series_bar_2=new QBarSeries();
    set_bar_2->setColor(QColor(0, 0, 255, 127));
    series_bar_2->append(set_bar_2);

     QChart *chart=new QChart();
    chart->addSeries(series_bar_2);
    chart->setTitle("Covid-19 World Report");
    chart->setAnimationOptions(QChart::AllAnimations);
    QBarCategoryAxis *axis=new QBarCategoryAxis();
    axis->append(categories_2);
    chart->createDefaultAxes();
    chart->setAxisX(axis,series_bar_2);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
   QChartView *chartView=new QChartView(chart);
  // chartView->setFixedSize(600,500);
   chartView->setRenderHint(QPainter::Antialiasing);
   chartView->setParent(ui->frame_2);
   chartView->show();

}

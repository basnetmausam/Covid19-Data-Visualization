
#include "datastructure_to_read_data.h"    //Importing our linked list to store data from csv
#include <fstream>                         //To read data from file
#include <string>                          //to manipulate string in our case for conversion from string to float
#include "iostream"

using namespace std;

class Read_data_for_graph {
public:
    read R;

    void read_csv();
};

void Read_data_for_graph::read_csv() {

      ifstream ip("E:\\IOE PULCHOWK\\@DataStructureProject\\DSA--075BCT (049, 051, 053)\\Covid19 Data Visualization\\covid_dataset_copy.csv");
      if (!ip.is_open()) {
            cout << "Error in Opening file" << endl;

      }

      string loc;
      string y, m, d;
      string tc, nc, td, nd,si,hdi;


      while (ip.good()) {
            getline(ip, loc, ',');
            getline(ip, m, '/');
            getline(ip, d, '/');
            getline(ip, y, ',');
            getline(ip, tc, ',');
            getline(ip, nc, ',');
            getline(ip, td, ',');
            getline(ip, nd, ',');
            getline(ip, si, ',');
            getline(ip, hdi, '\n');

            try {

                  float y1 = std::stof(y);
                  float m1 = std::stof(m);
                  float d1 = std::stof(d);
                  float tc1 = std::stof(tc);
                  float nc1 = std::stof(nc);
                  float td1 = std::stof(td);
                  float nd1 = std::stof(nd);
                  float si1 = std::stof(si);
                  float hdi1 = std::stof(hdi);
                  string loc1=loc;

                  if(loc1=="Australia")
                  {
                        R.read_data(loc1,0,y1, m1, d1, tc1, nc1, td1, nd1,si1);
                  }

                 if(loc1=="Bhutan")
                  {
                        R.read_data(loc1,1,y1, m1, d1, tc1, nc1, td1, nd1,si1);
                  }
                 if(loc1=="Brazil")
                 {
                       R.read_data(loc1,2,y1, m1, d1, tc1, nc1, td1, nd1,si1);
                 }
                  if(loc1=="Canada")
                  {
                        R.read_data(loc1,3,y1, m1, d1, tc1, nc1, td1, nd1,si1);
                  }
                  if(loc1=="France")
                  {
                        R.read_data(loc1,4,y1, m1, d1, tc1, nc1, td1, nd1,si1);
                  }
                  if(loc1=="India")
                  {
                        R.read_data(loc1,5,y1, m1, d1, tc1, nc1, td1, nd1,si1);
                  }
                  if(loc1=="Japan")
                  {
                        R.read_data(loc1,6,y1, m1, d1, tc1, nc1, td1, nd1,si1);
                  }
                  if(loc1=="Nepal")
                  {
                        R.read_data(loc1,7,y1, m1, d1, tc1, nc1, td1, nd1,si1);
                  }
                  if(loc1=="New Zealand")
                  {
                        R.read_data(loc1,8,y1, m1, d1, tc1, nc1, td1, nd1,si1);
                  }
                  if(loc1=="South Korea")
                  {
                        R.read_data(loc1,9,y1, m1, d1, tc1, nc1, td1, nd1,si1);
                  }
                  if(loc1=="United Kingdom")
                  {
                        R.read_data(loc1,10,y1, m1, d1, tc1, nc1, td1, nd1,si1);
                  }
                  if(loc1=="United States")
                  {
                        R.read_data(loc1,11,y1, m1, d1, tc1, nc1, td1, nd1,si1);
                  }
                  if(loc1=="World")
                  {
                        R.read_data(loc1,12,y1, m1, d1, tc1, nc1, td1, nd1,si1);
                  }





            } catch (invalid_argument e) {
                  cout << "\n Invalid argument " << y << "\t" << m << "\t" << d << endl;

            };

      }
}


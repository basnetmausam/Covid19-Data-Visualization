//#include "Read_data_for_graph.h"
//#include <SFML/Graphics.hpp>
//#include "select_button.h"
//#include <math.h>

//class test_class
//{
//public:
//    int X11[310];
//    int Y11[310];
//    int X11T[310];
//    int Y11T[310];
//    int X21T[310];
//    int Y21T[310];

//    sf::Image test_graph;
//    sf::Texture test_texture;
//    sf::Sprite test_sprite;

//    sf::Image test_graph2;
//    sf::Texture test_texture2;
//    sf::Sprite test_sprite2;

//    sf::Image test_graph3;
//    sf::Texture test_texture3;
//    sf::Sprite test_sprite3;
////    sf::Image img_graph;
////    sf::Texture img_texture;
////    sf::Sprite img_sprite;


//    void drawcircle(int x, int y, int r, sf::Image &graph,sf::Color co) {
//          static const double PI = 3.1415926535;
//          double i, angle, x1, y1;
//          for (int j = 1; j < r; j++) {
//                for (i = 0; i < 360; i += 0.1) {
//                      angle = i;
//                      x1 = j * cos(angle * PI / 180);
//                      y1 = j * sin(angle * PI / 180);
//                      graph.setPixel(x + x1, y + y1,co);
//                }

//          }

//    }
//    void traverse_tree(read::Node* node)
//    {
//          if (node == NULL)
//                return;

//          /* first recur on left child */
//          traverse_tree(node->left);

//          /* then print the data of node */

//          Y11[node->key] = (node->new_cases/20);
//                Y11T[node->key]= (node->total_cases / 10000000);
//                Y21T[node->key]= (node->new_deaths/100000);

////                if (re.R.country[index].temp->month == 1)
//                      X11[node->key] = node->key;
////                else {
////                      X11[i] = ((re.R.country[index].temp->month * 30) + re.R.country[index].temp->day);
////
////                }
//                X11T[node->key]=node->total_deaths/1000000;


//          drawcircle(X11[node->key] + 20, Y11[node->key] + 20, 5,test_graph , sf::Color::Blue);
//          drawcircle(X11T[node->key] + 20, Y11T[node->key] + 20, 3,test_graph2 , sf::Color::Red);
//          drawcircle(X11[node->key] + 20, Y21T[node->key] + 20, 3,test_graph3 , sf::Color::Green);

//              //  cout << X11[index] << "\t " << X11[index] << endl;





//          /* now recur on right child */
//          traverse_tree(node->right);
//    }


//    void test_store(read::Node* node)
//    {
//         // int i = 0;
//         // re.R.bubbleSort(&re.R.country[index].node_start,re.R.country[0].count_node);

//          //int scale=int (re.R.country[index].node_start->new_cases);
//          //cout<<scale;
////          int scale=1000;
////          cout<<"Scale "<<scale;

//          test_graph.create(500, 500, sf::Color(255, 255, 255));
//          test_graph2.create(500, 500, sf::Color(255, 255, 255));
//          test_graph3.create(500, 400, sf::Color(255, 255, 255));

//          traverse_tree(node);

//          //re.R.country[index].temp=re.R.country[index].root;





////          while (re.R.country[index].temp-> != NULL) {
////               // cout<<re.R.country[index].temp->new_cases<<endl;
////
////                Y11[i] = (re.R.country[index].temp->new_cases/(scale+5) );
////                Y11T[i]= (re.R.country[index].temp->total_cases / 10000000);
////                Y21T[i]= (re.R.country[index].temp->new_deaths/100000);
////
////                if (re.R.country[index].temp->month == 1)
////                      X11[i] = re.R.country[index].temp->day;
////                else {
////                      X11[i] = ((re.R.country[index].temp->month * 30) + re.R.country[index].temp->day);
////
////                }
////                X11T[i]=re.R.country[index].temp->total_deaths/1000000;
////
////              //  cout << X11[index] << "\t " << X11[index] << endl;
////                re.R.country[index].temp = re.R.country[index].temp->next;
////                i++;
////          }


//        //  img_graph.create(500, 400, sf::Color(255, 255, 255));
//       //   img_graph.loadFromFile("graph_img.jpg");




////          for ( int j = 0; j < 300; j++) {
////
////                drawcircle(X11[j] + 20, Y11[j] + 20, 5,test_graph , sf::Color::Blue);
////                drawcircle(X11T[j] + 20, Y11T[j] + 20, 3,test_graph2 , sf::Color::Red);
////                drawcircle(X11[j] + 20, Y21T[j] + 20, 3,test_graph3 , sf::Color::Green);
////
////
////
////          }

//          test_graph.flipVertically();
//          test_texture.loadFromImage(test_graph);
//          test_sprite.setTexture(test_texture, true);
//          test_sprite.setPosition(550,0);

//          test_graph2.flipVertically();
//          test_texture2.loadFromImage(test_graph2);
//          test_sprite2.setTexture(test_texture2, true);
//          test_sprite2.setPosition(20,0);

//          test_graph3.flipVertically();
//          test_texture3.loadFromImage(test_graph3);
//          test_sprite3.setTexture(test_texture3, true);
//          test_sprite3.setPosition(0,510);


////          img_texture.loadFromFile("graph_image.png");
////          img_sprite.setTexture(img_texture, true);
////          img_sprite.setPosition(500,510);


//    }
//    void draw(sf::RenderWindow &window)
//    {
//         // window.clear();
////          window.draw(img_sprite);

//          window.draw(test_sprite);
//          window.draw(test_sprite2);
//          window.draw(test_sprite3);


//          window.display();
//    }
//};



//int x[350];
//int y[350];
//int x11[350];
//int y11[350];
//int x21[350];
//int y21[350];
//int x31[350];
//int y31[350];
//bool nepal_draw= false;
//void drawcircle(int x, int y, int r, sf::Image &graph,sf::Color co) {
//      static const double PI = 3.1415926535;
//      double i, angle, x1, y1;
//      for (int j = 1; j < r; j++) {
//            for (i = 0; i < 360; i += 0.1) {
//                  angle = i;
//                  x1 = j * cos(angle * PI / 180);
//                  y1 = j * sin(angle * PI / 180);
//                  graph.setPixel(x + x1, y + y1,co);
//            }

//      }

//}


//void store(Read_data_for_graph re) {
//     int i =50;
//for(int j=0;j<5;j++)
//{
//      cout<<"TOTAL " <<re.R.country[j].country_name<<"   "<<re.R.country[j].node->total_cases<<endl;
//      y[j]=re.R.country[j].node->total_cases/1000;
//      x[j]=i;
//      i=i+50;


//}

//}
////
////void test_store(Read_data_for_graph re,int index,sf::RenderWindow &window)
////{
////    //  re.R.bubbleSort()
////      int i = 0;
////      while (re.R.country[index].temp->next != NULL) {
////
////            y11[i] = (re.R.country[index].temp->new_cases / 20);
//////            if (re.R.country[index].temp->month == 1)
//////                  x11[i] = re.R.country[index].temp->day;
////           // else
////           {
////                  x11[i] = (((re.R.country[index].temp->month-1) * 30) + re.R.country[index].temp->day);
////
////            }
////
////            cout << x11[index] << "\t " << y11[index] << endl;
////            re.R.country[index].temp = re.R.country[index].temp->next;
////            i++;
////      }
////
////      sf::Image test_graph;
////      test_graph.create(500, 500, sf::Color(255, 255, 255));
////      for ( int j = 0; j < i; j++) {
////
////
////                  drawcircle(x11[j] + 20, y11[j] + 20, 3,test_graph , sf::Color::Blue);
////            }
////
////      test_graph.flipVertically();
////      sf::Texture test_texture;
////      test_texture.loadFromImage(test_graph);
////      sf::Sprite test_sprite;
////      test_sprite.setTexture(test_texture, true);
////      test_sprite.setPosition(550,0);
////
////      window.clear();
////      window.draw(test_sprite);
////      window.display();
////}


////void store_1(Read_data_for_graph re) {
////      int i = 0;
////
////      while (re.R.country[4].temp->next != NULL) {
////
////            y11[i] = (re.R.country[4].temp->new_cases / 20);
////            if (re.R.country[4].temp->month == 1)
////                  x11[i] = re.R.country[4].temp->day;
////            else {
////                  x11[i] = ((re.R.country[4].temp->month * 30) + re.R.country[4].temp->day);
////
////            }
////
////            cout << x11[i] << "\t " << y11[i] << endl;
////            re.R.country[4].temp = re.R.country[4].temp->next;
////            i++;
////      }
////i=0;
////      while (re.R.country[3].temp->next != NULL) {
////
////            y21[i] = (re.R.country[3].temp->new_cases / 20);
////            if (re.R.country[3].temp->month == 1)
////                  x21[i] = re.R.country[3].temp->day;
////            else {
////                  x21[i] = ((re.R.country[3].temp->month * 30) + re.R.country[3].temp->day);
////
////            }
////
////            cout << x21[i] << "\t " << y21[i] << endl;
////            re.R.country[3].temp = re.R.country[3].temp->next;
////            i++;
////      }
////      i=0;
////      while (re.R.country[0].temp->next != NULL) {
////
////            y31[i] = (re.R.country[0].temp->new_cases / 20);
////            if (re.R.country[0].temp->month == 1)
////                  x31[i] = re.R.country[0].temp->day;
////            else {
////                  x31[i] = ((re.R.country[0].temp->month * 30) + re.R.country[0].temp->day);
////
////            }
////
////            cout << x31[i] << "\t " << y31[i] << endl;
////            re.R.country[0].temp = re.R.country[0].temp->next;
////            i++;
////      }
////
////
////
////}


//int main()
//{

//      test_class Tc;
//      int country_selection=4;
//      Selection_button buttons;
//      Read_data_for_graph Re;
//      Re.read_csv();
////      store(Re);
////      store_1(Re);

//     // Re.R.display();




//      sf::Vector2f resolution;
//      resolution.x = sf::VideoMode::getDesktopMode().width;
//      resolution.y = sf::VideoMode::getDesktopMode().height;
//      sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y), "Graph", sf::Style::Resize);
//      sf::Image graph;
//      sf::Image scatter_graph;
//      graph.create(500, 500, sf::Color(255, 255, 255));
//      scatter_graph.create(500, 500, sf::Color(255, 255, 255));


////      for ( int i = 0; i < 5; i++) {
////
////                  drawcircle(x[i] + 20, y[i] + 20, 5, graph,sf::Color::Red);
////
////      }
////
////
////      for ( int j = 0; j < 300; j++) {
////
////
////            drawcircle(x11[j] + 20, y11[j] + 20, 3, scatter_graph, sf::Color::Blue);
////
////            drawcircle(x21[j] + 20, y21[j] + 20, 3, scatter_graph, sf::Color::Green);
////            drawcircle(x31[j] + 20, y31[j] + 20, 3, scatter_graph, sf::Color::Black);
////      }






//      graph.flipVertically();
//      scatter_graph.flipVertically();
//      sf::Texture texture;
//      sf::Texture scatter_texture;
//      texture.loadFromImage(graph);
//      scatter_texture.loadFromImage(scatter_graph);
//      sf::Sprite sprite;
//      sf::Sprite scatter_sprite;
//      sprite.setTexture(texture, true);
//      scatter_sprite.setTexture(scatter_texture, true);
//      scatter_sprite.setPosition(550,0);

//      buttons.create_buttons();

////       cout<<Re.R.country[7].temp->new_cases<<endl;
////for(int sort_index=0;sort_index<13;sort_index++) {
////      Re.R.bubbleSort(&Re.R.country[sort_index].node_start, Re.R.country[sort_index].count_node);
////  //    Re.R.bubbleSort(&Re.R.country[7].node_start, Re.R.country[7].count_node);
////}
////      cout<<Re.R.country[7].temp->new_cases<<endl;

//// Re.R.display();
////   //  cout<<" NEW CASE"<< Re.R.country[7].node_start->new_cases;
//    //Re.R.printList(Re.R.country[7].node_start);



//      Tc.test_store(Re.R.country[7].root);


//int search_month,search_day=0;
//int key=20;



//      while (window.isOpen()) {
//            sf::Event event;
//            while (window.pollEvent(event)) {
//                  if (event.type == sf::Event::Closed)
//                        window.close();
//                  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
//                        window.close();
//                  }


//                  if (event.mouseButton.x >= buttons.pos_x && event.mouseButton.x <= buttons.pos_x+145){
//                        if (event.mouseButton.y >= 5  &&  event.mouseButton.y <40){

//                              cout<<"Australia"<<"\n\n";
//                              Tc.test_store(Re.R.country[0].root);
////                              cout<<"\n To get detailed data from particular date please enter date"<<endl;
////                              cout<<" Enter month"<<endl;
////                              cin>>search_month;
////                              cout<<"\n Enter day"<<endl;
////                              cin>>search_day;
////                              if(search_month && search_day !=0)
////                              {
////                                    key=0;
////                                    break;
////
////                              }
//                            //  Re.R.search_date(Re.R.country[0].node_start,13,9);

//                        }
//                        else if(event.mouseButton.y >= 40  &&  event.mouseButton.y < 75){
//                              cout<<"Bhutan"<<"\n\n";
//                              Tc.test_store(Re.R.country[1].root);

//                        }
//                        else if(event.mouseButton.y >= 75  &&  event.mouseButton.y < 110){
//                              cout<<"Brazil"<<"\n\n";
//                              //Tc.test_store(Re.R.country[2].root);

//                        }
//                        else if(event.mouseButton.y >= 110  &&  event.mouseButton.y < 145){
//                              cout<<"Canada"<<"\n\n";
//                             //Tc.test_store(Re.R.country[3].root);
//                        }
//                        else if(event.mouseButton.y >= 145  &&  event.mouseButton.y < 180){
//                              cout<<"France"<<"\n\n";
//                              //Tc.test_store(Re.R.country[4].root);
//                        }
//                        if (event.mouseButton.y >= 180  &&  event.mouseButton.y <215){
//                              cout<<"India"<<"\n\n";
//                              Tc.test_store(Re.R.country[5].root);

//                        }
//                        else if(event.mouseButton.y >= 215  &&  event.mouseButton.y < 250){
//                              cout<<"Japan"<<"\n\n";
//                              Tc.test_store(Re.R.country[6].root);

//                        }
//                        else if(event.mouseButton.y >= 250  &&  event.mouseButton.y < 285){
//                              cout<<"Nepal"<<"\n\n";
//                              Tc.test_store(Re.R.country[7].root);

//                        }
//                        else if(event.mouseButton.y >= 285  &&  event.mouseButton.y < 320){
//                              cout<<"New Zealand"<<"\n\n";
//                              Tc.test_store(Re.R.country[8].root);
//                        }
//                        else if(event.mouseButton.y >= 320  &&  event.mouseButton.y < 355){
//                              cout<<"S Korea"<<"\n\n";
//                              //Tc.test_store(Re.R.country[9].root);
//                        }
//                        else if(event.mouseButton.y >= 355 &&  event.mouseButton.y < 390){
//                              cout<<"UK"<<"\n\n";
//                              Tc.test_store(Re.R.country[10].root);

//                        }
//                        else if(event.mouseButton.y >= 390  &&  event.mouseButton.y < 425){
//                              cout<<"USA"<<"\n\n";
//                              Tc.test_store(Re.R.country[11].root);
//                        }
//                        else if(event.mouseButton.y >= 425 &&  event.mouseButton.y < 460){
//                              cout<<"World"<<"\n\n";
//                              //Tc.test_store(Re.R.country[12].root);
//                        }
//                  }
//            }



//            window.clear();
//           buttons.draw_bttons(window);
////            window.draw(textbox);
////            window.draw(textEntered);
//            Tc.draw(window);
//            // window.draw(sprite);
//         //  window.draw(scatter_sprite);
//            window.display();
////            if(key!=20)
////            {
////                  Re.R.search_date(Re.R.country[key].node_start,search_day,search_month);
////                  search_day=0;
////                  search_month=0;
////                  key=20;
////
////            }

//      }

//      return 0;

//}


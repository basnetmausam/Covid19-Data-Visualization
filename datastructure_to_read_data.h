
#ifndef DATASTRUCTUREPROJECT_DATASTRUCTURE_TO_READ_DATA_H
#define DATASTRUCTUREPROJECT_DATASTRUCTURE_TO_READ_DATA_H
#include "string.h"
#include"iostream"
#define COUNT 5
using namespace std;
class read                     //class to store data in Nodes same as in singly linked list
{

public:
    struct Node              //Node that stores data of individual days  data in single node
    {

        int key;
        float year, month, day;
        float total_cases, new_cases, total_deaths, new_deaths,si;
        Node * left;
        Node * right;
        int height;

    };

    struct Country {                   //Structure to hold country data
        string country_name;
        float highest_newcases=0;
        float highest_newdeaths=0;
        float highest_totalcase=0;
        float highest_totalDeath=0;
//        struct Node *node;
        Node * root=NULL;

//        struct Node * node_start=NULL;
//        struct Node * temp;
//        struct Node *node_start = NULL;

    };

    Country country[15];
    Country country_sorted[15];        //stores country in sorted manner



    //struct Node *start;
    //   struct Node *tmp;
    //  Node *nodeAddress[5000];

    read() {
          //start = NULL;


    }
    int height(struct Node *N)                 //calculate height of avl tree
    {
          if (N == NULL)
                return 0;
          return N->height;
    }

    int max(int a, int b)                              //compares two keys to find max
    {
          return (a > b)? a : b;
    }

    struct Node* newNode(int key,float y, float m, float d, float tc, float nc,float td,float nd,float si) //creates new node and returns address of created node
    {
          Node * node=new Node();
          node->key   = key;
          node->year = y;
          node->month = m;
          node->day = d;
          node->key=((m-1)*30+d);
          node->total_cases = tc;
          node->new_cases = nc;
          node->total_deaths = td;
          node->new_deaths = nd;
          node->si = si;

//          node->total_tests = tt;
//          node->new_tests = nt;
//          node->tests_per_case = tpc;
//          node->positive_rate = pr;
          node->left   = NULL;
          node->right  = NULL;
          node->height = 1;  // new node is initially added at leaf
          return(node);
    }
    struct Node *rightRotate(struct Node *y)
    {
          struct Node *x = y->left;
          struct Node *T2 = x->right;

                                                                // to rotate right
          x->right = y;
          y->left = T2;

                                                                 // to update height of tree
          y->height = max(height(y->left), height(y->right))+1;
          x->height = max(height(x->left), height(x->right))+1;

          return x;
    }

    struct Node *leftRotate(struct Node *x)
    {
          struct Node *y = x->right;
          struct Node *T2 = y->left;


          y->left = x;
          x->right = T2;


          x->height = max(height(x->left), height(x->right))+1;
          y->height = max(height(y->left), height(y->right))+1;

          return y;
    }
    int getBalance(struct Node *N)                            //to get balance condition i.e -1 or 0 or 1
    {
          if (N == NULL)
                return 0;
          return height(N->left) - height(N->right);
    }


    //to insert node/data  to tree
    struct Node* insert(struct Node* node, int key,float y,float m,float d,float tc,float nc,float td,float nd,float si)
    {

          if (node == NULL)
                return(newNode(key,y,m,d,tc,nc,td,nd,si));

          if (key < node->key)
                node->left  = insert(node->left, key,y,m,d,tc,nc,td,nd,si);
          else if (key > node->key)
                node->right = insert(node->right, key,y,m,d,tc,nc,td,nd,si);
          else
                return node;

                                      //height is updated here
          node->height = 1 + max(height(node->left),
                                 height(node->right));


          int balance = getBalance(node);



          if (balance > 1 && key < node->left->key)
                return rightRotate(node);

          if (balance < -1 && key > node->right->key)
                return leftRotate(node);

          if (balance > 1 && key > node->left->key)
          {
                node->left =  leftRotate(node->left);
                return rightRotate(node);
          }

          if (balance < -1 && key < node->right->key)
          {
                node->right = rightRotate(node->right);
                return leftRotate(node);
          }

          return node;
    }
    void preOrder(struct Node *root)
    {
          if(root != NULL)
          {
                printf("%d ", root->key);
                preOrder(root->left);
                preOrder(root->right);
          }
    }

    void search_highest(struct Node *node, int index) {
          if (node == NULL)
                return;

          search_highest(node->left, index);

          if (country[index].highest_newcases <= node->new_cases)
          {country[index].highest_newcases = node->new_cases;}

          if (country[index].highest_newdeaths <= node->new_deaths) {
                country[index].highest_newdeaths = node->new_deaths;
          }
          if (country[index].highest_totalcase <= node->total_cases) {
                country[index].highest_totalcase = node->total_cases;
          }
          if (country[index].highest_totalDeath <= node->total_deaths) {
                country[index].highest_totalDeath = node->total_deaths;
          }



          search_highest(node->right, index);
    }

    struct Node* binary_search(struct Node* root, int key)
    {

          if (root == NULL || root->key == key)
                return root;

          if (root->key < key)
                return binary_search(root->right, key);

          return binary_search(root->left, key);
    }

    Node * search_by_date(struct Node* root,int day,int month)
    {
          cout<<"Result of search"<<endl;
          int ke= (((month - 1) * 30) + day);
          Node * tempNode=binary_search(root,ke);
          cout<<"Date : 2020/ "<<tempNode->month<<"/"<<tempNode->day<<endl;
          cout<<"New Case:  "<<tempNode->new_cases<<endl;
          cout<<"New Deaths:  "<<tempNode->new_deaths<<endl;
          cout<<"Total Case:  "<<tempNode->total_cases<<endl;
          cout<<"Total Deaths:  "<<tempNode->total_deaths<<endl;

          return tempNode;

    }


    void find_highest() {
          for (int i = 0; i < 13; i++) {
                search_highest(country[i].root,i);


          }
    }


    void printInorder(struct Node* node)
    {
          if (node == NULL)
                return;

          printInorder(node->left);

          cout << node->key << " "<<node->month<<"   "<<node->day<<"   "<<node->new_cases<<endl;

          printInorder(node->right);
    }

    void read_data(string ,int,float, float, float, float, float,float ,float,float );
    void copy_country()
    {
        for(int i=0;i<13;i++)
        {
            country_sorted[i]=country[i];

        }
    }
    void sort_country_by_total_case();
    void sort_country_by_total_death();
    void sort_country_by_highest_newCase();
    void sort_country_by_highest_newDeath();



    void bubble_sort();


};



void read::read_data( string loc,int pos,float y, float m, float d, float tc, float nc,float td,float nd,float si) {
      int ke = (((m - 1) * 30) + d);
      country[pos].country_name=loc;
      country[pos].root = insert(country[pos].root, ke, y, m, d, tc, nc,td,nd,si);

}


//void read::sort_country_by_total_death()
//{

//          bool selected = true;
//          for (int pass = 0; pass < 12 && selected == true; pass++) {
//                selected = false;
//                for (int j = 0; j < 12 - pass - 1; j++) {
//                      if (country_sorted[j].highest_totalDeath > country_sorted[j + 1].highest_totalDeath) {
//                          struct Country temp;
//                            temp = country_sorted[j];
//                            country_sorted[j] = country_sorted[j + 1];
//                            country_sorted[j + 1] = temp;
//                            selected = true;


//                      }
//                }
//          }



//}


void read::sort_country_by_total_case()
{

    int j;
     struct Country temp_country;

        for (int i = 1; i <12; i++)
        {
            temp_country = country_sorted[i];
            j = i - 1;

            while (j >= 0 && country_sorted[j].highest_totalcase > temp_country.highest_totalcase)
            {
                country_sorted[j + 1] = country_sorted[j];
                j = j - 1;
            }
            country_sorted[j + 1] = temp_country;
        }



}



void read::sort_country_by_total_death()
{

    int j;
     struct Country temp_country;

        for (int i = 1; i <12; i++)
        {
            temp_country = country_sorted[i];
            j = i - 1;

            while (j >= 0 && country_sorted[j].highest_totalDeath > temp_country.highest_totalDeath)
            {
                country_sorted[j + 1] = country_sorted[j];
                j = j - 1;
            }
            country_sorted[j + 1] = temp_country;
        }



}



//void read::sort_country_by_highest_newCase()
//{

//          bool selected = true;
//          for (int pass = 0; pass < 12 && selected == true; pass++) {
//                selected = false;
//                for (int j = 0; j < 12 - pass - 1; j++) {
//                      if (country_sorted[j].highest_newcases > country_sorted[j + 1].highest_newcases) {
//                          struct Country temp;
//                            temp = country_sorted[j];
//                            country_sorted[j] = country_sorted[j + 1];
//                            country_sorted[j + 1] = temp;
//                            selected = true;


//                      }
//                }
//          }



//}


void read::sort_country_by_highest_newCase()
{

    int j;
     struct Country temp_country;

        for (int i = 1; i <12; i++)
        {
            temp_country = country_sorted[i];
            j = i - 1;

            while (j >= 0 && country_sorted[j].highest_newcases > temp_country.highest_newcases)
            {
                country_sorted[j + 1] = country_sorted[j];
                j = j - 1;
            }
            country_sorted[j + 1] = temp_country;
        }





}

//void read::sort_country_by_highest_newDeath()
//{

//          bool selected = true;
//          for (int pass = 0; pass < 12 && selected == true; pass++) {
//                selected = false;
//                for (int j = 0; j < 12 - pass - 1; j++) {
//                      if (country_sorted[j].highest_newdeaths > country_sorted[j + 1].highest_newdeaths) {
//                          struct Country temp;
//                            temp = country_sorted[j];
//                            country_sorted[j] = country_sorted[j + 1];
//                            country_sorted[j + 1] = temp;
//                            selected = true;


//                      }
//                }
//          }



//}

void read::sort_country_by_highest_newDeath()
{
int j;
 struct Country temp_country;

    for (int i = 1; i <12; i++)
    {
        temp_country = country_sorted[i];
        j = i - 1;

        while (j >= 0 && country_sorted[j].highest_newdeaths > temp_country.highest_newdeaths)
        {
            country_sorted[j + 1] = country_sorted[j];
            j = j - 1;
        }
        country_sorted[j + 1] = temp_country;
    }

}





#endif //DATASTRUCTUREPROJECT_DATASTRUCTURE_TO_READ_DATA_H

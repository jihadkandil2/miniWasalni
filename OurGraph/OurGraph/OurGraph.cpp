#include <iostream>
#include "Graph.h"
#include <fstream>
using namespace std;


int main()
{
    int choice,choice2;
    string city;
    string city1, city2;
    double weight;
    Graph g;

    cout << "************************************" << endl;
    cout << "******||Welcome To Wasalni||********" << endl;
    cout << "************************************" << endl;
    while (true)
    {
        cout << "1- Admin" << endl;
        cout << "2- User" << endl;
        cout << "3- exit" << endl;
        cout << "Choose if you are Admin or User:";
        cin >> choice;
        switch (choice)
        {
        case 1: //Admin
            cout << "--------------------------------------------" << endl;
            cout << "As you are admin you can choose to : " << endl;
            cout << "1- Add City to our MAP" << endl;
            cout << "2- Add Edge Between cities " << endl;
            cout << "--------------------------------------------" << endl;
            cout << "Enter what you want to do (1 or 2):  "; cin >> choice2;
            if (choice2 == 1)
            {
                cout << "Enter name of the city : "; cin >> city;
                g.addCity(city);
                cout << "--------------------------------------------------------------------------" << endl;
            }
            else if (choice2 == 2)
            {
                    cout << "Enter the two cities and the distance between them in this format [ 'city1' 'city2' 'distance' ]: ";
                    cin >> city1 >> city2 >> weight;
                    g.addEdge(city1, city2, weight);
                    cout << "--------------------------------------------------------------------------" << endl;
            }
            else
            {
                cout << "Sorry You entered Invalid Choice, try again later!!" << endl;
                cout << "--------------------------------------------------------------------------" << endl;
            }
            break;

        case 2:   // user
            cout << "--------------------------------------------" << endl;
            cout << "As you are User you can choose to : " << endl;
            cout << "1- Display MAP Data" << endl;
            cout << "2- Query the shortest path between 2 cities " << endl;
            cout << "--------------------------------------------" << endl;
            cout << "Enter your choice between (1 amd 2): "; cin >> choice2;
            if (choice2 == 1)
            {
                g.displayGraph();
                cout << "--------------------------------------------------------------------------" << endl;
            }
            else if (choice2 == 2)
            {
                //code sara / seham / shahd / dalia >> will be choices here 
            }
            else
            {
                cout << "Sorry You entered Invalid Choice, try again later!!" << endl;
                cout << "--------------------------------------------------------------------------" << endl;
            }
            break; 
        case 3:   // exit
            g.saveData();
            cout << "\n\nThanks for choosing Wasalni to reach your target in shortest distance" << endl;
            cout << "               Wasalni hopes you a beautiful day     " << endl;
            return 0;
          
        default:
            cout << "Sorry You entered Invalid Choice, try again later!!" << endl;
            cout << "--------------------------------------------------------------------------" << endl;
            return 0;
            break;
        }
    }
    g.saveData();
     return 0;
    
}



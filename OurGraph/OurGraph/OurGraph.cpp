#include <iostream>
#include "Graph.h"
#include <fstream>
using namespace std;


int main()
{
    int choice,choice2;
    string cityName;
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
            cout << "3- Delete city " << endl;
            cout << "4- Delete Edge Between cities " << endl;
            cout << "--------------------------------------------" << endl;
            cout << "Enter what you want to do (1 or 2):  "; cin >> choice2;
            if (choice2 == 1)
            {
                cout << "Enter name of the city : "; cin >> cityName;
                g.addCity(cityName);
                cout << "--------------------------------------------------------------------------" << endl;
            }
            else if (choice2 == 2)
            {
                    cout << "Enter the two cities and the distance between them in this format [ 'city1' 'city2' 'distance' ]: ";
                    cin >> city1 >> city2 >> weight;
                    g.addEdge(city1, city2, weight);
                    cout << "--------------------------------------------------------------------------" << endl;
            }
            else if (choice2 == 3)
            {
                cout << "Enter The name of city" << endl;
                cin >> cityName;
                g.deleteCity(cityName);
                cout << "--------------------------------------------------------------------------" << endl;
            }
            else if (choice2 == 4)
            {
                cout << "Enter the two cities in this format [ 'city1' 'city2' ]" << endl;
                cin >> city1 >> city2;
                g.deleteEdge(city1, city2);
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
            cout << "3- traverse the map using DFS" << endl;
            cout << "4- traverse the map Using BFS" << endl;
            cout << "5- for topoligical sort of the graph " << endl;
            cout << "--------------------------------------------" << endl;

            cout << "Enter your choice between (1 , 2 , 3 , 4): "; cin >> choice2;
            if (choice2 == 1)
            {
                g.displayGraph();
                cout << "--------------------------------------------------------------------------" << endl;
            }
            else if (choice2 == 2)
            {
                //code seham
                string startCity; string destination;
                cout << "Enter the name of city to start [from] and your destination [city]: "; 
                cin >> startCity >> destination;
                g.dijkstra(startCity , destination);
            }
            else if (choice2 == 3)       //shahd
            {    
                string source_node;
                cout << "Enter start city : ";
                cin >> source_node;
                cout << "DFS traverse from " << source_node << " : [ ";
                g.DFS(source_node);//if output is just source node ,this means that this node there is no out edges from it 
                cout << "]\n";
                cout << "--------------------------------------------" << endl;

            }
            else if (choice2 == 4)
            {
                // code sara
                string sourceNode;
                cin >> sourceNode;
                g.BFS(sourceNode);
            }
            else if (choice2 == 5)
            {
               /* vector<string> order = g.topologicalSort();
                cout << "topologicalSort of the graph is" << endl;
                cout << "-----------------------" << endl;
                for (auto it = order.begin(); it != order.end(); ++it) {
                    cout << *it << " ";
                }
                cout << endl;*/
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



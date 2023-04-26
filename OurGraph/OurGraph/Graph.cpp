#include "Graph.h"
#include <iostream>
using namespace std;

Graph::Graph() {}

// test comment

  /*
   * if    already found i will tell the user
   * else  i will insert it
   */
void Graph::addCity(string name)
{
    auto found = city.find(name);
    if (found != city.end())
    {
        cout << found->first << " City is already exist in our Map" << endl;
        // I want to insert code display the city info for the user
    }
    else {
        city[name];
    }
}


/*
 * if        two cities are not in the graph
 * else if   first city is not in the graph
 * else if   second city is not in the graph
 * else      we can add this edge between 2 cities
 */
void Graph::addEdge(string city1, string city2, double weight)
{
    auto found1 = city.find(city1);
    auto found2 = city.find(city2);

    if (found1 == city.end() && found2 == city.end())
    {
        cout << "Sorry can not add this edge as [ " << city1 << " ] and [ " << city2 << " ] is not in graph." << endl;
        //try add these cities
    }
    else if (found1 == city.end())
    {
        cout << "Sorry can not add this edge as [ " << city1 << " ] is not in graph." << endl;
    }
    else if (found2 == city.end())
    {
        cout << "Sorry can not add this edge as [ " << city2 << " ] is not in graph." << endl;
    }
    else {
        city[city1].push_back({ city2,weight });
    }
}





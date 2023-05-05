#pragma once
#include "Graph.h"
#include <unordered_map>
#include<vector>
#include<string>
using namespace  std;

enum type {
    BFS = 1, DFS = 2, dijkstra = 3
};


class Graph {
    unordered_map  < string, vector <pair <string, double> > > city;
   
public:
    Graph();
    void DisplayBucketsInfo(); //jihad
    //void DisplayData();        //jihad
    void addCity(string name);
    void addEdge(string city1, string city2, double weight);
    void displayGraph();
    void deleteCity(string city_name);
    void deleteEdge(string city1, string city2);
    void traverse(type t);
    void BFS(string srcNode);
    void DFS(string start);
    void dijkstra(string startPoint, string destination);
    void saveData();            //jihad
    vector<string> topologicalSort();
};



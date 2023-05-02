#include "Graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

Graph::Graph() {
    // Read the unordered_map from the file
    ifstream infile("city.txt");
    string line;
    string city_name;
    while (getline(infile, line)) {
        if (!line.empty()) {
            if (line.back() == ':') {
                // Start of a new city
                city_name = line.substr(0, line.length() - 1);
                city[city_name] = {};
            }
            else {
                // Read a pair of (city, distance)
                string city2;
                double distance;
                istringstream iss(line);
                iss >> city2 >> distance;
                city[city_name].push_back(make_pair(city2, distance));
            }
        }
    }
    infile.close();
}

void Graph :: saveData()
{
    // Write the unordered_map to a file
    ofstream outfile("city.txt");
    for (auto& it : city) {
        outfile << it.first << ":\n";
        for (auto& pair : it.second) {
            outfile << "  " << pair.first << " " << pair.second << "\n";
        }
    }
}


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
        cout << "We added " << name << " successfully." << endl;
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
        cout << "Edge is added Successfully." << endl;
    }
    // condition to loop on the already exist edge .
}

void Graph::displayGraph()
{
    cout << "The Graph Data is:-" << endl;
    cout << "--------------------" << endl;
    for ( auto  C : city)
    {
        cout << C.first << " :-" << endl;
        for (auto  LinkedCity : C.second)
        {
            cout << C.first << " linked To -> " << LinkedCity.first << "  with cost = " << LinkedCity.second << " KM" << endl;
        }
        cout << "----------------------------------------------------------------" << endl;
    }
}


void Graph::DisplayBucketsInfo()
{
    //عشان يعدي علي كل باكيت يعني كل مدينة ال I هنا بتمثل باكيت
    for (int i = 0; i < city.bucket_count(); ++i)
    {
        cout << "bucket #" << i << " of size " << city.bucket_size(i) << " contains:\n";
        cout << "--------------------------------" << endl;
        auto l = city.begin(i);
        // عشان اعدي علي كل باكيت اشوف الي جواها كافاليو واشوف مرتبطة ب فيكتور حجمه اد اي
        for (auto local_it = city.begin(i); local_it != city.end(i); ++local_it)
        {
            cout << local_it->first << " with " << local_it->second.size() << " element in the vector" << endl;
            int vectorSize = l->second.size();
            // عشان الف جوا كل فيكتور واطلع البير الي جواه
            for (int j = 0; j < vectorSize; ++j)
            {
                cout << "\nElement is : " << l->second.at(j).first << " with cost $ =  " << l->second.at(j).second;
            }
        }
        cout << endl << "-------------------------------------------------------------------\n";
    }
}





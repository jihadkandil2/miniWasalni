#include "Graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include<queue>
#include <cassert>
#include <stack>
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



void Graph::deleteCity(string city_name)
{
    auto found = city.find(city_name);
    if (found == city.end()) {
        cout << "Sorry can not delete this city as it is not in the graph." << endl;
        return;
    }

    // remove all edges from this city to other cities
    for (auto& adjacent_city : found->second) {
        string adj_city_name = adjacent_city.first;
        auto it = city.find(adj_city_name);
        if (it != city.end()) {
            for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
                if (it2->first == city_name) {
                    it->second.erase(it2);
                    break;
                }
            }
        }
    }

    // remove the city from the graph
    city.erase(found);
    cout << "City " << city_name << " and all its edges are deleted successfully." << endl;
}


void Graph::deleteEdge(string city1, string city2)
{
    auto found1 = city.find(city1);
    auto found2 = city.find(city2);

    if (found1 == city.end() || found2 == city.end())
    {
        cout << "Sorry can not delete this edge as one or both cities are not in the graph." << endl;
        return;
    }

    // remove the edge from city1 to city2
    for (auto it = city[city1].begin(); it != city[city1].end(); ++it) {
        if (it->first == city2) {
            city[city1].erase(it);
            cout << "Edge between " << city1 << " and " << city2 << " is deleted successfully." << endl;
            return;
        }
    }

    // if the loop above doesn't find the edge, it means the edge doesn't exist in the graph
    cout << "Sorry can not delete this edge as the edge between " << city1 << " and " << city2 << " doesn't exist in the graph." << endl;
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



void Graph::dijkstra(string start_point , string destination) {
    const int infinity = 999999999;

    priority_queue < pair<double, string>, vector < pair<double, string>>, greater<pair < double, string>>> visited_node;
    unordered_map<string, pair <string ,double>> distanceToCity;     // cairo - 0 - null 
   // vector<pair<string, double>>our_shortest_path;

   // unordered_map <string, pair<string, double >> ShortPath;  

    // to initialize all node to infinity
    for (auto it : city) {
        distanceToCity[it.first] = { "0",infinity};
    }
    distanceToCity[start_point] = { "0" , 0};

    // fill the priorty queue with the shortest path to this city 
    visited_node.push(make_pair(0, start_point));
   // our_shortest_path.push_back({ start_point, distanceToCity[start_point] });
    string current_node ;
    while (!visited_node.empty())
    {                                           
         current_node = visited_node.top().second;    // queue is visted node    // cairo 
         visited_node.pop();
       
        
      

        for (auto get_child : city[current_node])    //cairo >> ismailia >> giza 
        {
            string destination_city = get_child.first;    // giza
            double weight = get_child.second;             // 8.3

            if (distanceToCity[destination_city].second > distanceToCity[current_node].second + weight) 
            {
                distanceToCity[destination_city].second = distanceToCity[current_node].second + weight;
                distanceToCity[destination_city].first = current_node;
                visited_node.push(make_pair(distanceToCity[destination_city].second, destination_city));
            }
        }
    }
     
    stack <string> path;
    path.push(destination);
    string dist = destination;
    double cost = distanceToCity[destination].second;

    auto foundDestination = distanceToCity.find(destination);
    if (foundDestination == distanceToCity.end())
    {
        cout << "No path to this Destination" << endl;
    }
    else if (distanceToCity[destination].second == infinity)
    {
        cout << "No path to this Destination" << endl;
    }
    else 
        {
        while (distanceToCity[destination].first != start_point)
        {
            destination = distanceToCity[destination].first;
            path.push(destination);

        }
    }
   

    cout <<"Your path from " << start_point << " to " << dist << " is : \n[ " << start_point << " ";
    while (!path.empty())
    {
        cout << path.top() << " ";
        path.pop();
    }
    cout << "]" << "with cost = " << cost << endl;
    cout << "----------------------------------------------------------" << endl;
}



void Graph::DFS(string start)
{
    assert(city.find(start) != city.end());
    stack <string >nodes;
    nodes.push(start);
    unordered_map<string, bool >visited;
    for (auto it = city.begin(); it != city.end(); it++)// to intialize all nodes with false till be visited
    {
        visited[it->first] = false;
    }
    while (!nodes.empty())
    {
        string vertex = nodes.top();
        nodes.pop();
        if (visited[vertex] == false)//to any node has pushed more than one (because it isnot visited), didnot showed more than one
        {
            visited[vertex] = true;
            cout << vertex << "  ";
        }
        vector<pair<string, double>> neighbour = city[vertex];
        for (auto it = neighbour.begin(); it != neighbour.end(); it++)//to push childern of the vertex
        {
            if (visited[it->first] == false)// to any visited node didnot pushed twice 
            {
                nodes.push(it->first);
            }
        }
    }
}


void Graph::BFS(string srcNode)
{
    unordered_map <string, bool> visited_nodes; // vector(array) to know if the node is visited or not.
    queue<string> q_of_graphNodes; // queue to store the values of the node and trverse it. 

    for (auto it = city.begin();it != city.end(); it++)
    {
        visited_nodes.insert({ it->first, false });
    }
    visited_nodes[srcNode] = true; // add (pushing) the node in the array or vector to be already visited node.
    q_of_graphNodes.push(srcNode); //add (pushing the node into the queue).

    //the previous line can be written like that:  
    while (!q_of_graphNodes.empty())// while that the queue id not empty continue the process. 
    {
        string current_node = q_of_graphNodes.front(); // just storing th node in a variable because I will pop it.
        q_of_graphNodes.pop();
        cout << current_node << endl;

        for (auto neighbour = city[current_node].begin(); neighbour != city[current_node].end(); neighbour++)// iterator to loop the nodes of the graph, itrate on the vector of pair.
        {
            if (!visited_nodes[neighbour->first])//if the node is not visited, the condition can be written: 
            {
                q_of_graphNodes.push(neighbour->first);
                //visited_nodes.insert({ neighbour->first, true});
                visited_nodes[neighbour->first] = true;
            }
        }
    }
}


 /*vector<string> Graph::topologicalSort()
{
    unordered_map<string, int> inDegree;
    for (auto node : city) {
        inDegree[node.first] = 0;
    }
    for (auto node : city) {
        for (auto neighbor : node.second) {
            inDegree[neighbor.first]++;
        }
    }
    stack<string> s;
    for (auto node : city) {
        if (inDegree[node.first] == 0) {
            s.push(node.first);
        }
    }
    vector<string> result;
    while (!s.empty()) {
        string node = s.top();
        s.pop();
        result.push_back(node);
        for (auto neighbor : city[node]) {
            inDegree[neighbor.first]--;
            if (inDegree[neighbor.first] == 0) {
                s.push(neighbor.first);
            }
        }
    }
    return result;
} */
#include <iostream>
#include "Graph.h"
using namespace std;


int main()
{
    Graph g;

    g.addCity("cairo");
    g.addCity("Alexandria");
    g.addCity("MarsaMatroh");
    g.addCity("Ismailia");
    g.addCity("Giza");
    g.addCity("Banisuef");
    g.addCity("Elminia");
    g.addCity("sues");
    g.addCity("Zagazig");
    g.addCity("faioum");


    g.addEdge("Giza", "sues", 146);
    g.addEdge("Giza", "cairo", 9.2);
    g.addEdge("Giza", "Alexandria", 222);


    g.addEdge("Alexandria", "cairo", 221);
    g.addEdge("Alexandria", "Giza", 228);
    g.addEdge("Alexandria", "Zagazig", 190);
    g.addEdge("Alexandria", "MarsaMatroh", 284);


    g.addEdge("cairo", "Giza", 8.3);
    g.addEdge("cairo", "Alexandria", 218);
    g.addEdge("cairo", "Zagazig", 86);
    g.addEdge("cairo", "Ismailia", 126);


    g.addEdge("Ismailia", "sues", 89);

    g.addEdge("Banisuef", "Giza", 155);

    g.addEdge("Elminia", "Banisuef", 92);

    g.addEdge("Zagazig", "Ismailia", 84);

    // add edge with newyork which not found

    g.addEdge("newyork", "cairo", 30000);
    

}



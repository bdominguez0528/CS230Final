#include <iostream>
#include "graph.hpp"

int main(){
    Graph g(4);
    g.addEdge(0, 1, 1.0);
    g.addEdge(0, 2, 3.0);
    g.addEdge(0, 3, 4.0);
    g.addEdge(1, 2, 2.0);
    g.addEdge(2, 3, 5.0);

    auto mst = g.findMST();
    double total = 0.0;
    
    cout << "MST Edges:" << endl;
    for (const auto& e : mst){
        cout << e.srcVertex << " - " << e.destVertex << " : " << e.weight << endl;
        total += e.weight;
    }

    cout << "Total Weight: " << total << endl;
    return 0;
}
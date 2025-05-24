#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <memory>
#include "edge.hpp"

using namespace std;

class DisjointSet{
    vector<int> parent, rank;

public:
    DisjointSet(int n);
    int find(int x);
    void unite(int x, int y);
};

class Graph{
    int V;
    vector<Edge> edges;

public:
    Graph(int vertices);
    void addEdge(int u, int v, double w);
    vector<Edge> findMST() const;
};

#endif
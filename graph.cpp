#include "graph.hpp"
#include <algorithm>

using namespace std;

DisjointSet::DisjointSet(int n) : parent(n), rank(n, 0) {
    for (int i = 0; i < n; ++i){
        parent[i] = i;
    }
}
int DisjointSet::find(int x){
    if (parent[x] != x){
        parent[x] = find(parent[x]);
    }
    return parent[x];
}
void DisjointSet::unite(int x, int y){
    int xroot = find(x);
    int yroot = find(y);
    if (xroot == yroot){
        return;
    }
    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

Graph::Graph(int vertices) : V(vertices) {}
void Graph::addEdge(int u, int v, double w){
    edges.emplace_back(u, v, w);
}
vector<Edge> Graph::findMST() const{
    vector<Edge> result;
    vector<Edge> sortedEdges = edges;
    sort(sortedEdges.begin(), sortedEdges.end());
    DisjointSet ds(V);
    for (const Edge& e : sortedEdges){
        if (ds.find(e.srcVertex) != ds.find(e.destVertex)){
            result.push_back(e);
            ds.unite(e.srcVertex, e.destVertex);
        }
        if (result.size() == V - 1){
            break;
        }
    }
    return result;
}
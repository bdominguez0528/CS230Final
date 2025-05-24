#ifndef EDGE_HPP
#define EDGE_HPP

struct Edge{
    int srcVertex, destVertex;
    double weight;
    Edge(int src, int dest, double w) : srcVertex(src), destVertex(dest), weight(w) {}
    bool operator<(const Edge& other) const{
        return weight < other.weight;
    }
};

#endif // EDGE_HPP
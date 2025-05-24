#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "graph.hpp"

TEST_CASE("MST - Kruskal's Algorithm", "[MST]"){
    Graph g(4);
    g.addEdge(0, 1, 1.0);
    g.addEdge(0, 2, 3.0);
    g.addEdge(0, 3, 4.0);
    g.addEdge(1, 2, 2.0);
    g.addEdge(2, 3, 5.0);

    auto result = g.findMST();

    double totalWeight = 0.0;
    cout << "Test: MST - Kruskal's Algorithm" << endl;
    cout << "MST Edges:" << endl;
    for (const auto& edge : result){
        cout << edge.srcVertex << " - " << edge.destVertex << " : " << edge.weight << endl;
        totalWeight += edge.weight;
    }
    cout << "Total Weight: " << totalWeight << endl;
    REQUIRE(result.size() == 3);
    REQUIRE(totalWeight == Approx(7.0));
}

TEST_CASE("MST - Disconnected Graph", "[MST]") {
    Graph g(4);
    g.addEdge(0, 1, 1.0);
    g.addEdge(2, 3, 2.0);

    auto result = g.findMST();
    double totalWeight = 0.0;
    cout << "Test: MST - Disconnected Graph" << endl;
    cout << "MST Edges:" << endl;
    for (const auto& edge : result) {
        cout << edge.srcVertex << " - " << edge.destVertex << " : " << edge.weight << endl;
        totalWeight += edge.weight;
    }
    cout << "Total Weight: " << totalWeight << endl;
    REQUIRE(result.size() == 2);
    REQUIRE(totalWeight == Approx(3.0));
}

TEST_CASE("MST - Single Node", "[MST]") {
    Graph g(1);
    auto result = g.findMST();
    cout << "Test: MST - Single Node" << endl;
    cout << "MST Edges: (should be empty)" << endl;
    cout << "Total Weight: 0" << endl;
    REQUIRE(result.empty());
}

TEST_CASE("MST - Two Nodes, One Edge", "[MST]") {
    Graph g(2);
    g.addEdge(0, 1, 42.0);
    auto result = g.findMST();
    cout << "Test: MST - Two Nodes, One Edge" << endl;
    cout << "MST Edges:" << endl;
    for (const auto& edge : result) {
        cout << edge.srcVertex << " - " << edge.destVertex << " : " << edge.weight << endl;
    }
    cout << "Total Weight: " << result[0].weight << endl;
    REQUIRE(result.size() == 1);
    REQUIRE(result[0].weight == Approx(42.0));
}

TEST_CASE("MST - All Edges Same Weight", "[MST]") {
    Graph g(3);
    g.addEdge(0, 1, 5.0);
    g.addEdge(1, 2, 5.0);
    g.addEdge(0, 2, 5.0);
    auto result = g.findMST();
    cout << "Test: MST - All Edges Same Weight" << endl;
    cout << "MST Edges:" << endl;
    double totalWeight = 0.0;
    for (const auto& edge : result) {
        cout << edge.srcVertex << " - " << edge.destVertex << " : " << edge.weight << endl;
        totalWeight += edge.weight;
    }
    cout << "Total Weight: " << totalWeight << endl;
    REQUIRE(result.size() == 2);
    REQUIRE(totalWeight == Approx(10.0));
}

TEST_CASE("MST - Negative Weights", "[MST]") {
    Graph g(4);
    g.addEdge(0, 1, -2.0);
    g.addEdge(1, 2, -3.0);
    g.addEdge(2, 3, 4.0);
    g.addEdge(3, 0, 1.0);

    auto result = g.findMST();
    cout << "Test: MST - Negative Weights" << endl;
    cout << "MST Edges:" << endl;
    double totalWeight = 0.0;
    for (const auto& edge : result) {
        cout << edge.srcVertex << " - " << edge.destVertex << " : " << edge.weight << endl;
        totalWeight += edge.weight;
    }
    cout << "Total Weight: " << totalWeight << endl;
    REQUIRE(result.size() == 3);
    REQUIRE(totalWeight == Approx(-4.0));
}

TEST_CASE("MST - Larger Graph", "[MST]") {
    Graph g(6);
    g.addEdge(0, 1, 3.0);
    g.addEdge(0, 2, 1.0);
    g.addEdge(1, 2, 7.0);
    g.addEdge(1, 3, 5.0);
    g.addEdge(2, 3, 4.0);
    g.addEdge(3, 4, 2.0);
    g.addEdge(4, 5, 6.0);
    g.addEdge(3, 5, 8.0);

    auto result = g.findMST();
    cout << "Test: MST - Larger Graph" << endl;
    cout << "MST Edges:" << endl;
    double totalWeight = 0.0;
    for (const auto& edge : result) {
        cout << edge.srcVertex << " - " << edge.destVertex << " : " << edge.weight << endl;
        totalWeight += edge.weight;
    }
    cout << "Total Weight: " << totalWeight << endl;
    REQUIRE(result.size() == 5);
    REQUIRE(totalWeight == Approx(16.0));
}
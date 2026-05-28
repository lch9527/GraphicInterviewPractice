// Tesla Q16: Implement Graph Adjacency List
/*
Goal:
Build a functional directed graph using adjacency lists.
*/

#include "MathTypes.h"
#include <vector>
#include <algorithm>

class DirectedGraph {
public:
    void AddNode(int node) {
        // TODO: add node if it does not already exist.
        (void)node;
    }

    void AddEdge(int from, int to) {
        // TODO: add from/to nodes if needed, then add directed edge from -> to.
        (void)from;
        (void)to;
    }

    bool HasNode(int node) const {
        // TODO: return true if node exists.
        (void)node;
        return false;
    }

    bool HasEdge(int from, int to) const {
        // TODO: return true if directed edge from -> to exists.
        (void)from;
        (void)to;
        return false;
    }

    std::vector<int> Neighbors(int node) const {
        // TODO: return outgoing neighbors for node.
        (void)node;
        return {};
    }

    int NodeCount() const {
        // TODO: return number of unique nodes.
        return 0;
    }
};

bool SameValues(std::vector<int> a, std::vector<int> b) {
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    return a == b;
}

bool RunTests() {
    DirectedGraph graph;
    graph.AddEdge(1, 2);
    graph.AddEdge(1, 3);
    graph.AddEdge(2, 3);
    graph.AddNode(4);
    EXPECT_TRUE(graph.HasNode(1));
    EXPECT_TRUE(graph.HasNode(4));
    EXPECT_FALSE(graph.HasNode(9));
    EXPECT_TRUE(graph.HasEdge(1, 2));
    EXPECT_FALSE(graph.HasEdge(3, 1));
    EXPECT_TRUE(SameValues(graph.Neighbors(1), {2,3}));
    EXPECT_EQ_INT(graph.NodeCount(), 4);
    return true;
}

RUN_TESTS()


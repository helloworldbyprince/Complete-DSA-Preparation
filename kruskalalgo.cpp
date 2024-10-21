#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge {
    int u, v, weight;
    // Comparison operator to sort edges based on weight
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};
// Find function with path compression for disjoint set
int find(int v, vector<int>& parent) {
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v], parent);
}
// Union function to union two sets
void union_sets(int a, int b, vector<int>& parent, vector<int>& rank) {
    a = find(a, parent);
    b = find(b, parent);
    
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}
void kruskalMST(int n, vector<Edge>& edges) {
    vector<int> parent(n);
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        parent[i] = I;
    sort(edges.begin(), edges.end());
    int totalCost = 0;
    vector<Edge> result;
   // Process each edge in sorted order
    for (Edge e : edges) {
        if (find(e.u, parent) != find(e.v, parent)) {
            totalCost += e.weight;
            result.push_back(e);
            union_sets(e.u, e.v, parent, rank);
        }
    }
    cout << "Cost of MST: " << totalCost << endl;
    for (Edge e : result)
        cout << e.u << " -- " << e.v << " == " << e.weight << endl;
}

int main() {
    int n = 10;  // Number of vertices
    vector<Edge> edges = {
        {0, 1, 15}, {0, 3, 19}, {1, 3, 7}, {1, 4, 17},
        {2, 3, 10}, {2, 5, 14}, {3, 4, 12}, {3, 6, 3},
        {4, 6, 20}, {5, 6, 6}, {5, 8, 5}, {6, 7, 4},
        {6, 8, 9}, {7, 9, 2}, {8, 9, 1}, {6, 9, 11}, 
        {7, 8, 13}, {4, 7, 13}
    };
    kruskalMST(n, edges);
      return 0;
}

#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

enum Color {
    WHITE,
    GRAY,
    BLACK,
};

struct Graph {
    int V;
    vector<vector<int>> adj;
    vector<Color> colors;
    vector<int> topOrder;
    bool contain_cycle = false;

    Graph(int V) {
        this->V = V;
        adj.assign(V, {});
    }

    void add_edge(int x, int y, bool directed);
    void topologicalSort();

};

void Graph::add_edge(int x, int y, bool directed) {
    adj[x].push_back(y);

    if (!directed) {
        add_edge(y, x, true);
    }
}

void Graph::topologicalSort() {
    vector<int> inDegree(V, 0);
    priority_queue<int> pq;

    for (int u = 1; u < V; ++u) {
        for (int v : adj[u]) {
            inDegree[v]++;
        }
    }

    for (int i = 1; i < V; ++i) {
        if (inDegree[i] == 0) {
            pq.push(i);
        }
    }

    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        topOrder.push_back(u);

        for (int v : adj[u]) {
            if (--inDegree[v] == 0) {
                pq.push(v);
            }
        }
    }

}

int main() {
    int n;
    cin >> n;
    Graph g(n + 1);

    int k_i;
    for (int i = 0; i < n; ++i) {
        cin >> k_i;
        int t;
        for (int j = 0; j < k_i; ++j) {
            cin >> t;
            g.add_edge(i + 1, t, true);
        }
    }

    g.topologicalSort();

    for (int i = g.topOrder.size() - 1; i > -1; --i) {
        cout << g.topOrder[i] << " ";
    }
}

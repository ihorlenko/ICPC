#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <cmath>
#define EPS 1e-9

using namespace std;

vector<double> probs;

struct Graph{
    int V;
    vector<int> in_degree;
    vector<int> out_degree;
    vector<vector<int>> adj;

    Graph(int V) {
        this->V = V;
        in_degree.assign(V, 0);
        out_degree.assign(V, 0);
        adj.assign(V, {});
    };

    void add_edge(int x, int y, bool directed);

    void kahn(int start);
};

void Graph::add_edge(int x, int y, bool directed) {
    adj[x].push_back(y);

    if (!directed) {
        add_edge(y, x, true);
    }
}

void Graph::kahn(int start) {
    queue<int> q;

    for (int i = 1; i < in_degree.size(); i++)
        if (in_degree[i] == 0) q.push(i);
    probs[start] = 1.0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            probs[v] += probs[u] / out_degree[u];
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }
}

int main() {
    int n, m, r;
    cin >> n >> m >> r;
    probs.assign(n + 1, 0);

    Graph g(n + 1);

    int u, v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        g.add_edge(u, v, true);
        g.in_degree[v]++;
        g.out_degree[u]++;
    }

    g.kahn(r);

    double max_prob = -1;

    for (int i = 1; i < probs.size(); ++i) {
        if (g.out_degree[i] == 0) {
            max_prob = max(max_prob, probs[i]);
        }
    }

    for (int i = 1; i < probs.size(); ++i) {
        if (g.out_degree[i] == 0 && fabs(probs[i] - max_prob) <= EPS) {
            cout << i << " ";
        }
    }
}
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

enum Color {
    GREEN,
    RED,
};

struct Graph {
    int V;
    vector<vector<int>> adj;
    vector<Color> colors;
    vector<bool> visited;

    Graph(int V) {
        this->V = V;
        adj.assign(V, {});
        colors.assign(V, RED);
        visited.assign(V, false);
    }

    void add_edge(int x, int y);
    Color dfs(int u);
};

void Graph::add_edge(int x, int y) {
    adj[x].push_back(y);
    adj[y].push_back(x);
}

Color Graph::dfs(int u) {
    visited[u] = true;
    Color succesor_color;

    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (!visited[v]) {
            succesor_color = dfs(v);
            if (succesor_color == RED) {
                colors[u] = GREEN;
            }
        }
    }

    return colors[u];
}

int main() {
    int n, k;
    cin >> n >> k;
    Graph g(n + 1);

    int u, v;
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        g.add_edge(u, v);
    }

    bool firstPlayerWins = (g.dfs(k) == GREEN);

    if (firstPlayerWins) {
        int minAirport = INT_MAX;
        for (int v : g.adj[k]) {
            minAirport = g.colors[v] == RED ? min(minAirport, v) : minAirport;
        }
        cout << "First player wins flying to airport " << minAirport;
    } else {
        cout << "First player loses";
    }
}
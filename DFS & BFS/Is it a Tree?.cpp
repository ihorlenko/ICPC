#include <iostream>
#include <vector>

using namespace std;

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
    vector<int> parents;
    bool is_cycled;
    bool is_connected;

    Graph(int V) {
        this->V = V;
        adj.assign(V, {});
        colors.assign(V, WHITE);
        parents.assign(V, -1);
    }

    void add_edge(int x, int y) {
        adj[x].push_back(y);
    }

    void dfs(int u) {
        is_cycled = false;
        dfs_visit(u);
        for (int i = 1; i < adj.size(); ++i) {
            if (colors[i] == WHITE) {
                is_connected = false;
                return;
            }
        }
        is_connected = true;
    }

    void dfs_visit(int u) {
        colors[u] = GRAY;

        for (int v : adj[u]) {
            if (colors[v] == WHITE) {
                parents[v] = u;
                dfs_visit(v);
            } else if (colors[v] == GRAY && v != parents[u]) {
                is_cycled = true;
            }
        }

        colors[u] = BLACK;
    }

};

int main() {
    int n;
    cin >> n;

    Graph g(n + 1);

    int t;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> t;
            if (t == 1) { g.add_edge(i + 1, j + 1); }
        }
    }

    g.dfs(1);

    if (!g.is_cycled && g.is_connected) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
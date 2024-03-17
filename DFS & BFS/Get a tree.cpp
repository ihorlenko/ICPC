#include <iostream>
#include <climits>
#include <vector>

using namespace std;

enum Color {
    WHITE,
    GRAY,
    BLACK,
};

struct Graph {
    vector<vector<int>> list;

    Graph(int n) {
        list.resize(n);
    }

    void add_edge(int x, int y, bool directed) {
        list[x].push_back(y);

        if (!directed) {
            add_edge(y, x, true);
        }
    }

    void dfs(Graph& g_new) {
        vector<Color> colors(list.size());
        for (int i = 1; i < colors.size(); ++i) {
            colors[i] = WHITE;
        }

        for (int i = 1; i < list.size(); ++i) {
            if (colors[i] == WHITE) {
                dfs_visit(i, colors, g_new);
            }
        }
    }

    void dfs_visit(int u, vector<Color>& colors, Graph& g_new) {
        colors[u] = GRAY;

        for (int i = 0; i < list[u].size(); ++i) {
            int v = list[u][i];
            if (colors[v] == WHITE) {
                g_new.add_edge(u, v, true);
                dfs_visit(v, colors, g_new);
            }
        }

        colors[u] = BLACK;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Graph g(n + 1);
    Graph g_new(n + 1);

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        g.add_edge(x, y, false);
    }

    g.dfs(g_new);

    for (int i = 0; i < g_new.list.size(); ++i) {
        for (int j = 0; j < g_new.list[i].size(); ++j) {
            cout << i << " " << g_new.list[i][j] << endl;
        }
    }
}
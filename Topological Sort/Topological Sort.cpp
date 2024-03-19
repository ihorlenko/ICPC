#include <iostream>
#include <climits>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

enum Color {
    WHITE,
    GRAY,
    BLACK,
};

struct Graph {
    vector<vector<int>> list;
    vector<Color> colors;
    vector<int> top_sorted;
    bool contain_cycle = false;

    Graph(int n) {
        list.assign(n, {});
    }

    void add_edge(int x, int y, bool directed) {
        list[x].push_back(y);

        if (!directed) {
            add_edge(y, x, true);
        }
    }

    void dfs() {
        colors.assign(list.size(), WHITE);

        for (int i = 1; i < list.size(); ++i) {
            if (colors[i] == WHITE) {
                dfs_visit(i);
                if (contain_cycle) { return; }
            }
        }
    }

    void dfs_visit(int u) {
        colors[u] = GRAY;

        for (int i = 0; i < list[u].size(); ++i) {
            int v = list[u][i];

            if (colors[v] == WHITE) {
                dfs_visit(v);
            } else if (colors[v] == GRAY) {
                contain_cycle = true;
                return;
            }
        }

        top_sorted.push_back(u);
        colors[u] = BLACK;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Graph g(n + 1);

    int x, y;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        g.add_edge(x, y, true);
    }

    g.dfs();

    if (g.contain_cycle) {
        cout << -1;
    } else {
        for (int i = g.top_sorted.size() - 1; i > -1; --i) {
            cout << g.top_sorted[i] << " ";
        }
    }
}

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

    void dfs(int& counter) {
        vector<Color> colors(list.size());
        for (int i = 1; i < colors.size(); ++i) {
            colors[i] = WHITE;
        }

        for (int i = 1; i < list.size(); ++i) {
            if (colors[i] == WHITE) {
                dfs_visit(i, colors);
                counter++;
            }
        }
    }

    void dfs_visit(int u, vector<Color>& colors) {
        colors[u] = GRAY;

        for (int i = 0; i < list[u].size(); ++i) {
            int v = list[u][i];
            if (colors[v] == WHITE) {
                dfs_visit(v, colors);
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
            if (t == 1) {
                g.add_edge(i + 1, j + 1, true);
            }
        }
    }

    int counter = 0;
    g.dfs(counter);

    cout << counter;
}
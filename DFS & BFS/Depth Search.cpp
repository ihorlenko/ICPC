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
        list.assign(n, {});
    }

    void add_edge(int x, int y, bool directed) {
        list[x].push_back(y);

        if (!directed) {
            add_edge(y, x, true);
        }
    }

    void dfs(int start, int& nodeCount) {
        vector<Color> colors(list.size());
        for (int i = 1; i < colors.size(); ++i) {
            colors[i] = WHITE;
        }
        int time = 0;

        dfs_visit(start, colors, time);

        nodeCount = time / 2;
    }

    void dfs_visit(int u, vector<Color>& colors, int& time) {
        colors[u] = GRAY;
        time++;

        for (int i = 0; i < list[u].size(); ++i) {
            int v = list[u][i];

            if (colors[v] == WHITE) {
                dfs_visit(v, colors, time);
            }
        }

        colors[u] = BLACK;
        time++;
    }
};

int main() {
    int n, s;
    cin >> n >> s;
    Graph g(n + 1);
    int nodeCount = 0;

    int t;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> t;
            if (t == 1) { g.add_edge(i + 1, j + 1, true); }
        }
    }

    g.dfs(s, nodeCount);

    cout << nodeCount;
}
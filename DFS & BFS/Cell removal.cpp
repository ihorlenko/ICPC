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

    void dfs(int& counter, vector<int>& vertices) {
        vector<Color> colors(list.size());
        for (int i = 1; i < colors.size(); ++i) {
            colors[i] = WHITE;
        }

        for (int i = 0; i < vertices.size(); ++i) {
            int u = vertices[i];
            if (colors[u] == WHITE) {
                dfs_visit(u, colors);
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

int cellNum(int x, int y, int n) {
    return n * x + y + 1;
}

int main() {
    int m, n;
    cin >> m >> n;
    char table[m][n];
    Graph g(n * m + 1);
    vector<int> vertices;

    string t;
    for (int i = 0; i < m; ++i) {
        cin >> t;
        for (int j = 0; j < n; ++j) {
            table[i][j] = t[j];
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (table[i][j] == '#') {
                if (j + 1 < n && table[i][j + 1] == '#') {
                    g.add_edge(cellNum(i, j, n), cellNum(i, j + 1, n), true);
                }
                if (i - 1 > -1 && table[i - 1][j] == '#') {
                    g.add_edge(cellNum(i, j, n), cellNum(i - 1, j, n), true);
                }
                if (j - 1 > -1 && table[i][j - 1] == '#') {
                    g.add_edge(cellNum(i, j, n), cellNum(i, j - 1, n), true);
                }
                if (i + 1 < n && table[i + 1][j] == '#') {
                    g.add_edge(cellNum(i, j, n), cellNum(i + 1, j, n), true);
                }
                vertices.push_back(cellNum(i, j, n));
            }
        }
    }

    int counter = 0;
    g.dfs(counter, vertices);

    cout << counter;
}
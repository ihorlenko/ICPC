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

    void bfs(int start, vector<int>& d, vector<int>& p) {
        vector<Color> colors(list.size());
        for (int i = 1; i < colors.size(); ++i) {
            colors[i] = WHITE;
            d[i] = INT_MAX;
            p[i] = -1;
        }

        colors[start] = GRAY;
        d[start] = 0;
        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int i = 0; i < list[u].size(); ++i) {
                int v = list[u][i];

                if (colors[v] == WHITE) {
                    colors[v] = GRAY;
                    d[v] = d[u] + 1;
                    p[v] = u;
                    q.push(v);
                }
            }

            colors[u] = BLACK;
        }
    }
};

int cellNum(int i, int j, int n) {
    return i * n + j + 1;
}

void getCell(int& i, int& j, int cellNum, int n) {
    i = (cellNum - 1) / n;
    j = (cellNum - 1) % n;
}

int main() {
    int n;
    cin >> n;
    char table[n][n];
    Graph g(n * n + 1);
    vector<int> d(n * n + 1);
    vector<int> p(n * n + 1);

    string t;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        for (int j = 0; j < n; ++j) {
            table[i][j] = t[j];
        }
    }

    int start = -1;
    int finish = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (table[i][j] == '#') { continue; }

            if (j + 2 < n) {
                if (i - 1 > -1 && table[i - 1][j + 2] != '#') {
                    g.add_edge(cellNum(i,j,n), cellNum(i - 1,j + 2,n), true);
                }
                if (i + 1 < n && table[i + 1][j + 2] != '#') {
                    g.add_edge(cellNum(i,j,n), cellNum(i + 1, j + 2, n), true);
                }
            }
            if (i - 2 > -1) {
                if (j - 1 > -1 && table[i - 2][j - 1] != '#') {
                    g.add_edge(cellNum(i,j,n), cellNum(i - 2,j - 1,n), true);
                }
                if (j + 1 < n && table[i - 2][j + 1] != '#') {
                    g.add_edge(cellNum(i,j,n), cellNum(i - 2,j + 1,n), true);
                }
            }
            if (j - 2 > -1) {
                if (i - 1 > -1 && table[i - 1][j - 2] != '#') {
                    g.add_edge(cellNum(i,j,n), cellNum(i - 1,j - 2,n), true);
                }
                if (i + 1 < n && table[i + 1][j - 2] != '#') {
                    g.add_edge(cellNum(i,j,n), cellNum(i + 1, j - 2, n), true);
                }
            }
            if (i + 2 < n) {
                if (j - 1 > -1 && table[i + 2][j - 1] != '#') {
                    g.add_edge(cellNum(i,j,n), cellNum(i + 2,j - 1,n), true);
                }
                if (j + 1 < n && table[i + 2][j + 1] != '#') {
                    g.add_edge(cellNum(i,j,n), cellNum(i + 2,j + 1,n), true);
                }
            }

            if (table[i][j] == '@' && start == -1) {
                start = cellNum(i,j,n);
            } else if (table[i][j] == '@') {
                finish = cellNum(i,j,n);
            }
        }
    }

    g.bfs(start, d, p);

    if (d[finish] == INT_MAX) {
        cout << "Impossible";
    } else {
        vector<int> path;
        int u = finish;
        while (u != start) {
            path.push_back(u);
            u = p[u];
        }
        path.push_back(start);

        int i, j;
        for (int k = 0; k < path.size(); ++k) {
            getCell(i, j, path[k], n);
            table[i][j] = '@';
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << table[i][j];
            }
            cout << endl;
        }
    }
}
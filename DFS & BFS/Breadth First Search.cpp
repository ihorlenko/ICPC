#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

enum Color {
    WHITE,
    GRAY,
    BLACK,
};

struct Graph {
    vector<vector<int>> list;

    Graph(int n) {
        list.resize(n + 1);
    }

    void add_edge(int x, int y, bool directed) {
        list[x].push_back(y);

        if (!directed) {
            add_edge(y, x, true);
        }
    }

    void bfs(int start, vector<int> &d, vector<int> &p) {
        vector<Color> colors(list.size());
        for (int i = 0; i < colors.size(); ++i) {
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

int main() {
    int n, s, f;
    cin >> n >> s >> f;

    Graph g(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int t;
            cin >> t;
            if (t == 1) {
                g.add_edge(i + 1, j + 1, true);
            }
        }
    }

    vector<int> d(n + 1);
    vector<int> p(n + 1);

    g.bfs(s, d, p);
    if (d[f] == INT_MAX) { cout << 0; }
    else { cout << d[f]; }
}

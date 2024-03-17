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

    void dfs(vector<int>& p, bool& statement, int& loop_start, int& loop_end) {
        vector<Color> colors(list.size());
        for (int i = 1; i < colors.size(); ++i) {
            colors[i] = WHITE;
            p[i] = -1;
        }

        for (int i = 1; i < list.size(); ++i) {
            if (colors[i] == WHITE) {
                dfs_visit(i, colors,
                          p, statement,
                          loop_start, loop_end);
            }
        }
    }

    void dfs_visit(int u, vector<Color>& colors,
                   vector<int>& p, bool& statement,
                   int& loop_start, int& loop_end) {
        colors[u] = GRAY;

        for (int i = 0; i < list[u].size(); ++i) {
            int v = list[u][i];
            if (colors[v] == WHITE) {
                p[v] = u;
                dfs_visit(v, colors, p, statement, loop_start, loop_end);
            } else if (colors[v] == GRAY) {
                statement = true;
                loop_start = u;
                loop_end = v;
            }
        }

        colors[u] = BLACK;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Graph g(n + 1);
    vector<int> p(n + 1);
    bool statement = false;
    int loop_start, loop_end;
    loop_start = loop_end = -1;

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        g.add_edge(x, y, true);
    }

    g.dfs(p, statement, loop_start, loop_end);

    if (statement) {
        int node = loop_start;
        vector<int> path;
        while (node != loop_end) {
            path.push_back(node);
            node = p[node];
        }
        path.push_back(loop_end);
        cout << "YES" << endl;
        for (int i = path.size() - 1; i > -1; --i) {
            cout << path[i] << " ";
        }
    } else {
        cout << "NO";
    }

}
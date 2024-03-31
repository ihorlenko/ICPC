#include <iostream>
#include <string>
#include <climits>
#include <vector>
#include <map>

using namespace std;

enum Color {
    WHITE,
    GRAY,
    BLACK,
};

struct Graph {
    int V;
    map<string, vector<string>> adj;
    map<string, Color> colors;

    Graph(int V) {
        this->V = V;
    }

    void add_edge(string u, string v) {
        adj[u].push_back(v);
        colors[u] = WHITE;
    }

    void dfs(string u, string root, bool& is_cycled) {
        colors[u] = GRAY;

        for (const string& v : adj[u]) {
            if (colors[v] == WHITE) {
                dfs(v, root, is_cycled);
            } else if (colors[v] == GRAY && v == root) {
                is_cycled = true;
            }
        }

        colors[u] = BLACK;
    }
};

int main() {
    int n;
    cin >> n;
    Graph g(n);
    vector<string> procedures;

    string u;
    int k;
    while (n--) {

        cin >> u;
        procedures.push_back(u);

        cin >> k;

        string v;
        while (k--) {
            cin >> v;
            g.add_edge(u, v);
        }

        if (n > 0) cin >> u;
    }

    map<string, Color> colors_saved = g.colors;

    for (string proc : procedures) {
        bool is_cycled = false;
        g.dfs(proc, proc, is_cycled);
        g.colors = colors_saved;
        cout << proc << ": " << (is_cycled ? "YES" : "NO") << endl;
    }
}
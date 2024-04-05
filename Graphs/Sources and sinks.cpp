#include <iostream>
#include <vector>

using namespace std;

struct Graph {
    int V;
    vector<vector<int>> adj;
    vector<int> in_degrees;
    vector<int> out_degrees;

    Graph(int V) {
        this->V = V;
        adj.assign(V, {});
        in_degrees.assign(V, 0);
        out_degrees.assign(V, 0);
    }

    void add_edge(int x, int y) {
        adj[x].push_back(y);
        ++out_degrees[x];
        ++in_degrees[y];
    }

    vector<int> get_sources() {
        vector<int> sources;
        for (int i = 1; i < V; ++i) {
            if (in_degrees[i] == 0) sources.push_back(i);
        }

        return sources;
    }

    vector<int> get_sinks() {
        vector<int> sinks;
        for (int i = 1; i < V; ++i) {
            if (out_degrees[i] == 0) sinks.push_back(i);
        }

        return sinks;
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

    vector<int> sources = g.get_sources();
    vector<int> sinks = g.get_sinks();

    cout << sources.size() << " ";
    for (int i = 0; i < sources.size(); ++i) {
        cout << sources[i] << " ";
    }
    cout << endl;

    cout << sinks.size() << " ";
    for (int i = 0; i < sinks.size(); ++i) {
        cout << sinks[i] << " ";
    }
}
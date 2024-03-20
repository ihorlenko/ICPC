#include <iostream>
#include <climits>
#include <vector>
#include <sstream>

using namespace std;

enum Color {
    WHITE,
    GRAY,
    BLACK,
};

vector<int> p;

struct Graph {
    int V;
    vector<vector<int>> adj;
    vector<Color> colors;
    vector<int> topOrder;

    Graph(int V) {
        this->V = V;
        adj.assign(V, {});
    }

    void addEdge(int x, int y, bool directed);

    void dfs(int start, long long& total_cost);

    void dfs_visit(int u, long long& total_cost);
};

void Graph::addEdge(int x, int y, bool directed) {
    adj[x].push_back(y);

    if (!directed) {
        addEdge(y, x, true);
    }
}

void Graph::dfs(int start, long long& total_cost) {
    colors.assign(V, WHITE);
    dfs_visit(start, total_cost);
}

void Graph::dfs_visit(int u, long long& total_cost) {
    colors[u] = GRAY;

    for (int v : adj[u]) {
        if (colors[v] == WHITE) {
            colors[v] = GRAY;
            dfs_visit(v, total_cost);
        }
    }

    total_cost += p[u - 1];
    colors[u] = BLACK;
}

int main() {
    string str;
    std::getline(std::cin, str);
    istringstream iss(str);

    int cost;
    while (iss >> cost) {
        p.push_back(cost);
    }

    Graph g(p.size() + 1);

    for (int i = 0; i < p.size(); ++i) {
        getline(cin, str);

        int detail;
        istringstream iss(str);
        while (iss >> detail) {
            g.addEdge(i + 1,detail, true);
        }
    }

    long long total_cost = 0;
    g.dfs(1, total_cost);

    cout << total_cost;
}
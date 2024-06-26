//
// Created by Ihor Orlenko on 12.03.2024.
//
#include <vector>
#include <stack>
#ifndef ICPC_DFS_H
#define ICPC_DFS_H

using namespace std;

enum Color {
    WHITE,
    GRAY,
    BLACK,
};

struct Graph {
    vector<vector<int>> adj;

    Graph(int n) {
        adj.resize(n);
    }

    void add_edge(int x, int y, bool directed) {
        adj[x].push_back(y);

        if (!directed) {
            add_edge(y, x, true);
        }
    }

    void dfs() {
        vector<Color> colors(adj.size());
        for (int i = 1; i < colors.size(); ++i) {
            colors[i] = WHITE;
        }

        for (int i = 1; i < adj.size(); ++i) {
            if (colors[i] == WHITE) {
                dfs_visit(i, colors);
            }
        }
    }

    void dfs_visit(int u, vector<Color>& colors) {
        colors[u] = GRAY;

        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i];

            if (colors[v] == WHITE) {
                dfs_visit(v, colors);
            }
        }

        colors[u] = BLACK;
    }
};

#endif //ICPC_DFS_H

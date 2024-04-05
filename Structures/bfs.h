//
// Created by Ihor Orlenko on 10.03.2024.
//
#include <vector>
#include <queue>
#ifndef ICPC_BFS_H
#define ICPC_BFS_H

using namespace std;
enum Color {
    WHITE,
    GRAY,
    BLACK,
};

struct Graph {
    vector<vector<int>> adj;

    Graph(int n) {
        adj.resize(n + 1);
    }

    void add_edge(int x, int y, bool directed) {
        adj[x].push_back(y);

        if (!directed) {
            add_edge(y, x, true);
        }
    }

    void bfs(int start) {
        vector<Color> colors(adj.size());
        for (int i = 0; i < colors.size(); ++i) {
            colors[i] = WHITE;
        }

        colors[start] = GRAY;
        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < adj[u].size(); ++i) {
                int v = adj[u][i];
                if (colors[v] == WHITE) {
                    colors[v] = GRAY;
                    q.push(v);
                }
            }
            colors[u] = BLACK;
        }
    }
};

#endif //ICPC_BFS_H

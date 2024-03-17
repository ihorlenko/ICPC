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


    void dfs(int start) {
        vector<Color> colors(list.size());
        for (int i = 0; i < colors.size(); ++i) {
            colors[i] = WHITE;
        }

        stack<int> S;
        colors[start] = GRAY;
        S.push(start);

        while (!S.empty()) {
            int u = S.top();
            S.pop();

            for (int i = 0; i < list[u].size(); ++i) {
                int v = list[u][i];
                if (colors[v] == WHITE) {
                    colors[v] = GRAY;
                    S.push(v);
                }
            }
            colors[u] = BLACK;
        }
    }
};
#endif //ICPC_DFS_H

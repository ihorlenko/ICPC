#include <iostream>
#include <string>
#include <climits>
#include <cmath>
#define N 101

using namespace std;

struct Game {
    int m, n;
    int field[N][N];
    char directions[N][N];
    int memo[N][N];

    Game(int m, int n) {
        this->m = m;
        this->n = n;
        memset(field, 0, sizeof(field));

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                memo[i][j] = INT_MIN;
            }
        }
    };

    void add_grains(int row, int col, int grains) {
        field[row][col] = grains;
    }

    int maximize_grains(int row, int col) {

        if (row == 0 && col == n - 1) {
            return field[row][col];
        }
        if (memo[row][col] != INT_MIN) return memo[row][col];

        int grains;
        int max_grains = INT_MIN;
        if (col + 1 < n) {
            grains = maximize_grains(row, col + 1);
            if (grains > max_grains) {
                max_grains = grains;
                directions[row][col] = 'R';
            }
        }
        if (row - 1 > -1) {
            grains = maximize_grains(row - 1, col);
            if (grains > max_grains) {
                max_grains = grains;
                directions[row][col] = 'F';
            }
        }

        memo[row][col] = field[row][col] + max_grains;
        return field[row][col] + max_grains;
    }

    string find_route(int row, int col) {
        string route;
        while (row != 0 || col != n - 1) {
            route += directions[row][col];
            if (directions[row][col] == 'R') ++col;
            else --row;
        }
        return route;
    }
};


int main() {
    int m, n;
    cin >> m >> n;
    Game g(m, n);

    int grains;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grains;
            g.add_grains(i, j, grains);
        }
    }

    g.maximize_grains(n - 1, 0);
    cout << g.find_route(m - 1, 0);
}
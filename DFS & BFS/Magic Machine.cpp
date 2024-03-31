#include <iostream>
#include <climits>
#include <queue>
#include <vector>

using namespace std;

int op1(int x) {
    return x * 3;
}

int op2(int x) {
    int x_copy = x;
    int sum = 0;

    while (x != 0) {
        sum += x % 10;
        x /= 10;
    }

    return x_copy + sum;
}

int op3(int x) {
    return x - 2;
}

bool is_valid(int x) {
    return 0 <= x and x <= 9999;
}

int main() {
    int a, b;
    cin >> a >> b;

    queue<int> q;
    vector<bool> visited(10000, false);
    vector<int> dist(10000, INT_MAX);

    q.push(a);
    visited[a] = true;
    dist[a] = 0;

    int res1, res2, res3;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        res1 = op1(x);
        res2 = op2(x);
        res3 = op3(x);

        if (is_valid(res1) && !visited[res1]) {
            q.push(res1);
            visited[res1] = true;
            dist[res1] = dist[x] + 1;
            if (res1 == b) break;
        }

        if (is_valid(res2) && !visited[res2]) {
            q.push(res2);
            visited[res2] = true;
            dist[res2] = dist[x] + 1;
            if (res2 == b) break;
        }

        if (is_valid(res3) && !visited[res3]) {
            q.push(res3);
            visited[res3] = true;
            dist[res3] = dist[x] + 1;
            if (res3 == b) break;
        }
    }

    cout << dist[b];
}
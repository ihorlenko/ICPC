#include <iostream>

using namespace std;
int memo[126000];

int binomial_coefficient(int n, int k) {
    int index = n * (n + 1) / 2 + k + 1;
    if (k == 0 || n == k) {
        memo[index] = 1;
        return 1;
    }
    if (memo[index] != 0) return memo[index];
    memo[index] = (binomial_coefficient(n - 1, k) + binomial_coefficient(n - 1, k - 1)) % 9929;
    return memo[index];
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << binomial_coefficient(n, k);
}
#include <iostream>
#define ull unsigned long long

using namespace std;

ull binomial_coefficient(int n, int k) {
    if (k > n - k) k = n - k;
    long long result = 1;

    for (int i = 0; i < k; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }

    return result;
}

int main() {
    int n, k;
    cin >> k >> n;

    ull res = 0;

    for (int i = k - 1; i > -1; --i) {
        res += binomial_coefficient(n - 1, i) * binomial_coefficient(k, k - i - 1);
    }

    cout << res;
}
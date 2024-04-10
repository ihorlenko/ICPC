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
    int k, n;
    cin >> k >> n;
    cout << binomial_coefficient(n - 1, k - 1);
}
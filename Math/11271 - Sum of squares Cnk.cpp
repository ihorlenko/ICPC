#include <iostream>

using namespace std;

long long binomial_coefficient(int n, int k) {
    if (k > n - k) k = n - k;
    long long result = 1;

    for (int i = 0; i < k; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    cout <<  binomial_coefficient(2 * n, n);
}
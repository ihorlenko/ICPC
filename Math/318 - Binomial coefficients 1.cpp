#include <iostream>
#include <cmath>
#include <map>
#define ull unsigned long long
using namespace std;

map<pair<ull, ull>, ull> memo;

ull gcd(ull a, ull b) {
    while (a != 0 && b != 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }

    return a + b;
}

ull binomial_coefficient(ull n, ull k) {
    if (k > n - k) k = n - k;
    ull result = 1;

    if (memo.find({n, k}) != memo.end()) return memo[{n, k}];

    for (int i = 0; i < k; ++i) {
        ull div = gcd(result, i + 1);
        ull tmp = (n - i) / ((i + 1) / div);
        result = result / div * tmp;
    }

    memo[{n, k}] = result;
    return result;
}

int main() {
    int t;
    cin >> t;
    ull n, k;
    while (t--) {
        cin >> n >> k;
        cout << binomial_coefficient(n, k) << endl;
    }
}
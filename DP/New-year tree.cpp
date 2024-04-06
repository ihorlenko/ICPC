#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if (k == 1) { cout << -1; }
    else if (k == 2 && n % 2 != 0) { cout << -1; }
    else {
        cout << static_cast<int>(pow(k - 1, n - 2)) * k;
    }
}
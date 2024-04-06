#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long cnt = 0;
    long long p = 5;
    int i = 1;
    while (i != 14) {
        cnt += n / p;
        p = static_cast<int>(pow(5, ++i));
    }

    cout << cnt;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    int n, m, k, h;
    while (t--) {
        cin >> n >> m >> k >> h;
        bool statement = true;

        if (n < k || m < k) statement = false;

        if (!(2 * k <= n + m && n + m <= h * k)) statement = false;

        if (statement) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

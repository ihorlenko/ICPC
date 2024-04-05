#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int matches = 0;

    int i = 0;
    while ((i + 1) * (i + 1) * (i + 1) <= n) {
        i++;
    }
    matches += 3 * i * (i + 1) * (i + 1);
    n %= i * i * i;

    int j = 0;
    while (i * (j + 1) <= n) {
        j++;
    }
    matches += j * (i + 1) * (i + 1) + 2 * i * j * (i + 1);
    n %= i * i;

    int k = 0;

}

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

void eratho_sieve(vector<bool>& isPrime) {
    isPrime[0] = false;
    isPrime[1] = false;
    int n = isPrime.size();

    for (int p = 2; p * p < n; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i < n; i += p)
                isPrime[i] = false;
        }
    }
}

int main() {
    int N;
    string num;
    int number_of_digits;
    cin >> N >> num;
    number_of_digits = num.size();
    int p1 = stoi(num);

    vector<bool> isPrime(static_cast<int>(pow(10, number_of_digits)), true);
    eratho_sieve(isPrime);

    int i = 1;
    while (p1 + i < isPrime.size() && !isPrime[p1 + i]) {
        ++i;
    }

    if (N - 2 < i || p1 + i >= isPrime.size()) {
        cout << -1;
    } else {
        cout << i - 1;
    }
}

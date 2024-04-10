#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <bitset>
#include <algorithm>
#define ull unsigned long long

using namespace std;

int main() {
    ull n;
    cin >> n;
    bitset<64> bin_n(n);
    string bin_str = bin_n.to_string();
    bin_str.erase(0, bin_str.find_first_not_of('0'));

    int length = bin_str.size();
    stack<int> zeroBitPairs;
    bool zeroizationIsNeeded = false;
    for (int i = 0; i < (length / 2 + length % 2); ++i) {
        int pair = length - i - 1;
        if (bin_str[i] == '0') {
            zeroBitPairs.push(i);
            if (bin_str[pair] == '1') zeroizationIsNeeded = true;
        }
    }
    if (zeroBitPairs.empty()) {
        for (int i = length / 2; i < length; ++i) {
            bin_str[i] = '1';
        }
    } else if (zeroizationIsNeeded) {
        int lastIndex = zeroBitPairs.top();
        if (bin_str[length - lastIndex - 1] != '0')  {
            bin_str[lastIndex] = '1';
            bin_str[length - lastIndex - 1] = '1';
        }
        for (int i = 0; i < lastIndex; ++i) {
            int pair = length - i - 1;
            bin_str[pair] = bin_str[i];
        }
        for (int i = lastIndex + 1; i < (length / 2 + length % 2); ++i) {
            int pair = length - i - 1;
            bin_str[i] = '0';
            bin_str[pair] = '0';
        }
    } else {
        for (int i = 0; i < (length / 2 + length % 2); ++i) {
            int pair = length - i - 1;
            if (bin_str[i] == '1') bin_str[pair] = '1';
        }
    }

    cout << bitset<16>(n) << " " << bitset<16>(1057) << " " << bitset<16>(1025) << endl;
    cout << bitset<64>(bin_str).to_ullong();
}

// 1034
// 134234
// 12718763
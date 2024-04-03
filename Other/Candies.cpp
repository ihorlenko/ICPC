#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> bags(N);
    vector<int> p2(N);
    vector<int> p4(N);

    for (int i = 0; i < N; ++i) {
        cin >> bags[i];
        if (i > 0) {
            p2[i] = bags[i] + bags[i - 1];
        }
        if (i > 2) {
            p4[i] = bags[i] + bags[i - 1] + bags[i - 2] + bags[i - 3];
        }
    }

    int maxx1 = -1;
    int maxx2 = -1;
    int maxx1_i;

    for (int i = 1; i < N; ++i) {
        if (p2[i] > maxx1) {
            maxx1 = p2[i];
            maxx1_i = i;
        }
    }
    for (int i = 1; i < N; ++i) {
        if (abs(i - maxx1_i) > 1 && p2[i] > maxx2) {
            maxx2 = p2[i];
        }
    }

    for (int i = 3; i < N; ++i) {
        if (p4[i] > (maxx1 + maxx2)) {
            maxx1 = p4[i];
            maxx2 = 0;
        }
    }

    cout << maxx1 + maxx2;
}
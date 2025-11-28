#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int N;
    short num;

    int C[10001] = {
        0};
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> num;
        C[num]++;
    }
    for (int i = 1; i <= 10000; ++i) {
        C[i] = C[i] + C[i - 1];
    }

    for (int i = 0; i < 10000; ++i) {
        for (int j = C[i]; j < C[i + 1]; ++j) {
            cout << i + 1 << "\n";
        }
    }

    return 0;
}
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int combination(int N, int K) { /* 동적계획 이항계수 구하기 */
    vector<vector<int>> bin(N + 1, vector<int>(K + 1));

    bin[1][0] = 1;
    bin[1][1] = 1;

    for (int i = 2; i <= N; ++i) {
        bin[i][0] = 1;
        for (int j = 1; j <= ((K < i) ? K : i); ++j) {
            bin[i][j] = bin[i - 1][j - 1] + bin[i - 1][j];
        }
    }

    return bin[N][K];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int a, b;
    for (int i = 0; i < N; ++i) {
        cin >> a >> b;
        cout << combination(max(a, b), min(a, b)) << "\n";
    }

    return 0;
}
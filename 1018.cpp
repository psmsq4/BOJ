#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    char kernel1[8][8] = {
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    };
    char kernel2[8][8] = {
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    };
    int N, M;
    cin >> N >> M;

    vector<vector<char>> map(N, vector<char>(M));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> map[i][j];
        }
    }

    int min = INT32_MAX;

    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++) {
            int cnt_kernel1 = 0;
            int cnt_kernel2 = 0;
            for (int n = 0; n < 8; ++n) {
                for (int m = 0; m < 8; ++m) {
                    if (kernel1[n][m] != map[i + n][j + m]) {
                        cnt_kernel1++;
                    }
                    if (kernel2[n][m] != map[i + n][j + m]) {
                        cnt_kernel2++;
                    }
                }
            }
            int cnt = cnt_kernel1 < cnt_kernel2 ? cnt_kernel1 : cnt_kernel2;
            min = cnt < min ? cnt : min;
        }
    }

    cout << min << "\n";

    return 0;
}
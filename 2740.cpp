#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M;
    vector<vector<int>> M1(N, vector<int>(M));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> M1[i][j];
        }
    }

    cin >> M >> K;
    vector<vector<int>> M2(M, vector<int>(K));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < K; ++j) {
            cin >> M2[i][j];
        }
    }

    vector<vector<int>> R(N, vector<int>(K));
    for (int n = 0; n < N; ++n) {
        for (int m = 0; m < M; ++m) {
            for (int k = 0; k < K; ++k) {
                R[n][k] += M1[n][m] * M2[m][k];
            }
        }
    }

    for (int n = 0; n < N; ++n) {
        for (int k = 0; k < K; ++k) {
            cout << R[n][k] << " ";
        }
        cout << "\n";
    }

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> pow2(vector<vector<long long>> M, int N, int mod) {
    vector<vector<long long>> R(N, vector<long long>(N));
    for (int n = 0; n < N; ++n) {
        for (int m = 0; m < N; ++m) {
            for (int k = 0; k < N; ++k) {
                R[n][k] += (M[n][m] % mod) * (M[m][k] % mod) % mod;
            }
        }
    }

    return R;
}

vector<vector<long long>> calc(vector<vector<long long>> M1, vector<vector<long long>> M2, int N, int mod) {
    vector<vector<long long>> R(N, vector<long long>(N));
    for (int n = 0; n < N; ++n) {
        for (int m = 0; m < N; ++m) {
            for (int k = 0; k < N; ++k) {
                R[n][k] += (M1[n][m] % mod) * (M2[m][k] % mod) % mod;
            }
        }
    }

    return R;
}

vector<vector<long long>> dfs(vector<vector<long long>> M1, long long B, long long mod, int N) {
    if (B == 1) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                M1[i][j] %= mod;
            }
        }

        return M1;
    }

    vector<vector<long long>> half = dfs(M1, B / 2, mod, N);
    if (B % 2 == 1) {
        return calc(pow2(half, N, mod), M1, N, mod);
    } else {
        return pow2(half, N, mod);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N, B;
    cin >> N >> B;
    vector<vector<long long>> M1(N, vector<long long>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> M1[i][j];
        }
    }

    vector<vector<long long>> R(N, vector<long long>(N));
    R = dfs(M1, B, 1000, N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            R[i][j] %= 1000;
        }
    }

    for (int n = 0; n < N; ++n) {
        for (int k = 0; k < N; ++k) {
            cout << R[n][k] << " ";
        }
        cout << "\n";
    }

    return 0;
}
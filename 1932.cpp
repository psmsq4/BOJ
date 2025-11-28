#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<vector<int>> costs(N, vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            cin >> costs[i][j];
        }
    }

    vector<vector<int>> dp(N, vector<int>(N));
    dp[0][0] = costs[0][0];

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            int stt = j - 1 > 0 ? j - 1 : 0;
            int end = j > i ? i : j;
            dp[i][j] = max(dp[i - 1][stt], dp[i - 1][end]) + costs[i][j];
        }
    }

    int MAX = INT32_MIN;
    for (int i = 0; i < N; ++i) {
        MAX = max(MAX, dp[N - 1][i]);
    }

    cout << MAX << "\n";

    return 0;
}
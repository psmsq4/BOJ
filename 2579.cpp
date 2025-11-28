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

    vector<int> stair_scores(N);
    for (int i = 0; i < N; ++i) {
        cin >> stair_scores[i];
    }

    vector<vector<int>> dp(N, vector<int>(3));
    dp[0][0] = 0;
    dp[0][1] = stair_scores[0];

    for (int i = 1; i < N; ++i) {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = dp[i - 1][0] + stair_scores[i];
        dp[i][2] = dp[i - 1][1] + stair_scores[i];
    }

    cout << max(dp[N - 1][1], dp[N - 1][2]) << "\n";

    return 0;
}
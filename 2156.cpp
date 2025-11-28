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

    vector<int> wines(N);
    for (int i = 0; i < N; ++i) {
        cin >> wines[i];
    }

    vector<vector<int>> dp(N, vector<int>(3));
    dp[0][0] = 0;
    dp[0][1] = wines[0];

    /* Type 0: 안 넣는 유형 (이전 Type1과 Type0으로부터 기인)
     * Type 1: 넣어도 되고 안 넣어도 되는 유형 (이전 Type1과 Type0으로부터 기인) (연속된 수행이 하나 뿐인 경우)
     * Type 2: 다음 번에는 무조건 안 넣어야 하는 유형(이전 Type1로부터 기인) */
    for (int i = 1; i < N; ++i) {
        dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
        dp[i][1] = dp[i - 1][0] + wines[i];
        dp[i][2] = dp[i - 1][1] + wines[i];
    }

    cout << max(max(dp[N - 1][1], dp[N - 1][2]), dp[N - 1][0]) << "\n";

    return 0;
}
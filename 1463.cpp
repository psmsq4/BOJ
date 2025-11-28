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

    vector<int> dp(N + 1, 0);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i <= N; ++i) {
        // if (i % 3 == 0 && i % 2 == 0) {
        //     dp[i] = min(min((dp[i / 3] + 1), (dp[i / 2] + 1)), (dp[i - 1] + 1));
        // } else if (i % 3 == 0) {
        //     dp[i] = min((dp[i / 3] + 1), (dp[i - 1] + 1));
        // } else if (i % 2 == 0) {
        //     dp[i] = min((dp[i / 2] + 1), (dp[i - 1] + 1));
        // } else {
        //     dp[i] = (dp[i - 1] + 1);
        // }
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2] + 1);

        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3] + 1);
    }

    cout << dp[N] << "\n";

    return 0;
}
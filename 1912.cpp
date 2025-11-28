#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> nums(N + 1);
    vector<vector<int>> dp(2, vector<int>(N + 1));

    int num;
    int MAX = INT32_MIN;
    for (int i = 1; i <= N; ++i) {
        cin >> nums[i];
        // dp[0][i] = nums[i];
        // if (MAX < nums[i])
        //     MAX = nums[i];
    }

    MAX = nums[1];
    int currentSum = nums[1];

    for (int i = 2; i <= N; ++i) {
        /* Kadane 알고리즘 */
        currentSum = max(nums[i], currentSum + nums[i]);
        MAX = max(MAX, currentSum);
    }

    // for (int i = 1; i < N; ++i) {
    //     for (int j = 1; j <= N - i; ++j) {
    //         /* dp[2][1] = dp[1][1] + nums[2]
    //          * dp[3][1] = dp[2][1] + nums[3]
    //          * dp[3][2] = dp[2][2] + nums[4] */
    //         dp[i % 2][j] = dp[(i - 1) % 2][j] + nums[i + j];
    //         // cout << dp[(i - 1) % 2][j] << " + " << nums[i + j] << " = " << dp[i % 2][j] << "\n";
    //         if (MAX < dp[i % 2][j])
    //             MAX = dp[i % 2][j];
    //     }
    // }

    cout << MAX << "\n";

    return 0;
}
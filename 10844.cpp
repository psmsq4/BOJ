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

    vector<vector<long long>> dp(N + 1, vector<long long>(10));
    for (int i = 1; i <= 9; ++i) {
        dp[1][i] = 1;
    }

    for (int row = 2; row <= N; ++row) {
        for (int col = 1; col <= 8; ++col) {
            dp[row][col] = (dp[row - 1][col - 1] + dp[row - 1][col + 1]) % 1'000'000'000;
        }
        dp[row][0] = dp[row - 1][1] % 1'000'000'000;
        dp[row][9] = dp[row - 1][8] % 1'000'000'000;
    }

    long long sum = 0;
    for (int col = 0; col <= 9; ++col) {
        sum = (sum + dp[N][col]) % 1'000'000'000;
    }

    cout << sum << "\n";

    return 0;
}
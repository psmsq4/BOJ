#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    cin >> a >> b;

    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    cout << "  ";
    for (int j = 0; j < m; j++) {
        cout << b[j] << " ";
    }
    cout << "\n";
    for (int i = 1; i <= n; i++) {
        cout << a[i - 1] << " ";
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }

    cout << dp[n][m] << "\n";

    /*
        i) A A A B B A
        j) B B A A A A
            B B A A A A
          0 0 0 0 0 0 0
        A 0 0 0 1 1 1 1
        A 0 0 0 1 2 2 2
        A 0 0 0 1 2 3 3
        B 0 1 1 1 2 3 3
        B 0 1 2 2 2 3 3
        A 0 1 2 3 3 3 4
        현재 i를 기준으로 j와
            1) 매칭이 됐을 때
                -> 현재 비교 중인 i 바로 이전(i - 1) && j와 매칭되기 바로 직전 (j - 1)의 수열 길이 + 1
            2) 매칭이 안 됐을 때
                -> 현재 비교 중인 i 바로 이전(i - 1) 기준 최장 수열 길이와 현재 비교 중인 i의 바로 직전 j (j - 1)의 수열 길이 중 최대값
                -> 즉, i, j 위치값 기준 가능한 후보는 두 가지로 수렴하는 것을 알 수 있음.
    */
}

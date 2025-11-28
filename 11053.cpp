/* 실패한 아이디어 */
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> nums(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    /* index 0: 현재 최적해 (pair<연속 개수, 마지막 숫자>)
     * index 1: 최적해 후보 (pair<연속 개수, 마지막 숫자>) */
    vector<vector<pair<int, int>>> dp(N, vector<pair<int, int>>(2));
    dp[0][0].first = 1;
    dp[0][0].second = nums[0];
    /* 후보는 아직 없다. */
    dp[0][1] = {0, 0};

    /* dp 알고리즘 시작*/
    for (int i = 1; i < N; ++i) {
        /* 현재 최적해보다 현재 수열값이 크다면 현재 최적해를 갱신한다. */
        if (dp[i - 1][0].second < nums[i]) {
            dp[i][0].first = dp[i - 1][0].first + 1;
            dp[i][0].second = nums[i];

            dp[i][1].first = dp[i - 1][1].first + 1;
            dp[i][1].second = nums[i];
        } else {
            /* 만약, 현재 최적해보다 현재 수열값이 작다면 후보 최적해에 대한 작업을 수행한다. */
            /* 현재 최적해는 이전 최적해로 일단 유지한다. */
            dp[i][0] = dp[i - 1][0];
            /* 그리고, 후보 최적해를 갱신한다.
             * 갱신 조건은 다음과 같다.
             * - 이전 후보 최적해의 마지막 값보다 현재 수열값이 클 것.
             * - otherwise, 후보 최적해는 초기화. */
            if (dp[i - 1][1].second < nums[i]) {
                dp[i][1].first = dp[i - 1][1].first + 1;
                dp[i][1].second = nums[i];
            } else {
                dp[i][1].first = 1;
                dp[i][1].second = nums[i];
            }

            /* 후보 최적해가 현재 최적해를 넘어섰다면, 현재 최적해를 후보 최적해로 교체한다. */
            if (dp[i][0].first < dp[i][1].first) {
                dp[i][0] = dp[i][1];
            }
        }
    }

    cout << dp[N - 1][0].first << "\n";
    for (int i = 0; i < N; ++i) {
        cout << "dp[" << i << "][0]: {" << dp[i][0].first << ", " << dp[i][0].second << "} ";
        cout << "dp[" << i << "][1]: {" << dp[i][1].first << ", " << dp[i][1].second << "}\n";
    }

    return 0;
}
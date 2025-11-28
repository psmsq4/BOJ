#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> series(N + 1);
    for (int i = 1; i <= N; ++i)
        cin >> series[i];

    int stt, end;
    int sum = 0;

    vector<map<int, int>> dp(N + 1);

    for (int i = 0; i < M; ++i) {
        cin >> stt >> end;

        auto iter = dp[stt].lower_bound(end);
        if (iter == dp[stt].end()) {
            if (dp[stt].size() > 0) {
                iter = --iter;
                sum = (*iter).second;
                for (int j = (*iter).first + 1; j <= end; ++j)
                    sum += series[j];

                dp[stt][end] = sum;
            } else {
                for (int j = stt; j <= end; ++j)
                    sum += series[j];

                dp[stt][end] = sum;
            }
        } else {
            int saved_end = (*iter).first;
            if (saved_end == end)
                sum = (*iter).second;
            else if (end < saved_end) {
                iter = --iter;
                int bak_saved_end = saved_end;
                saved_end = (*iter).first;
                /* 그대로 일때 처음부터 다시 계산 */
                if (bak_saved_end == saved_end || (*iter).second == 0) {
                    for (int j = stt; j <= end; ++j)
                        sum += series[j];

                    dp[stt][end] = sum;
                } else { /* 나머지 경우, saved_end < end인 경우밖에 없음. */
                    sum = (*iter).second;
                    for (int j = saved_end + 1; j <= end; ++j)
                        sum += series[j];

                    dp[stt][end] = sum;
                }
            }
        }
        cout << sum << "\n";
        sum = 0;
    }
    /*
        vector[1][1]
        vector[1][5]

        vector[1][2] = vector[1][1] + series[2]
        vector[1][3] = vector[1][1] + series[2] + series[3]
        vector<map<int, int>> dp;
        dp[1] : map<int, int>
        dp[1]: {map[1], map[5]}
        dp[1][1] : map[1] : sum(1, 1)
        dp[1][5] : map[5] : sum(1, 5)
        dp[1][3]을 조회했을 때 dp[1][1]을 얻을 수 있는 방법?
        map은 정렬된 상태로 존재.
        -> binary search 사용?

    */

    return 0;
}
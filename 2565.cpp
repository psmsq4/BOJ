#include <iostream>
#include <map>
#include <vector>

using namespace std;
/* 첫 번째 전봇대는 오름차순인데 연결된 두 번째 전봇대에서는 내림차순이면 교차됨.
 * 또는 내림차순이다가 반대편에서 오름차순이면 교차됨.
 * 오름차순 쌍 vs 내림차순 쌍 두 개 중 작은 것을 제거하는게 정답일 듯.
 * 첫 번째 전봇대의 번호를 인덱스로 하고 두 번째 전봇대의 번호를 값으로 하는 수열
 * 8 -> 2 -> 9 -> 1 -> 4 -> 6 -> 7 -> 10
 * 여기서 가장 긴 증가하는 수열: 2(1) -> 4 -> 6 -> 7 -> 10
 * 이러면 사실 상 첫 번째 전봇대 정보는 필요없다.  */
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    map<int, int> LS;
    int idx, value;
    for (int i = 0; i < N; ++i) {
        cin >> idx >> value;
        LS[idx] = value;
    }

    vector<int> dp;
    for (auto line : LS) {
        auto iter = lower_bound(dp.begin(), dp.end(), line.second);
        if (iter == dp.end())
            dp.push_back(line.second);
        else
            *iter = line.second;
    }
    // for (auto num : dp) {
    //     cout << "LS[" << num.first << "] = " << num.second << " ";
    //     cout << num << " ";
    // }
    // cout << "\n";

    cout << N - dp.size()
         << "\n";

    return 0;
}
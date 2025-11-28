#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int>> meetings(N);
    for (int i = 0; i < N; ++i) {
        cin >> meetings[i].first >> meetings[i].second; // start, end
    }

    // 종료시간 기준으로 정렬, 종료시간이 같으면 시작시간 기준
    sort(meetings.begin(), meetings.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    });

    int count = 0;
    int last_end = 0;

    for (const auto &meeting : meetings) {
        if (meeting.first >= last_end) { // 시작시간이 마지막 종료시간보다 크거나 같으면
            count++;
            last_end = meeting.second; // 종료시간 업데이트
        }
    }

    cout << count << "\n";

    return 0;
}
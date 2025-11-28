#include <deque>
#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    deque<pair<int, int>> dq;
    int txt;
    for (int i = 0; i < N; ++i) {
        cin >> txt;
        dq.push_back({i + 1, txt});
    }

    cout << dq.front().first << " ";
    txt = dq.front().second;

    while (N >= 2) {
        if (txt > 0) {
            dq.erase(dq.begin());
            N--;
            /* 풍선을 터트리면 +1 효과 발생
             * 풍선을 터트리고 txt가 양수이면 txt - 1 만큼 회전하면 목표 회전 횟수 충족됨. */
            for (int i = 0; i < (txt)-1; ++i) {
                dq.push_back(dq.front());
                dq.pop_front();
            }

            cout << dq.front().first << " ";
            txt = dq.front().second;
        } else {
            dq.erase(dq.begin());
            N--;
            /* 풍선을 터트리면 +1 효과 발생
             * 풍선을 터트리고 txt가 음수이면 직후 회전 시 -1
             * 즉, 회전 횟수는 abs(txt)만큼 채워야 함. */
            for (int i = 0; i < abs(txt); ++i) {
                dq.push_front(dq.back());
                dq.pop_back();
            }

            cout << dq.front().first << " ";
            txt = dq.front().second;
        }
    }
    cout << "\n";

    return 0;
}
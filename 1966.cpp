#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_num;
    cin >> test_num;

    for (int t = 0; t < test_num; ++t) {
        int N, M;
        cin >> N >> M;

        queue<pair<int, bool>> q;
        priority_queue<int> pq;
        pair<int, bool> target;
        pair<int, bool> input;
        for (int i = 0; i < N; ++i) {
            cin >> input.first;
            input.second = (i == M) ? 1 : 0;

            q.push(input);
            pq.push(input.first);

            if (i == M)
                target = input;
        }

        int cnt = 0;
        while (true) {
            if (pq.top() == target.first) {
                while (pq.top() != q.front().first) {
                    auto f = q.front();
                    q.pop();
                    q.push(f);
                }

                cnt++;
                if (q.front().second) {
                    break;
                } else {
                    q.pop();
                }
                continue;
            }
            if (pq.top() > q.front().first) {
                auto f = q.front();
                q.pop();
                q.push(f);
            } else if (pq.top() == q.front().first) {
                q.pop();
                pq.pop();
                cnt++;
            }
        }
        cout << cnt << "\n";
    }

    /*
    1
    10 3
    1 2 1 3 3 4 4 5 8 1
    5

    2 1 3 3+ 4 4 5 8 1 1
    1 3 3+ 4 4 5 8 1 1 2
    3 3+ 4 4 5 8 1 1 2 1
    3+ 4 4 5 8 1 1 2 1 3
    4 4 5 8 1 1 2 1 3 3+
    4 5 8 1 1 2 1 3 3+ 4
    5 8 1 1 2 1 3 3+ 4 4
    8 1 1 2 1 3 3+ 4 4 5
    1 1 2 1 3 3+ 4 4 5
    1 2 1 3 3+ 4 4 5 1
    2 1 3 3+ 4 4 5 1 1
    1 3 3+ 4 4 5 1 1 2
    3 3+ 4 4 5 1 1 2 1
    3+ 4 4 5 1 1 2 1 3
    4 4 5 1 1 2 1 3 3+
    4 5 1 1 2 1 3 3+ 4
    5 1 1 2 1 3 3+ 4 4
    1 1 2 1 3 3+ 4 4
    1 2 1 3 3+ 4 4 1
    2 1 3 3+ 4 4 1 1
    1 3 3+ 4 4 1 1 2
    3 3+ 4 4 1 1 2 1
    3+ 4 4 1 1 2 1 3
    4 4 1 1 2 1 3 3+
    4 1 1 2 1 3 3+
    1 1 2 1 3 3+
    1 2 1 3 3+ 1
    2 1 3 3+ 1 1
    1 3 3+ 1 1 2
    3 3+ 1 1 2 1
    3+ 1 1 2 1
    1 1 2 1
    */

    return 0;
}
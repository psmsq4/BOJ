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

    int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

    for (int t = 0; t < test_num; ++t) {
        int I;
        cin >> I;
        pair<int, int> from, to;

        cin >> from.first >> from.second;
        cin >> to.first >> to.second;

        queue<pair<int, int>> q;
        q.push(from);

        vector<vector<int>> tracked(I, vector<int>(I));
        tracked[from.first][from.second] = 1; // Trick. 0부터 시작하면 Queue에 계속 들어가 쓸데없이 재탐색할 것임.

        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();

            if (curr == to)
                break;

            for (int i = 0; i < 8; ++i) {
                if (curr.first + dx[i] >= 0 && curr.first + dx[i] < I && curr.second + dy[i] >= 0 && curr.second + dy[i] < I && !tracked[curr.first + dx[i]][curr.second + dy[i]]) {
                    tracked[curr.first + dx[i]][curr.second + dy[i]] = tracked[curr.first][curr.second] + 1;
                    q.push({curr.first + dx[i], curr.second + dy[i]});
                }
            }
        }

        cout << tracked[to.first][to.second] - 1 << "\n";
    }

    return 0;
}
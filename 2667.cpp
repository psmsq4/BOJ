#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

pair<int, int> is_all_true(vector<vector<bool>> &bitset) {
    for (int i = 0; i < bitset.size(); ++i) {
        for (int j = 0; j < bitset[i].size(); ++j) {
            if (!bitset[i][j])
                return make_pair(i, j);
        }
    }

    return make_pair(-1, -1);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> graph(N, vector<int>(N));
    vector<vector<bool>> tracking(N, vector<bool>(N));
    string line;

    for (int i = 0; i < N; ++i) {
        cin >> line;
        for (int j = 0; j < N; ++j) {
            graph[i][j] = line[j] - '0';
        }
    }
    queue<pair<int, int>> bfs;
    vector<int> ans;
    int group_cnt = 0;

    while (true) {
        pair<int, int> non_track_coord = is_all_true(tracking);

        if (non_track_coord == make_pair(-1, -1))
            break;

        bfs.push(non_track_coord);
        tracking[non_track_coord.first][non_track_coord.second] = true;

        bool is_home = false;
        int house_cnt = 0;
        while (!bfs.empty()) {
            auto coord = bfs.front();
            bfs.pop();

            if (graph[coord.first][coord.second] == 0)
                continue;

            /* 처음부터 0이면 아예 셈에 들어가지도 않는다. */
            house_cnt++;

            if (coord.first - 1 >= 0 && !tracking[coord.first - 1][coord.second]) {
                tracking[coord.first - 1][coord.second] = true;
                bfs.push(make_pair(coord.first - 1, coord.second));
            }
            if (coord.first + 1 < N && !tracking[coord.first + 1][coord.second]) {
                tracking[coord.first + 1][coord.second] = true;
                bfs.push(make_pair(coord.first + 1, coord.second));
            }
            if (coord.second - 1 >= 0 && !tracking[coord.first][coord.second - 1]) {
                tracking[coord.first][coord.second - 1] = true;
                bfs.push(make_pair(coord.first, coord.second - 1));
            }
            if (coord.second + 1 < N && !tracking[coord.first][coord.second + 1]) {
                tracking[coord.first][coord.second + 1] = true;
                bfs.push(make_pair(coord.first, coord.second + 1));
            }
            /* 처음부터 0이면 위 조건에 의한 continue로 false를 유지하며, 최초 1이 한 번이라도 나와야 true가 된다. */
            is_home = true;
        }

        /* 유효한 집이 하나라도 있어야 실행 */
        if (is_home) {
            group_cnt++;
            ans.push_back(house_cnt);
        }
    }

    sort(ans.begin(), ans.end());

    cout << group_cnt << "\n";
    for (auto a : ans) {
        cout << a << "\n";
    }

    return 0;
}
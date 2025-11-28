#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

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
    int house_cnt = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (graph[i][j] == 1 && !tracking[i][j]) {
                bfs.push(make_pair(i, j));
                tracking[i][j] = true;
                group_cnt++;

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
                }

                ans.push_back(house_cnt);
                house_cnt = 0;
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << group_cnt << "\n";
    for (auto a : ans) {
        cout << a << "\n";
    }

    return 0;
}
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
        int N, M, K;
        cin >> M >> N >> K;
        /* M : 가로 길이
         * N : 세로 길이 */

        vector<vector<int>> graph(N, vector<int>(M));
        vector<vector<bool>> tracking(N, vector<bool>(M));

        int r, c;
        for (int i = 0; i < K; ++i) {
            cin >> c >> r;
            graph[r][c] = 1;
        }
        queue<pair<int, int>> bfs;
        int group_cnt = 0;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (graph[i][j] == 1 && !tracking[i][j]) {
                    bfs.push(make_pair(i, j));
                    tracking[i][j] = true;
                    group_cnt++;

                    while (!bfs.empty()) {
                        auto coord = bfs.front();
                        bfs.pop();

                        if (graph[coord.first][coord.second] == 0)
                            continue;

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
                        if (coord.second + 1 < M && !tracking[coord.first][coord.second + 1]) {
                            tracking[coord.first][coord.second + 1] = true;
                            bfs.push(make_pair(coord.first, coord.second + 1));
                        }
                    }
                }
            }
        }

        cout << group_cnt << "\n";
    }

    return 0;
}
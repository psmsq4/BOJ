#include <climits>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

int N, M;

void bfs(vector<vector<short>> &graph, vector<vector<int>> &ans, vector<vector<bool>> &tracking, pair<int, int> center) {
    queue<pair<int, int>> works;

    works.push(center);
    tracking[center.first][center.second] = true;
    ans[center.first][center.second] = 0;

    /* 현재 최적값을 다음 루트로 전파시키는 것이 좋다.
     * 현재 최적값을 현재 설정하는 것은 4방향을 모두 탐색해야 하고 최소값을 찾아야 하므로 좋지 않다. */
    while (!works.empty()) {
        pair<int, int> curr = works.front();
        works.pop();

        if (curr.first - 1 >= 0) {
            if (!tracking[curr.first - 1][curr.second] && graph[curr.first - 1][curr.second] != 0) {
                tracking[curr.first - 1][curr.second] = true;
                ans[curr.first - 1][curr.second] = ans[curr.first][curr.second] + 1;
                works.push(make_pair(curr.first - 1, curr.second));
            }
        }
        if (curr.first + 1 < N) {
            if (!tracking[curr.first + 1][curr.second] && graph[curr.first + 1][curr.second] != 0) {
                tracking[curr.first + 1][curr.second] = true;
                ans[curr.first + 1][curr.second] = ans[curr.first][curr.second] + 1;
                works.push(make_pair(curr.first + 1, curr.second));
            }
        }
        if (curr.second - 1 >= 0) {
            if (!tracking[curr.first][curr.second - 1] && graph[curr.first][curr.second - 1] != 0) {
                tracking[curr.first][curr.second - 1] = true;
                ans[curr.first][curr.second - 1] = ans[curr.first][curr.second] + 1;
                works.push(make_pair(curr.first, curr.second - 1));
            }
        }
        if (curr.second + 1 < M) {
            if (!tracking[curr.first][curr.second + 1] && graph[curr.first][curr.second + 1] != 0) {
                tracking[curr.first][curr.second + 1] = true;
                ans[curr.first][curr.second + 1] = ans[curr.first][curr.second] + 1;
                works.push(make_pair(curr.first, curr.second + 1));
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    vector<vector<short>> graph(N, vector<short>(M));
    pair<int, int> goal;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> graph[i][j];

            if (graph[i][j] == 2)
                goal = {i, j};
        }
    }

    vector<vector<int>> ans(N, vector<int>(M, INT32_MAX));
    vector<vector<bool>> tracking(N, vector<bool>(M, false));

    bfs(graph, ans, tracking, goal);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (ans[i][j] == INT32_MAX && graph[i][j] == 0) {
                ans[i][j] = 0;
            } else if (ans[i][j] == INT32_MAX && graph[i][j] == 1) {
                ans[i][j] = -1;
            }

            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
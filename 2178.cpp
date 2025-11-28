#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(vector<vector<int>> &g, vector<vector<int>> &tracking, pair<int, int> vertex) {
    queue<pair<int, int>> q;

    q.push({0, 0});
    tracking[0][0] = 1;

    while (!q.empty()) {
        auto c = q.front();
        q.pop();

        if (c.first == N - 1 && c.second == M - 1)
            break;

        for (int i = 0; i < 4; ++i) {
            if (c.first + dx[i] >= 0 && c.first + dx[i] < N && c.second + dy[i] >= 0 && c.second + dy[i] < M && g[c.first + dx[i]][c.second + dy[i]] == 1 && !tracking[c.first + dx[i]][c.second + dy[i]]) {
                tracking[c.first + dx[i]][c.second + dy[i]] = tracking[c.first][c.second] + 1;
                q.push({c.first + dx[i], c.second + dy[i]});
            }
        }
    }

    return tracking[N - 1][M - 1];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    vector<vector<int>> g(N, vector<int>(M));

    string line;
    for (int i = 0; i < N; ++i) {
        cin >> line;
        for (int j = 0; j < M; ++j) {
            g[i][j] = line[j] - '0';
        }
    }

    vector<vector<int>> tracking(N, vector<int>(M));

    cout << bfs(g, tracking, {0, 0}) << "\n";

    return 0;
}
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;
    cin >> M >> N;

    vector<vector<int>> g(N, vector<int>(M));
    queue<pair<int, int>> q;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            cin >> g[y][x];

            if (g[y][x] == 1) {
                q.push({y, x});
            }
        }
    }

    char dx[4] = {0, 0, 1, -1};
    char dy[4] = {1, -1, 0, 0};

    int ans = 0;

    while (!q.empty()) {
        pair<int, int> c = q.front();
        q.pop();

        int cy = c.first;
        int cx = c.second;

        for (int i = 0; i < 4; ++i) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny >= 0 && ny < N && nx >= 0 && nx < M && g[ny][nx] == 0) {
                g[ny][nx] = g[cy][cx] + 1;
                q.push({ny, nx});
            }
        }
    }

    bool is_impossible = false;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            if (g[y][x] == 0) {
                ans = 0;
                is_impossible = true;
                break;
            }

            if (ans < g[y][x])
                ans = g[y][x];
        }

        if (is_impossible)
            break;
    }

    cout << ans - 1 << "\n";

    return 0;
}
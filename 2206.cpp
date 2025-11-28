#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct state {
    int x;
    int y;
    bool is_break;
    int seq;

    state(int x, int y, int seq, bool is_break) : x(x), y(y), seq(seq), is_break(is_break) {}
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> g(N, vector<int>(M));
    string line;
    for (int i = 0; i < N; ++i) {
        cin >> line;
        for (int j = 0; j < M; ++j) {
            g[i][j] = line[j] - '0';
        }
    }

    queue<state> q;
    q.push(state(0, 0, 1, false));

    // visited[y][x][is_break] - 벽을 부순 상태별로 방문 체크 (그래프 탐색: 상태 공간 확장기법)
    /* BFS에 대한 오해를 깨는 문제
        > "먼저 도달했다고 해서 항상 최적인 것은 아니다. 상태가 다르다면 나중에 도달한 경로가 더 나은 미래 가능성을 가질 수 있다."
     */
    vector<vector<vector<bool>>> visited(N, vector<vector<bool>>(M, vector<bool>(2, false)));
    visited[0][0][0] = true;

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int ans = 0;
    while (!q.empty()) {
        state c = q.front();
        q.pop();

        int cx = c.x;
        int cy = c.y;

        if (cx == M - 1 && cy == N - 1) {
            ans = c.seq;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
                if (g[ny][nx] == 1 && !c.is_break && !visited[ny][nx][1]) {
                    // 벽을 부수고 이동
                    q.push(state(nx, ny, c.seq + 1, true));
                    visited[ny][nx][1] = true;
                } else if (g[ny][nx] == 0 && !visited[ny][nx][c.is_break ? 1 : 0]) {
                    // 빈 공간으로 이동
                    q.push(state(nx, ny, c.seq + 1, c.is_break));
                    visited[ny][nx][c.is_break ? 1 : 0] = true;
                }
            }
        }
    }

    // cout << "\n";
    // for (int i = 0; i < N; ++i) {
    //     for (int j = 0; j < M; ++j) {
    //         cout << g[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    ans = (ans == 0) ? -1 : ans;
    cout << ans << "\n";

    return 0;
}
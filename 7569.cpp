#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct tri {
    int x;
    int y;
    int z;

    tri(int x, int y, int z) : x(x), y(y), z(z) {}
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N, H;
    cin >> M >> N >> H;

    vector<vector<vector<int>>> g(H, vector<vector<int>>(N, vector<int>(M)));
    queue<tri> q;
    for (int z = 0; z < H; ++z) {
        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < M; ++x) {
                cin >> g[z][y][x];

                if (g[z][y][x] == 1) {
                    q.push(tri(x, y, z));
                }
            }
        }
    }

    char dx[6] = {0, 0, 0, 0, 1, -1};
    char dy[6] = {1, -1, 0, 0, 0, 0};
    char dz[6] = {0, 0, 1, -1, 0, 0};

    int ans = 0;

    while (!q.empty()) {
        tri c = q.front();
        q.pop();

        int cx = c.x;
        int cy = c.y;
        int cz = c.z;

        for (int i = 0; i < 6; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int nz = cz + dz[i];
            if (nz >= 0 && nz < H && ny >= 0 && ny < N && nx >= 0 && nx < M && g[nz][ny][nx] == 0) {
                g[nz][ny][nx] = g[cz][cy][cx] + 1;
                q.push(tri(nx, ny, nz));
            }
        }
    }

    bool is_impossible = false;
    for (int z = 0; z < H; ++z) {
        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < M; ++x) {
                if (g[z][y][x] == 0) {
                    ans = 0;
                    is_impossible = true;
                    break;
                }

                if (ans < g[z][y][x])
                    ans = g[z][y][x];
            }

            if (is_impossible)
                break;
        }
        if (is_impossible)
            break;
    }

    cout << ans - 1 << "\n";

    return 0;
}

/*

5 3 2
0 -1 0 0 0
-1 0 0 0 0
0 0 0 0 0
-1 0 0 0 0
0 0 1 0 0
0 0 0 0 0

*/
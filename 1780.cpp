#include <iostream>
#include <vector>

using namespace std;

int cnt[3] = {
    0,
};

bool check(vector<vector<int>> &raw, int x, int y, int size) {
    for (int i = y; i < y + size; ++i) {
        for (int j = x; j < x + size; ++j) {
            if (raw[i][j] != raw[y][x]) {
                return true;
            }
        }
    }

    return false;
}

void dfs(vector<vector<int>> &raw, int x, int y, int size) {
    if (size == 1) {
        cnt[raw[y][x] + 1]++;
        return;
    }

    if (check(raw, x, y, size)) {
        dfs(raw, x, y, size / 3);
        dfs(raw, x + size / 3, y, size / 3);
        dfs(raw, x + size / 3 * 2, y, size / 3);

        dfs(raw, x, y + size / 3, size / 3);
        dfs(raw, x + size / 3, y + size / 3, size / 3);
        dfs(raw, x + size / 3 * 2, y + size / 3, size / 3);

        dfs(raw, x, y + size / 3 * 2, size / 3);
        dfs(raw, x + size / 3, y + size / 3 * 2, size / 3);
        dfs(raw, x + size / 3 * 2, y + size / 3 * 2, size / 3);
    } else {
        cnt[raw[y][x] + 1]++;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> raw(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> raw[i][j];
        }
    }

    dfs(raw, 0, 0, N);

    cout << cnt[0] << "\n"
         << cnt[1] << "\n"
         << cnt[2] << "\n";

    return 0;
}
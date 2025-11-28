#include <iostream>
#include <vector>

using namespace std;

/* 순서 문제를 해결하기 위한 로직
 * 순서 문제란?
 * 같은 집합을 먼저 출력해야 하는데, dfs 순서로 출력하면 다른 집합을 먼저 출력하게 되는 문제
 * 4
 * 1100
 * 1100
 * 0010
 * 0001
 * 의 원래 순서는 (100(1001))이자만
 * dfs 순서대로 출력하면 ((1001)100)으로 출력됨. */
bool check(vector<vector<char>> &raw, int x, int y, int size) {
    for (int i = y; i < y + size; ++i) {
        for (int j = x; j < x + size; ++j) {
            if (raw[i][j] != raw[y][x]) {
                return true;
            }
        }
    }

    return false;
}

void dfs(vector<vector<char>> &raw, int x, int y, int size) {
    if (size == 1) {
        cout << raw[y][x];
        return;
    }

    if (check(raw, x, y, size)) {
        cout << "(";
        dfs(raw, x, y, size / 2);
        dfs(raw, x + size / 2, y, size / 2);
        dfs(raw, x, y + size / 2, size / 2);
        dfs(raw, x + size / 2, y + size / 2, size / 2);
        cout << ")";
    } else {
        cout << raw[y][x];
        return;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<vector<char>> raw(N, vector<char>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> raw[i][j];
        }
    }

    dfs(raw, 0, 0, N);

    return 0;
}
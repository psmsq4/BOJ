#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> matrix(N + 1, vector<int>(N + 1));
    vector<vector<int>> row(N + 1, vector<int>(N + 1));
    vector<vector<int>> col(N + 1, vector<int>(N + 1));
    int total = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> matrix[i][j];
            row[i][j] = row[i][j - 1] + matrix[i][j];
            col[i][j] = col[i - 1][j] + matrix[i][j];
            total += matrix[i][j];
        }
    }

    int x1, x2, y1, y2;
    int result = 0;
    int row_sum = 0;
    int col_sum = 0;
    for (int i = 1; i <= M; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;

        for (int x = 1; x < x1; ++x) {
            row_sum += row[x][N];
        }
        for (int x = x2 + 1; x <= N; ++x) {
            row_sum += row[x][N];
        }
        for (int y = 1; y < y1; ++y) {
            col_sum += col[x2][y] - col[x1 - 1][y];
        }
        for (int y = y2 + 1; y <= N; ++y) {
            col_sum += col[x2][y] - col[x1 - 1][y];
        }

        cout << total - (row_sum + col_sum) << "\n";

        row_sum = col_sum = 0;
    }

    return 0;
}
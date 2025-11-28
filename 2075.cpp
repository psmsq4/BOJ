#include <iostream>
#include <vector>

using namespace std;

void merge(vector<vector<int>> &table, int left_row_stt, int left_row_end, int right_row_stt, int right_row_end, int N) {
    vector<int> tmp((right_row_end - left_row_stt + 1) * N);

    pair<int, int> left_ptr = {left_row_stt, 0};
    pair<int, int> right_ptr = {right_row_stt, 0};

    int ptr = 0;
    while ((left_ptr.first <= left_row_end) && (right_ptr.first <= right_row_end)) {
        if (table[left_ptr.first][left_ptr.second] < table[right_ptr.first][right_ptr.second]) {
            tmp[ptr++] = table[left_ptr.first][left_ptr.second++];
            if (left_ptr.second >= N) {
                left_ptr.first++;
                left_ptr.second = 0;
            }
        } else {
            tmp[ptr++] = table[right_ptr.first][right_ptr.second++];
            if (right_ptr.second >= N) {
                right_ptr.first++;
                right_ptr.second = 0;
            }
        }
    }

    if (left_ptr.first > left_row_end) {
        while (right_ptr.first <= right_row_end && right_ptr.second < N) {
            tmp[ptr++] = table[right_ptr.first][right_ptr.second++];
            if (right_ptr.second >= N) {
                right_ptr.first++;
                right_ptr.second = 0;
            }
        }
    } else if (right_ptr.first > right_row_end) {
        while (left_ptr.first <= left_row_end && left_ptr.second < N) {
            tmp[ptr++] = table[left_ptr.first][left_ptr.second++];
            if (left_ptr.second >= N) {
                left_ptr.first++;
                left_ptr.second = 0;
            }
        }
    }

    ptr = 0;
    for (int i = left_row_stt; i <= right_row_end; ++i) {
        for (int j = 0; j < N; ++j) {
            table[i][j] = tmp[ptr++];
        }
    }
}

void split(vector<vector<int>> &table, int row_stt, int row_end, int N) {
    if (row_stt >= row_end)
        return;

    int mid_row = (row_stt + row_end) / 2;
    split(table, row_stt, mid_row, N);
    split(table, mid_row + 1, row_end, N);

    merge(table, row_stt, mid_row, mid_row + 1, row_end, N);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> table(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> table[j][i];
        }
    }

    split(table, 0, N - 1, N);

    cout << table[N - 1][0] << "\n";

    return 0;
}
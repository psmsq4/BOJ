#include <iostream>
#include <vector>

using namespace std;

void cantor(vector<string> &target, int row_stt, int row_end, int col_stt, int col_end) {
    if (row_end <= row_stt || col_end <= col_stt)
        return;

    for (int i = row_stt + (row_end - row_stt + 1) / 3; i < row_stt + (row_end - row_stt + 1) / 3 * 2; ++i) {
        for (int j = col_stt + (col_end - col_stt + 1) / 3; j < col_stt + (col_end - col_stt + 1) / 3 * 2; ++j) {
            target[i][j] = ' ';
        }
    }

    int section_one_row_stt = row_stt;
    int section_one_row_end = row_stt + (row_end - row_stt + 1) / 3 - 1;
    int section_two_row_stt = section_one_row_end + 1;
    int section_two_row_end = row_stt + (row_end - row_stt + 1) * 2 / 3 - 1;
    int section_three_row_stt = section_two_row_end + 1;
    int section_three_row_end = row_end;

    int section_one_col_stt = col_stt;
    int section_one_col_end = col_stt + (col_end - col_stt + 1) / 3 - 1;
    int section_two_col_stt = section_one_col_end + 1;
    int section_two_col_end = col_stt + (col_end - col_stt + 1) * 2 / 3 - 1;
    int section_three_col_stt = section_two_col_end + 1;
    int section_three_col_end = col_end;

    cantor(target, section_one_row_stt, section_one_row_end, section_one_col_stt, section_one_col_end);
    cantor(target, section_one_row_stt, section_one_row_end, section_two_col_stt, section_two_col_end);
    cantor(target, section_one_row_stt, section_one_row_end, section_three_col_stt, section_three_col_end);

    cantor(target, section_two_row_stt, section_two_row_end, section_one_col_stt, section_one_col_end);
    cantor(target, section_two_row_stt, section_two_row_end, section_three_col_stt, section_three_col_end);

    cantor(target, section_three_row_stt, section_three_row_end, section_one_col_stt, section_one_col_end);
    cantor(target, section_three_row_stt, section_three_row_end, section_two_col_stt, section_two_col_end);
    cantor(target, section_three_row_stt, section_three_row_end, section_three_col_stt, section_three_col_end);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<string> stars(N);
    string star_line(N, '*');
    for (int i = 0; i < N; ++i) {
        stars[i] = star_line;
    }

    cantor(stars, 0, N - 1, 0, N - 1);
    for (int i = 0; i < N; ++i) {
        cout << stars[i] << "\n";
    }

    return 0;
}
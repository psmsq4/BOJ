#include <iostream>

using namespace std;

int main(void)  {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    int MATRIX[9][9] = {0, };
    int max_val, max_row, max_col;

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> MATRIX[i][j];
            if (i == 0 && j == 0)   {
                max_val = MATRIX[0][0];
                max_row = max_col = 0;
            } else {
                if (max_val <= MATRIX[i][j]) {
                    max_val = MATRIX[i][j];
                    max_row = i + 1;
                    max_col = j + 1;
                }
            }
        }
    }

    cout << max_val << endl;
    cout << max_row << " " << max_col;

    return 0;
}
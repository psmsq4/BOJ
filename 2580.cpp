#include <chrono>
#include <deque>
#include <iostream>
#include <map>
#include <thread>

using namespace std;

int sdq[9][9];
deque<pair<int, int>> slots;
map<int, bool> checklist;

bool promising(int row, int col) {
    bool is_promising = true;

    int cnt = 0;
    for (int c = 0; c < 9; ++c) {
        checklist[sdq[row][c]] = true;
        if (sdq[row][c] == 0)
            cnt++;

        if (cnt >= 2) {
            is_promising = false;
            break;
        }
    } // 행 유망성 검사

    if (!is_promising) {
        checklist.clear();
        is_promising = true;
        cnt = 0;
        for (int r = 0; r < 9; ++r) {
            checklist[sdq[r][col]] = true;
            if (sdq[r][col] == 0)
                cnt++;

            if (cnt >= 2) {
                is_promising = false;
                break;
            }
        } // 열 유망성 검사
    }

    if (!is_promising) {
        checklist.clear();
        is_promising = true;
        cnt = 0;
        for (int r = row - (row % 3); r < 3 * (row / 3 + 1); ++r) {
            for (int c = col - (col % 3); c < 3 * (col / 3 + 1); ++c) {
                checklist[sdq[r][c]] = true;
                if (sdq[r][c] == 0)
                    cnt++;

                if (cnt >= 2) {
                    is_promising = false;
                    break;
                }
            }
        } // 3x3 유망성 검사
    }

    return is_promising;
}

void sudoku() {
    if (slots.empty())
        return;

    pair<int, int> slot = slots.front();
    slots.pop_front();

    int row = slot.first;
    int col = slot.second;
    cout << "sudoku(" << row << ", " << col << ")\n";

    if (promising(row, col)) {
        int fill;
        for (int i = 1; i <= 9; ++i) {
            if (!checklist[i]) {
                fill = i;
                break;
            }
        }

        sdq[row][col] = fill;

        cout << "(" << row << ", " << col << ") " << "fill: " << fill << "\n";
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                cout << sdq[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        this_thread::sleep_for(chrono::seconds(1));

        checklist.clear();
        sudoku();
    } else {
        checklist.clear();
        slots.push_back(slot);
        sudoku();
    }
}

int main(void) {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> sdq[i][j];
            if (sdq[i][j] == 0)
                slots.push_back(make_pair(i, j));
        }
    }

    sudoku();

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << sdq[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
#include <bitset>
#include <chrono>
#include <iostream>
#include <map>
#include <thread>
#include <vector>

using namespace std;

/* 각 빈칸에 해당하는 후보 목록을 만들기
 * ->  */

struct Slot {
    pair<int, int> coord;
    vector<int> candidates;

    Slot(pair<int, int> coord) : coord(coord) {}
};

int sdq[9][9];
vector<Slot> slots;
bitset<10> checklist(false);

void init() {
    for (auto &slot : slots) {
        int row = slot.coord.first;
        int col = slot.coord.second;

        for (int c = 0; c < 9; ++c) {
            checklist[sdq[row][c]] = true;
        } // 후보 추출 from 행

        for (int r = 0; r < 9; ++r) {
            checklist[sdq[r][col]] = true;
        } // 후보 추출 from 열

        for (int r = row - (row % 3); r < 3 * (row / 3 + 1); ++r) {
            for (int c = col - (col % 3); c < 3 * (col / 3 + 1); ++c) {
                checklist[sdq[r][c]] = true;
            }
        } // 후보 추출 from 3x3

        for (int i = 1; i <= 9; ++i) {
            if (!checklist[i])
                slot.candidates.push_back(i);
        }
        checklist.reset();
    }
}

int max_lv;

bool promising(int row, int col) {
    /* 중복값 존재 -> 유망하지 않음. */
    checklist.reset();
    for (int c = 0; c < 9; ++c) {
        /* 0이 여러 개인 것은 의미가 없다. */
        if (sdq[row][c] == 0)
            continue;

        // cout << checklist[sdq[row][c]] << "\n";
        if (checklist[sdq[row][c]]) {
            return false;
        } else {
            checklist[sdq[row][c]] = true;
        }
    } // 행 유망성 검사

    checklist.reset();
    for (int r = 0; r < 9; ++r) {
        /* 0이 여러 개인 것은 의미가 없다. */
        if (sdq[r][col] == 0)
            continue;

        // cout << checklist[sdq[r][col]] << "\n";
        if (checklist[sdq[r][col]]) {
            return false;
        } else {
            checklist[sdq[r][col]] = true;
        }
    } // 열 유망성 검사

    checklist.reset();
    for (int r = row - (row % 3); r < 3 * (row / 3 + 1); ++r) {
        for (int c = col - (col % 3); c < 3 * (col / 3 + 1); ++c) {
            /* 0이 여러 개인 것은 의미가 없다. */
            if (sdq[r][c] == 0)
                continue;

            // cout << checklist[sdq[r][c]] << "\n";
            if (checklist[sdq[r][c]]) {
                return false;
            } else {
                checklist[sdq[r][c]] = true;
            }
        }
    } // 3x3 유망성 검사

    return true;
}

void sudoku(int current_lv, int fill) {
    int row = slots[current_lv].coord.first;
    int col = slots[current_lv].coord.second;
    sdq[row][col] = fill;

    // cout << "lv: " << current_lv << "(" << row << ", " << col << ")" << "\n";
    if (promising(row, col)) {
        /* 종료조건 (promising이 선행되어야 함.) */
        if (current_lv >= max_lv) {
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                    cout << sdq[i][j] << " ";
                }
                cout << "\n";
            }
            exit(0);
        }

        for (int i = 0; i < slots[current_lv + 1].candidates.size(); ++i) {
            sudoku(current_lv + 1, slots[current_lv + 1].candidates[i]);
        }
        /* 이 코드는 왜?
         * -> 하위 레벨에서 모든 후보를 조사했는데도 불구하고 실패했다는 거니까
         *    현재 레벨에서 시도한 행위 조차 유망하지 않다는 것을 경험적으로 증명한 것이므로
         *    롤백을 해야한다.  */
        sdq[row][col] = 0;
    } else {
        sdq[row][col] = 0;
    }

    return;
}

void root() {
    for (int i = 0; i < slots[0].candidates.size(); ++i) {
        sudoku(0, slots[0].candidates[i]);
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
                slots.push_back(Slot(make_pair(i, j)));
        }
    }

    init();
    max_lv = slots.size() - 1;
    root();

    // for (int i = 0; i < 9; ++i) {
    //     for (int j = 0; j < 9; ++j) {
    //         cout << sdq[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    return 0;
}
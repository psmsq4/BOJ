#include <iostream>
#include <vector>

using namespace std;

int N;
int ans = 0;
vector<pair<int, int>> valid_queens;

void nqueens(int current_row, int current_col) {
    /* 유효성 검사 */
    for (auto queens : valid_queens) {
        if (queens.first == current_row || queens.second == current_col || abs(queens.first - current_row) == abs(queens.second - current_col)) {
            return;
        }
    }
    /* 처음 호출 때는 무시함. */
    if (current_row != 0)
        valid_queens.push_back(make_pair(current_row, current_col));

    /* 종료조건: N행 초과 검사 시 */
    if (current_row == N) {
        ans++;
        valid_queens.pop_back();
        return;
    }

    /* 현재 row와 col이 확정되면 다음 row를 검사함. */
    for (int col = 1; col <= N; ++col) {
        nqueens(current_row + 1, col);
    }

    /* 검사 완료 시, 현재 확정된 row, col을 vector에서 제거함.
     * 처음 호출 때는 무시함 */
    if (current_row != 0)
        valid_queens.pop_back();
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    nqueens(0, 0);

    cout << ans << "\n";

    return 0;
}
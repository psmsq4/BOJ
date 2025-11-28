#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int bin_search(vector<int> &xs, int C) {
    int MAX = INT32_MIN;
    int prev_step = 0;
    int curr_step = (*(xs.end() - 1) - *(xs.begin())) / (C - 1);
    int begin = 0;
    int last = curr_step;
    /* C가 3이면, 구간은 두 개로 분할되어야 함.
     * C가 4이면, 구간은 세 개로 분할되어야 함.
     * C가 5이면, 구간은 네 개로 분할되어야 함. */

    while (true) {
        bool is_valid = true;
        int init = *(xs.begin());
        auto next = xs.begin();
        cout << "step: [" << curr_step << "] ";
        for (int i = 0; i < (C - 1); ++i) {
            next = lower_bound(next + 1, xs.end(), init + curr_step);
            if (next == xs.end()) {
                is_valid = false;
                break;
            }
            cout << *(next) << " ";
            init = *next;
        }
        cout << "\n";

        if (is_valid) {
            begin = curr_step; // 저점 높이기
        } else {
            last = curr_step; // 고점 낮추기
        }

        curr_step = (begin + last) / 2;
        if (curr_step == begin)
            break;
    }
    // 5(fail) -> 2(success) -> 3(= (last5 + begin2) / 2)(success) -> 4(= (last5 + begin3) / 2)(fail) -> 3(= (begin3 + last4) / 2) (이미 시도) -> 3의 최대
    //                       -> 3(fail) -> 2(= (2 + 3) / 2)
    // 5(fail) -> 2(= (0 + 5) / 2)(fail) -> 1(= (0 + 2) / 2)(success) -> 0(= (1 + 0) / 2)(== prev_step): break

    return curr_step;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, C;
    cin >> N >> C;

    vector<int> xs(N);
    for (int i = 0; i < N; ++i) {
        cin >> xs[i];
    }

    /* 1 2 4 8 9
       1 2 3 4 5 6 7 8 9 10 21
       1 2 3 4 5 6 7 8 9 10 11 21 */
    /* 1 ~ 21 : 20개 간격
     * 5개 공유기 설치 시 최대 5의 간격 필요 (20 / 4 = 5)(1, 6, 11, 16, 21)
     * BUT 16이 없는 상태. (1, 6, 11, 21, X)
     * 5의 절반인 2의 간격으로 시도 (1, 3, 5, 7, 9) : 모두 존재
     * 2의 간격으로 했을 때 모두 존재하므로 2와 5의 절반인 3의 간격으로 시도 (1, 4, 7, 10, 21) : 모두 존재
     * (만약 3을 건너 뛰었을 때 없다면, 그 이상의 것을 취해도 됨.)
     * 3의 간격으로 했을 때 모두 존재하므로 3과 5의 절반인 4의 간격으로 시도 (1, 5, 10, 21, X) : 모두 존재하지 않음.
     * 즉, 3의 간격이 최대 간격임을 알 수 있다.*/
    sort(xs.begin(), xs.end());
    cout << bin_search(xs, C) << "\n";

    return 0;
}
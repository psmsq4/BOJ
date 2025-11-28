#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int N;
    cin >> N;

    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    int l = 1;
    int r = N;
    int m = (l + r) / 2;
    while (l <= r) {
        /* 이분 탐색 기준은 "길이"가 되어야 할 것 같다.
         * 최대 길이를 구하는 것이기 때문이다.
         * 길이로 가능한 것은 최소 1에서 최대 N까지 가능하다.
         * 처음 탐색할 것은 (N + 1) / 2 길이를 가진 증가하는 연속 수열이 있느냐에 관한 것이다.
         * 없으면 1과 (N + 1) / 2의 중간 길이를, 있으면 (N + 1) / 2와 N의 중간 길이가 존재하는지 찾아본다.
         * 문제가 되는 건, 길이 MID에 해당하는 증가하는 연속수열의 존재성을 어떻게 파악할 것인가에 관한 것이다.
         * 물론 길이 MID를 탐색할 때 유효성 조건은 길이 MID 이상의 증가하는 연속수열을 찾으면 된다. */

        이전에 풀었던 방식에서 lower_bound자체가 이분 탐색을 활용한 것임.

            int len = 0;
        for (int i = 1; i < N; ++i) {
        }
    }

    return 0;
}
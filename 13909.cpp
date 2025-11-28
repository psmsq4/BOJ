#include <cmath>
#include <iostream>
#include <set>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    size_t N;
    cin >> N;

    /* 6번 사람은 6번 문을, 6 = [2 | 3], 1이 열고 -> 2가 닫고 -> 3이 열었던 문을 닫는다.
     * 7번 사람은 7번 문을, 7 = [], 1이 열었던 문을 닫는다.
     * 8번 사람은 8번 문을, 8 = [2 | 4], 1이 열고 -> 2가 닫고 -> 4가 열었던 문을 닫는다.
     * 9번 사람은 9번 문을, 9 = [3], 1이 열고 -> 3이 닫았던 문을 연다. */

    // size_t cnt = N;
    // for (int i = 2; i <= N; i++) {
    //     set<size_t> submultiples;
    //     for (int j = 2; j * j <= i; j++) {
    //         if (i % j == 0) {
    //             submultiples.insert(j);
    //             submultiples.insert(i / j);
    //         }
    //     }
    //     if (submultiples.size() % 2 == 0) {
    //         cnt--;
    //     }
    // }

    /* 아이디어 주요 골자
     * -> 약수의 개수가 홀수 / 짝수에 따라 로직이 달라짐.
     * -> 그러나 약수의 개수가 홀수인 경우는 완전제곱수일 때를 제외하고는 존재하지 않음. */
    cout << static_cast<int>(sqrt(N)) << "\n";

    return 0;
}
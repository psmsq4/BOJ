#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    long long stt = 1;
    long long end = N * N; // K번째 수는 최대 K
    long long M = (stt + end) / 2;
    while (true) {
        long long range_left = 0;
        long long range_right = 0;
        long long MAX = LONG_MIN;
        for (long long i = 1; i <= N; ++i) {
            if (M / i > N) {
                range_left += N;
                range_right += N;
            } else if (M % i == 0) { // && M / i <= N
                range_left += M / i - 1;
                range_right += M / i;
            } else if (M % i != 0) { // && M / i <= N
                range_left += M / i;
                range_right += M / i;
                if (MAX < (M / i) * i)
                    MAX = (M / i) * i;
            }
        }
        range_left += 1;
        cout << "(" << range_left << ", " << range_right << ")(" << stt << ", " << end << "): " << M << "\n";
        if (range_left > range_right) {
            // 존재하지 않는 수.
            // cout << "stt: " << stt << " end: " << end << " M: " << M << "\n";
            if (range_right == K) {
                M = MAX;
                break;
            }
        }

        if (range_right < K) {
            stt = M + 1;
        } else if (K < range_left) {
            end = M - 1;
        } else if (range_left <= K && K <= range_right) {
            break;
        }
        M = (stt + end) / 2;
    }

    cout << M << "\n";

    /*
    1 2 3
    2 4 6
    3 6 9
    -> 1 2 2 3 3 4 6 6 9
    -> 9 / 1 -> 3
    -> 9 / 2 -> 3
    -> 9 / 3 -> 2
    -> 8 / 1 -> 3
    -> 8 / 2 -> 3
    -> 8 / 3 -> 2

    1 2 3 4
    2 4 6 8
    3 6 9 12
    4 8 12 16
    -> 1 2 2 3 3 4 4 4 6 6 8 8 9 12 12 16

    -> 1 2 2 3 3 4 4 4 5 5 6 6 8 8 9 10 10 12 12 15 15 16 20 20 25

    1  2  3  4  5  6  7  8  9   10  11  12   1 x 1
    2  4  6  8  10 12 14 16 18  20  22  24   1 x 2
    3  6  9  12 15 18 21 24 27  30  33  36   1 x 3
    4  8  12 16 20 24 28 32 36  40  44  48   1 x 2 x 2
    5  10 15 20 25 30 35 40 45  50  55  60   1 x 5
    6  12 18 24 30 36 42 48 54  60  66  72   1 x 2 x 3
    7  14 21 28 35 42 49 56 63  70  77  84   1 x 7
    8  16 24 32 40 48 56 64 72  80  88  96   1 x 2 x 2 x 2 (8 미만 수의 위치를 변동시키지 않는다.)
    9  18 27 36 45 54 63 72 81  90  99  108  1 x 3 x 3 (9 미만 수의 위치를 변동시키지 않는다.)
    10 20 30 40 50 60 70 80 90  100 110 120
    11 22 33 44 55 66 77 88 99  110 121 132
    12 24 36 48 60 72 84 96 108 120 132 144
    */

    return 0;
}
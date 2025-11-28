#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N;
    cin >> N;

    long long input;
    for (long long i = 0; i < N; ++i) {
        cin >> input;

        for (long long j = input;; ++j) {
            bool is_prime = true;

            // 0과 1은 소수가 아님
            if (j <= 1) {
                is_prime = false;
            } else {
                long long k = 2;
                while (k <= sqrt(j)) {
                    if (j % k == 0) {
                        is_prime = false;
                        break; // 이거 없으면 시간 초과
                    }
                    k++;
                }
            }

            if (is_prime) {
                cout << j << "\n";
                break;
            }
        }
    }

    return 0;
}
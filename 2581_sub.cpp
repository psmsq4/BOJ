#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int M, N;
    cin >> M >> N;

    vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= N; ++i) {
        /* 소수의 배수가 제거되므로, is_prime[i]가 true이면 반드시 소수이다. */
        if (is_prime[i]) {
            /* i * 1 ~ (i-1)은 필요없다. 이미 이전에 제거되었기 때문이다. */
            /* i의 배수만 신경쓰기 위해 j += i로 증가시킨다. */
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int sum = 0, min_prime = 0;
    for (int i = M; i <= N; ++i) {
        if (is_prime[i]) {
            sum += i;
            if (min_prime == 0)
                min_prime = i;
        }
    }

    if (sum == 0) {
        cout << -1 << endl;
    } else {
        cout << sum << endl;
        cout << min_prime << endl;
    }

    return 0;
}
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<size_t> prime_operate(size_t num) {
    vector<bool> is_primes(num + 1, true);
    vector<size_t> primes;

    is_primes[1] = false;
    is_primes[2] = true;
    is_primes[3] = true;

    for (int i = 2; i * i <= num; ++i) {
        if (is_primes[i]) {
            for (int j = i * i; j <= num; j += i) {
                is_primes[j] = false;
            }
        }
    }

    for (int i = 2; i <= num; ++i) {
        if (is_primes[i])
            primes.push_back(i);
    }

    return primes;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    size_t N;
    cin >> N;

    pair<size_t, size_t> input;
    for (size_t i = 0; i < N; ++i) {
        cin >> input.first >> input.second;

        /* 첫 번째 수와 두 번째 수를 각각 소인수분해
         * -> 공통인 소수가 없으면, 단순 곱으로 최소공배수 도출
         * -> 공통인 소수가 있으면, (공통 소수 곱) * (첫 번째 수 / 공통 소수 곱) * (두 번째 수 / 공통 소수 곱)
         *    == (첫 번째 수) * (두 번째 수) / (공통 소수 곱)으로 최소 공배수 도출
         * ※ 여기서 (공통 소수 곱)은 최대공약수를 의미함. */

        /* 두 개의 수 중 작은 수만 소인수분해
         * -> 소인수분해된 소수들로 큰 수를 나눠보고 나눠 떨어지면 공통인 소수 */

        /* 최적화 전략:
         * -> 소인수분해가 아닌 최대공약수를 구하는 유클리드 호제법을 이용하도록 한다.
         * -> 간단히 유클리드 호제법을 정리하면 다음과 같다.
         * --> a, b가 최대공약수를 구하고자 하는 수이며, a = b * q + r (0 <= r < b)를 만족한다고 할 때
         * --> a, b의 최대공약수는 b, r의 최대공약수와 같다.
         * --> 즉 구현할 때는 r이 0이 될 때까지 구하고 r이 0일 때 a가 최종적으로 구하고자 하는 최대공약수가 되는 것이다. */
        size_t min_input = min(input.first, input.second);
        size_t max_input = max(input.first, input.second);
        size_t common_prime_product = 1;
        vector<size_t> primes = prime_operate(min_input);
        vector<size_t> min_input_primes;
        for (auto prime : primes) {
            while (min_input % prime == 0) {
                min_input_primes.push_back(prime);
                min_input /= prime;
            }
        }

        for (auto min_input_prime : min_input_primes) {
            if (max_input % min_input_prime == 0) {
                common_prime_product *= min_input_prime;
                max_input /= min_input_prime;
            }
        }

        cout << input.first * input.second / common_prime_product << "\n";
    }

    return 0;
}
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int M, N;
    int interval = 0;

    cin >> M >> N;
    interval = N - M + 1;

    int *prime_list = (int *)malloc(sizeof(int) * interval);
    for (int i = M; i <= N; ++i) {
        prime_list[i - M] = i;
    }

    if (prime_list[0] == 1)
        prime_list[0] = -1;

    vector<int> primes;

    for (int i = 2; i <= sqrt(N); ++i) {
        bool flag = false;
        for (int prime : primes) {
            if (i % prime == 0) {
                flag = true;
                break;
            }
        }
        if (flag)
            continue;

        primes.push_back(i);

        // for (int j = 2; j < i; ++j) {
        //     if (i % j == 0)
        //         flag = true;
        // }

        // if (flag)
        //     continue;

        for (int k = 0; k < interval; ++k) {
            if (prime_list[k] == -1)
                continue;
            if (prime_list[k] % i == 0 && prime_list[k] != i) {
                prime_list[k] = -1;
            }
        }
    }

    int prime_sum = 0;
    int lowest_prime = 0;

    for (int i = 0; i < interval; ++i) {
        cout << prime_list[i] << " ";
        if (lowest_prime == 0 && prime_list[i] != -1) {
            lowest_prime = prime_list[i];
        }
        if (prime_list[i] != -1)
            prime_sum += prime_list[i];
    }
    cout << "\n";

    if (prime_sum == 0)
        cout << -1 << "\n";
    else {
        cout << prime_sum << "\n";
        cout << lowest_prime << "\n";
    }

    free(prime_list);
    return 0;
}
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int N;

    cin >> N;
    int tmp = N;

    vector<bool> is_prime(N, true);

    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= N; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= N; ++i) {
        if (is_prime[i]) {
            while (tmp % i == 0) {
                tmp /= i;
                cout << i << "\n";
            }
        }
    }

    return 0;
}
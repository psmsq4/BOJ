#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;
    cin >> M >> N;

    vector<bool> is_prime(N + 1, true); // N + 1 크기로 설정해야 N까지 소수 여부를 다룰 수 있음.
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= N; ++i) {
        for (int j = i * i; j <= N; j += i) {
            if (is_prime[i]) {
                is_prime[j] = false;
            }
        }
    } // 이건 뭐 공식 같은 거니까 평생 기억해둘 것.

    for (int i = M; i <= N; ++i) {
        if (is_prime[i])
            cout << i << "\n";
    }

    return 0;
}
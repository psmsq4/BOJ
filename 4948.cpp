#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    while (true) {
        cin >> N;
        if (N == 0)
            break;

        vector<bool> is_prime(2 * N + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i <= 2 * N; ++i) {
            for (int j = i * i; j <= 2 * N; j += i) {
                if (is_prime[i])
                    is_prime[j] = false;
                else
                    break;
            }
        }

        int cnt = 0;
        for (int i = N + 1; i <= 2 * N; ++i) {
            if (is_prime[i])
                cnt++;
        }
        cout << cnt << "\n";
    }
}
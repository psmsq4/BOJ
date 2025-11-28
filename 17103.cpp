#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int input;
    for (int seq = 0; seq < N; ++seq) {
        cin >> input;

        vector<bool> is_prime(input + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i <= input; ++i) {
            for (int j = i * i; j <= input; j += i) {
                if (is_prime[i])
                    is_prime[j] = false;
                else
                    break;
            }
        }

        /* 골드바흐 파티션 개수 아이디어 주요 골지
         * -> 합은 N의 절반 이하의 수와 N의 절반 이상의 수로 구성될 것이기에,
         * -> N의 절반만큼만 반복하면 전체 골드바흐 파티션 개수를 구할 수 있음. */
        int cnt = 0;
        for (int i = 2; i <= is_prime.size() / 2; ++i) {
            if (is_prime[i])
                if (is_prime[input - i]) {
                    cnt++;
                }
        }

        cout << cnt << "\n";
    }

    return 0;
}
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> coins;
    int coin;
    for (int i = 0; i < N; ++i) {
        cin >> coin;
        if (coin > K)
            continue;

        coins.push_back(coin);
    }

    sort(coins.begin(), coins.end(), [](int a, int b) {
        return a > b;
    });

    int acc = 0;
    int cnt = 0;
    while (acc != K) {
        if (acc + coins[0] > K) {
            coins.erase(coins.begin());
        } else {
            acc += coins[0];
            cnt++;
        }
    }

    cout << cnt << "\n";

    return 0;
}
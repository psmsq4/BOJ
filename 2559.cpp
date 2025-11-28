#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> series(N + 1);
    vector<int> ps(N + 1);
    int MAX = INT32_MIN;

    for (int i = 1; i <= N; ++i) {
        cin >> series[i];
        ps[i] = ps[i - 1] + series[i];
        if (i >= K) {
            int candidate = ps[i] - ps[i - K]; // (i - 2) + (i - 1) + i
            if (candidate > MAX)
                MAX = candidate;
        }
    }

    cout << MAX << "\n";

    return 0;
}
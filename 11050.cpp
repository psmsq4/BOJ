#include <iostream>

using namespace std;

int combination(int N, int K) {
    if (N == 1 || K == 0 || N == K)
        return 1;

    return combination(N - 1, K - 1) + combination(N - 1, K);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    cout << combination(N, K) << "\n";

    return 0;
}
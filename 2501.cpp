#include <iostream>
using namespace std;

int main(void) {
    int N, K;
    int i;

    cin >> N >> K;

    for (i = 1; i <= N; ++i) {
        if (N % i == 0)
            K--;

        if (K == 0) {
            break;
        }
    }

    if (K != 0)
        cout << 0 << "\n";
    else
        cout << i << "\n";

    return 0;
}
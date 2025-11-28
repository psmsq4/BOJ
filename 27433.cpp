#include <iostream>

using namespace std;

long long factorial(long long N) {
    if (N == 1 || N == 0)
        return 1;

    return N * factorial(N - 1);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N;
    cin >> N;

    cout << factorial(N) << "\n";

    return 0;
}
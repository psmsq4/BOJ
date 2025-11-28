#include <iostream>
#include <vector>

using namespace std;

long long fibo(int N) {
    if (N == 0)
        return 0;
    else if (N == 1)
        return 1;

    return fibo(N - 1) + fibo(N - 2);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    cout << fibo(N) << "\n";
}
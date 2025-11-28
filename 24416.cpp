#include <iostream>

using namespace std;

int recursive_cnt = 0;
int fib(int n) {
    if (n == 1 || n == 2) {
        recursive_cnt++;
        return 1;
    } else {
        return (fib(n - 1) + fib(n - 2));
    } // f5 = f4 + f3 = f3 + f2 + f2 + f1 = f2 + f1 + f2 + f2 + f1
}

int f[41];
int dp_cnt = 0;

int fibonacci(int n) {
    f[1] = f[2] = 1;
    for (int i = 3; i <= n; ++i) {
        dp_cnt++;
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    fib(N);
    fibonacci(N);

    cout << recursive_cnt << " " << dp_cnt << "\n";

    return 0;
}
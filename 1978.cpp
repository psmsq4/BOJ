#include <iostream>
using namespace std;

bool isPrime(int num) {
    if (num == 1)
        return false;

    for (int i = 2; i < num; ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main(void) {
    int N;
    int cnt = 0;

    cin >> N;

    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;

        if (isPrime(num))
            cnt++;
    }

    cout << cnt << "\n";

    return 0;
}
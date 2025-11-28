#include <iostream>

using namespace std;

int main(void) {
    /* (n-1) + (n-2) + (n-3) + --- + 0 = (n-1) * (n) / 2*/
    unsigned long long N;

    cin >> N;

    cout << (N - 1) * N / 2 << "\n";
    cout << 2 << "\n";

    return 0;
}
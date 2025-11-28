#include <cmath>
#include <iostream>

using namespace std;

int main(void) {
    long long N;

    cin >> N;

    long long R = 0;

    long long tmp;

    // while (N >= 0) {
    tmp = N;
    while (tmp - 2 >= 0) {
        R += (tmp - 1) * (tmp - 2) / 2;
        tmp--;
    }
    // N--;
    // }

    cout << R << "\n";
    cout << 3 << "\n";

    return 0;
}
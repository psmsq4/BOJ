#include <cmath>
#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
    long long tmp;
    while (b != 0) {
        tmp = b;
        b = a % b;
        a = tmp;
    }

    return a;
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long a, b;
    cin >> a >> b;

    cout << lcm(max(a, b), min(a, b)) << "\n";

    return 0;
}
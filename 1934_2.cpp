#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

size_t gcd(size_t a, size_t b) {
    while (b != 0) {
        size_t tmp = b;
        b = a % b;
        a = tmp;
    }

    return a;
}

size_t lcm(size_t a, size_t b) {
    return a / gcd(a, b) * b;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    size_t N;
    cin >> N;

    pair<size_t, size_t> input;
    for (size_t i = 0; i < N; ++i) {
        cin >> input.first >> input.second;

        cout << lcm(input.first, input.second) << "\n";
    }

    return 0;
}

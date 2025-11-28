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

    long long numerator1, denominator1;
    long long numerator2, denominator2;

    cin >> numerator1 >> denominator1;
    cin >> numerator2 >> denominator2;

    long long deno_lcm = lcm(max(denominator1, denominator2), min(denominator1, denominator2));
    long long numerator3 = (numerator1 * deno_lcm / denominator1) + (numerator2 * deno_lcm / denominator2);
    long long denominator3 = deno_lcm;
    long long divider = gcd(max(numerator3, denominator3), min(numerator3, denominator3));

    numerator3 /= divider;
    denominator3 /= divider;

    cout << numerator3 << " " << denominator3 << "\n";

    return 0;
}
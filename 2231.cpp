/* 2231.cpp */
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int N;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int res_min = INT32_MAX;
    int constructor = N;
    int decomposition_sum = 0;
    int tmp;
    vector<int> digits;

    while (constructor > 0) {
        tmp = constructor;
        while (tmp != 0) {
            digits.push_back(tmp % 10);
            tmp /= 10;
        }

        for (int digit : digits) {
            decomposition_sum += digit;
        }
        decomposition_sum += constructor;

        if (decomposition_sum == N && constructor < res_min) {
            res_min = constructor;
        }

        constructor--;
        digits.clear();
        decomposition_sum = 0;
    }

    if (res_min == INT32_MAX)
        cout << 0 << "\n";
    else
        cout << res_min << "\n";

    return 0;
}
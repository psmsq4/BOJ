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

    int init = 665;
    int six_continuity = 0;
    int tmp;
    bool is_valid = false;
    while (N > 0) {
        init++;
        tmp = init;

        while (tmp != 0) {
            if (tmp % 10 == 6)
                six_continuity++;
            else
                six_continuity = 0;

            if (six_continuity == 3) {
                is_valid = true;
                break;
            }
            tmp /= 10;
        }

        if (is_valid)
            N--;
        six_continuity = 0;
        is_valid = false;
    }

    cout << init << "\n";

    return 0;
}
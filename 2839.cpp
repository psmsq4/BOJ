#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    int quotient_five = N / 5;
    int remainder_five = N % 5;

    int quotient_three = 0;
    int remainder_three = 0;

    while (true) {

        if (remainder_five == 0) {
            break;
        } else {
            quotient_three = remainder_five / 3;
            remainder_three = remainder_five % 3;

            if (remainder_three == 0) {
                break;
            }

            quotient_five--;
            remainder_five += 5;
        }

        if (quotient_five == -1) {
            cout << -1 << "\n";
            return 0;
        }
    }

    int result = quotient_five + quotient_three;

    cout << result << "\n";

    return 0;
}
#include <cmath>
#include <iostream>

using namespace std;

int main(void) {
    int a0, a1;
    int c, n0;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a0 >> a1;
    cin >> c;
    cin >> n0;

    if ((c - a0) < 0) {
        cout << 0 << "\n";
    } else if ((c - a0) * n0 >= a1) {
        cout << 1 << "\n";
    } else {
        cout << 0 << "\n";
    }

    return 0;
}
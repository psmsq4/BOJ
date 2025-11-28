#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int a, b, c, d, e, f;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c >> d >> e >> f;

    int x, y;
    if (a != 0 && b != 0 && d != 0 && e != 0) {
        y = (c * d - f * a) / (b * d - e * a);
        x = (c - b * y) / a;
    } else if (a == 0) {
        y = c / b;
        x = (f - e * y) / d;
    } else if (b == 0) {
        x = c / a;
        y = (f - d * x) / e;
    } else if (d == 0) {
        y = f / e;
        x = (c - b * y) / a;
    } else if (e == 0) {
        x = f / d;
        y = (c - a * x) / b;
    } else {
        x = y = 0;
    }
    cout << x << " " << y << "\n";

    return 0;
}
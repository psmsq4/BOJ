#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int x, y, w, h;

    cin >> x >> y >> w >> h;

    int min = INT32_MAX;

    if (min > x)
        min = x;
    if (min > y)
        min = y;
    if (min > w - x)
        min = w - x;
    if (min > h - y)
        min = h - y;

    cout << min << "\n";

    return 0;
}
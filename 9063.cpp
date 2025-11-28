#include <cmath>
#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    int xmin = INT32_MAX, xmax = INT32_MIN, ymin = INT32_MAX, ymax = INT32_MIN;
    int x, y;
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;

        if (x > xmax)
            xmax = x;
        if (x < xmin)
            xmin = x;

        if (y > ymax)
            ymax = y;
        if (y < ymin)
            ymin = y;
    }

    int width = xmax - xmin;
    int height = ymax - ymin;

    unsigned long long result = static_cast<unsigned long long>(width) * static_cast<unsigned long long>(height);

    cout << result << "\n";

    return 0;
}
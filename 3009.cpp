#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int x, y;
    vector<int> xs, ys;
    int rx, ry;

    for (auto i = 0; i < 3; ++i) {
        bool flag = false;
        cin >> x >> y;

        for (auto j = xs.begin(); j != xs.end(); ++j) {
            if (x == *j) {
                xs.erase(j);
                flag = true;
                break;
            }
        }

        if (!flag)
            xs.push_back(x);

        flag = false;

        for (auto j = ys.begin(); j != ys.end(); ++j) {
            if (y == *j) {
                ys.erase(j);
                flag = true;
                break;
            }
        }

        if (!flag)
            ys.push_back(y);
    }

    cout << *(xs.begin()) << " " << *(ys.begin()) << "\n";

    return 0;
}
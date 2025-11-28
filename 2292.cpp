#include <iostream>

using namespace std;

int main(void)  {
    int N;

    int d = 6;
    int step = 1;

    cin >> N;

    while ((1 + (step - 1) * (6 * step) / 2) < N)   {
        step ++;
    }

    cout << step;

    return 0;
}
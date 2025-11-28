#include <cmath>
#include <iostream>

using namespace std;

int main(void) {
    int A, B, V;

    cin >> A >> B >> V;

    int DAY_STEP = A - B;
    int DAYS = 0;

    if (A >= V) {
        cout << 1 << endl;
        return 0;
    }
    V = V - A;

    DAYS = ceil(V / (double)DAY_STEP) + 1;

    cout << DAYS << "\n";

    return 0;
}
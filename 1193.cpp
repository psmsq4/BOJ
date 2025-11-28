#include <iostream>

using namespace std;

int accumulate_sum(int diag) {
    int sum = 0;
    for (int i = 1; i <= diag; ++i) {
        sum += i;
    }

    return sum;
}

int main(void) {
    int i = 0;
    int N;

    cin >> N;

    while (!(accumulate_sum(i) < N && N <= accumulate_sum(i + 1))) {
        i++;
    }

    i++;

    int x, y;
    if (i % 2 == 0) {
        x = 1;
        y = i;

        int gap = N - accumulate_sum(i - 1) - 1;
        cout << x + gap << "/" << y - gap << "\n";
    } else {
        x = i;
        y = 1;

        int gap = N - accumulate_sum(i - 1) - 1;
        cout << x - gap << "/" << y + gap << "\n";
    }

    return 0;
}

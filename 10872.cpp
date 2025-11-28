#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    long long r = 1;
    while (N >= 1) {
        r *= N--;
    }

    cout << r << "\n";
}
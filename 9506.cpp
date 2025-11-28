#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int N;

    while (true) {
        int sum = 0;
        vector<int> factors;
        cin >> N;

        if (N == -1) {
            break;
        }

        for (int i = 1; i < N; ++i) {
            if (N % i == 0) {
                sum += i;
                factors.push_back(i);
            }
        }

        if (sum == N) {
            cout << N << " = ";
            for (int factor : factors) {
                cout << factor;

                if (*(factors.rbegin()) != factor)
                    cout << " + ";
            }
        } else {
            cout << N << " is NOT perfect.";
        }
        cout << "\n";
    }

    return 0;
}
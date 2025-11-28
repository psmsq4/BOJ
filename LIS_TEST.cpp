#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int N;
    cin >> N;

    vector<int> test(N);
    for (int i = 0; i < N; ++i) {
        cin >> test[i];
    }

    vector<int> dp;
    for (int i = 0; i < N; ++i) {
        auto iter = lower_bound(dp.begin(), dp.end(), test[i]);
        if (iter == dp.end())
            dp.push_back(test[i]);
        else
            *iter = test[i];
    }

    cout << dp.size() << "\n";

    return 0;
}
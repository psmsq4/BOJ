#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> times(N);
    for (int i = 0; i < N; ++i) {
        cin >> times[i];
    }

    sort(times.begin(), times.end());
    int total = 0;
    vector<int> ps(N);
    for (int i = 0; i < N; ++i) {
        ps[i] = ps[i - 1] + times[i];
        total += ps[i];
    }

    cout << total << "\n";

    return 0;
}
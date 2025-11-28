#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> bin_permutation(N + 1, 0);
    bin_permutation[1] = 1;
    bin_permutation[2] = 2;

    for (int i = 3; i <= N; ++i) {
        bin_permutation[i] = (bin_permutation[i - 2] + bin_permutation[i - 1]) % 15746;
    }

    cout << bin_permutation[N] << "\n";

    return 0;
}
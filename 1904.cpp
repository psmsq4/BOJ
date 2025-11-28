#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<vector<string>> bin_permutation(N + 1, vector<string>());
    bin_permutation[1].push_back("1");
    bin_permutation[2].push_back("00");
    bin_permutation[2].push_back("11");

    for (int i = 3; i <= N; ++i) {
        for (string permutation : bin_permutation[i - 2]) {
            bin_permutation[i].push_back(permutation + "00");
        }
        for (string permutation : bin_permutation[i - 1]) {
            bin_permutation[i].push_back(permutation + "1");
        }
    }

    cout << bin_permutation[N].size() << "\n";

    return 0;
}
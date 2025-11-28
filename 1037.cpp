#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> submul(N);
    for (int i = 0; i < N; ++i) {
        cin >> submul[i];
    }

    sort(submul.begin(), submul.end());
    cout << *(submul.begin()) * *(submul.end() - 1) << "\n";
}
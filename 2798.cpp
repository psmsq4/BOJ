#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int N, M;
    cin >> N >> M;

    vector<int> cards(N, 0);

    for (int i = 0; i < N; ++i) {
        cin >> cards[i];
    }

    int max = 0;
    int tmp = 0;
    for (int i = 0; i < N - 2; ++i) {
        for (int j = i + 1; j < N - 1; ++j) {
            for (int k = j + 1; k < N; ++k) {
                tmp = cards[i] + cards[j] + cards[k];
                if (max < tmp && tmp <= M)
                    max = cards[i] + cards[j] + cards[k];
            }
        }
    }

    cout << max << "\n";

    return 0;
}
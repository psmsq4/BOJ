#include <iostream>
#include <unordered_map>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N;

    unordered_map<int, int> cards;
    int card;
    for (int i = 0; i < N; ++i) {
        cin >> card;
        cards[card]++;
    }

    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> card;
        cout << cards[card] << " ";
    }
    cout << "\n";
}
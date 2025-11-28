#include <iostream>
#include <map>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<int, bool> cards;
    int N;
    cin >> N;

    int tmp;
    for (int i = 0; i < N; ++i) {
        cin >> tmp;
        cards[tmp] = true;
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> tmp;
        cout << cards[tmp] << " ";
    }

    return 0;
}
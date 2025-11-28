#include <deque>
#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    deque<int> cards;
    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cards.push_back(i);
    }

    while (cards.size() > 1) {
        cards.pop_front();
        cards.push_back(cards.front());
        cards.pop_front();
    }

    cout << cards.front() << "\n";

    return 0;
}
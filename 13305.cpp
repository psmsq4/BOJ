#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<long long> distance(N - 1);
    vector<long long> price_per_liter(N);

    for (int i = 0; i < (N - 1); ++i) {
        cin >> distance[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> price_per_liter[i];
    }

    vector<long long>::iterator curr_pos = price_per_liter.begin();
    vector<long long>::iterator goal = --price_per_liter.end();
    long long total_price = 0;
    long long idx = 0;
    while (curr_pos != goal) {
        vector<long long>::iterator next_pos = curr_pos + 1;
        while (next_pos != goal && (*curr_pos) < (*next_pos)) {
            total_price += (*curr_pos) * distance[idx++];
            ++next_pos;
        }
        total_price += (*curr_pos) * distance[idx++];
        curr_pos = next_pos;
    }

    cout << total_price << "\n";

    return 0;
}
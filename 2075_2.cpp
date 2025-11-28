#include <cstdio>
#include <functional>
#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> total_pq;

    int num;
    for (int i = 0; i < N; ++i) {
        priority_queue<int> row_pq;
        for (int j = 0; j < N; ++j) {
            cin >> num;

            if (i >= 1) {
                if (total_pq.top() < num) {
                    total_pq.pop();
                    total_pq.push(num);
                }
            } else
                total_pq.push(num);
        }
    }

    cout << total_pq.top() << "\n";

    return 0;
}
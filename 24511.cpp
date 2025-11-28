#include <deque>
#include <iostream>
#include <map>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    map<int, bool> valid;
    deque<int> queuestack;
    for (int i = 0; i < N; ++i) {
        bool isStack;
        cin >> isStack;
        if (!isStack) {
            valid[i] = true;
        }
    }

    int tmp;
    for (int i = 0; i < N; ++i) {
        cin >> tmp;
        if (valid[i])
            queuestack.push_back(tmp);
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> tmp;

        queuestack.push_front(tmp);
        cout << queuestack.back() << " ";
        queuestack.pop_back();
    }
    cout << "\n";

    return 0;
}
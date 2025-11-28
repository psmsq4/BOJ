#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    string op;
    queue<int> q;
    for (int i = 0; i < N; ++i) {
        cin >> op;

        if (op == "push") {
            int elem;
            cin >> elem;

            q.push(elem);
        } else if (op == "front") {
            if (q.size() == 0)
                cout << -1 << "\n";
            else
                cout << q.front() << "\n";
        } else if (op == "back") {
            if (q.size() == 0)
                cout << -1 << "\n";
            else
                cout << q.back() << "\n";
        } else if (op == "size") {
            cout << q.size() << "\n";
        } else if (op == "pop") {
            if (q.size() == 0)
                cout << -1 << "\n";
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        } else if (op == "empty") {
            cout << q.empty() << "\n";
        } else if (op == "size") {
            cout << q.size() << "\n";
        }
    }

    return 0;
}
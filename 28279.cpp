#include <deque>
#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int op;
    deque<int> dq;

    for (int i = 0; i < N; ++i) {
        int input;

        cin >> op;
        switch (op) {
        case 1:
            cin >> input;
            dq.push_front(input);
            break;
        case 2:
            cin >> input;
            dq.push_back(input);
            break;
        case 3:
            if (dq.size() == 0)
                cout << -1 << "\n";
            else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
            break;
        case 4:
            if (dq.size() == 0)
                cout << -1 << "\n";
            else {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
            break;
        case 5:
            cout << dq.size() << "\n";
            break;
        case 6:
            cout << dq.empty() << "\n";
            break;
        case 7:
            if (dq.size() == 0)
                cout << -1 << "\n";
            else {
                cout << dq.front() << "\n";
            }
            break;
        case 8:
            if (dq.size() == 0)
                cout << -1 << "\n";
            else {
                cout << dq.back() << "\n";
            }
            break;
        }
    }

    return 0;
}
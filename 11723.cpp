#include <iostream>
#include <set>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    set<int> all_set;
    for (int i = 1; i <= 20; ++i) {
        all_set.insert(i);
    }
    set<int> empty_set;
    set<int> ans;
    string op;
    int operand;

    for (int i = 0; i < N; ++i) {
        cin >> op;

        if (op == "add") {
            cin >> operand;

            ans.insert(operand);
        } else if (op == "remove") {
            cin >> operand;

            ans.erase(operand);
        } else if (op == "check") {
            cin >> operand;

            if (ans.find(operand) == ans.end())
                cout << 0 << "\n";
            else
                cout << 1 << "\n";
        } else if (op == "toggle") {
            cin >> operand;

            if (ans.find(operand) == ans.end())
                ans.insert(operand);
            else
                ans.erase(operand);
        } else if (op == "all") {
            ans = all_set;
        } else if (op == "empty") {
            ans = empty_set;
        }
    }

    return 0;
}
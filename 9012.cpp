#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    stack<bool> parenthesis;
    string input;
    for (int i = 0; i < N; ++i) {
        bool is_valid = true;
        cin >> input;
        for (char c : input) {
            if (c == '(') {
                parenthesis.push(true);
            } else if (c == ')') {
                if (parenthesis.size() <= 0) {
                    is_valid = false;
                    break;
                } else {
                    parenthesis.pop();
                }
            }
        }
        if (is_valid && parenthesis.empty())
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";

        while (!parenthesis.empty())
            parenthesis.pop();
    }

    return 0;
}
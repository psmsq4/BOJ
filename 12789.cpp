#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    queue<int> lines;
    stack<int> dummy_space;
    int input;
    int ticket = 1;
    for (int i = 0; i < N; ++i) {
        cin >> input;
        lines.push(input);
    }

    bool is_valid = true;
    while (lines.size() || dummy_space.size()) {
        // cout << lines.front() << " ";
        if (lines.front() == ticket) {
            lines.pop();
            ticket++;
        } else if (dummy_space.size() != 0 && dummy_space.top() == ticket) {
            dummy_space.pop();
            ticket++;
        } else {
            dummy_space.push(lines.front());
            lines.pop();
        }

        if (lines.size() == 0 && dummy_space.size() != 0 && dummy_space.top() != ticket) {
            is_valid = false;
            break;
        }
    }

    cout << (is_valid ? "Nice" : "Sad") << "\n";

    return 0;
}
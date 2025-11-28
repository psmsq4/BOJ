#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    stack<int> account;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int num;
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> num;
        if (!num) {
            if (!account.size())
                continue;
            int tmp = account.top();
            sum -= tmp;
            account.pop();
        } else {
            account.push(num);
            sum += num;
        }
    }

    cout << sum << "\n";

    return 0;
}
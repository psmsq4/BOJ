#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // 이 코드는 NULL이 아닐 때 cin 받기 전에 cout을 수행하도록 한다. NULL이면 출력 버퍼에 계속 쌓아둔다.
    // cout.tie(NULL)이 의미하는 건 cin과의 연결을 끊어서 동기화를 하지 않겠다는 것.

    stack<char> parenthesis;
    string input;
    while (true) {
        bool is_valid = true;
        // getchar(); * 앞서 개행문자가 없으면 유효 문자열의 앞 문자 하나가 날아감. 안 쓰는게 좋을 듯.
        getline(cin, input);

        // cout << input << "\n";

        if (input.length() == 1 && input[0] == '.')
            break;

        for (char c : input) {
            if (c == '(' || c == '[') {
                parenthesis.push(c);
            } else if (c == ')' || c == ']') {
                if (parenthesis.size() <= 0) {
                    is_valid = false;
                    break;
                }
                if ((c == ')' && parenthesis.top() == '(') || (c == ']' && parenthesis.top() == '['))
                    parenthesis.pop();
                else {
                    is_valid = false;
                    break;
                }
            }
        }
        if (is_valid && parenthesis.empty())
            cout << "yes" << "\n";
        else
            cout << "no" << "\n";

        while (!parenthesis.empty())
            parenthesis.pop();
    }

    return 0;
}
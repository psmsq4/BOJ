#include <cstring>
#include <iostream>

using namespace std;

int cnt = 0;

// int recursion(string s, int l, int r) { <- s를 참조자로 넘겨주고 안 넘겨주고는 속도 차이가 어마무시하다.
//     if (l >= r)
//         return 1;
//     else if (s[l] != s[r])
//         return 0;
//     else
//         return recursion(s, l + 1, r - 1);
// }

// int isPalindrome(string s) { <- s를 참조자로 넘겨주고 안 넘겨주고는 속도 차이가 어마무시하다.
//     return recursion(s, 0, strlen(s) - 1);
// }

int isPalindrome(string s) {
    bool is_palindrome = true;
    int step = 0;
    while (true) {
        if (step >= s.length() / 2)
            break;
        if (s[step] != s[s.length() - 1 - step]) {
            is_palindrome = false;
            break;
        }
        step++;
    }

    cnt = step + 1;
    return is_palindrome;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    string input;
    for (int i = 0; i < N; ++i) {
        cin >> input;
        cout << isPalindrome(input) << " " << cnt << "\n";
        cnt = 0;
    }

    return 0;
}
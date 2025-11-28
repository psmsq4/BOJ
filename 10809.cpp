#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

int main(void)  {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    string S;
    int alpha[26];

    memset(alpha, -1, sizeof(alpha));

    cin >> S;
    for (int i = 0; i < S.length(); ++i)    {
        if (alpha[S[i] - 97] == -1)
            alpha[S[i] - 97] = i;
    }

    for (int i = 0; i < 26; ++i)    {
        cout << alpha[i] << " ";
    }

    return 0;
}
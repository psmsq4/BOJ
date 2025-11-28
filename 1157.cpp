#include <iostream>
#include <string>

using namespace std;

int main(void)  {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    int alpha[26] = {0,};
    string str;

    cin >> str;
    for (int i = 0; i < str.length(); ++i)  {
        str[i] = toupper(str[i]);
        alpha[str[i] - 65]++;
    }
    
    int max = 0;
    int max_index = 0;
    for (int i = 0; i < 26; ++i)    {
        if (max <= alpha[i]) {
            if (max == alpha[i])    {
                max_index = -1;
                continue;
            }
            max = alpha[i];
            max_index = i;
        }
    }

    if (max_index == -1)
        cout << '?' << endl;
    else
        cout << char(max_index + 65) << endl;

    return 0;
}
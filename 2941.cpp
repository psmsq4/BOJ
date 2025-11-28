#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(void)  {
    string str;
    string str1, str2;
    char *tmp;
    int cnt = 0;

    cin >> str;
    for (int i = 0; i < str.length(); ++i)   {
        if (str[i] == '=')  {
            if (str[i - 2] == 'd' && str[i - 1] == 'z')
            {
                cnt++;
                str[i - 2] = str[i - 1] = str[i] = NULL;
                // cout << str << endl;
            }
            else if (str[i-1] == 'c' || str[i-1] == 's' || str[i-1] == 'z')  {
                cnt++;
                str[i - 1] = str[i] = NULL;
                // cout << str << endl;
            }
        }
        else if (str[i] == '-') {
            if (str[i-1] == 'c' || str[i-1] == 'd') {
                str[i - 1] = str[i] = NULL;
                cnt++;
                // cout << str << endl;
            }
        }
        else if (str[i] == 'j') {
            if (str[i-1] == 'l' || str[i-1] == 'n') {
                str[i - 1] = str[i] = NULL;
                cnt++;
                // cout << str << endl;
            }
        }
    }

    for (int i = 0; i < str.length(); ++i)
        if (str[i] != NULL)
            cnt++;

    cout << cnt << endl;

    return 0;
}
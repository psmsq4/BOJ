#include <iostream>
#include <string>

using namespace std;

int main(void)  {
    string str;
    int flag = 1;

    cin >> str;
    
    for (int i = 0; i < str.length() / 2; ++i)  {
        if (str[i] != str[str.length() - 1 - i])    {
            flag = 0;
        }
    }

    cout << flag;

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

int main(void)  {
    string str;
    int num = 0;

    getline(cin, str);
    for (int i = 0; i < str.length(); ++i)  {
        if (str[i] != ' ' && (str[i+1] == ' ' || str[i+1] == '\0'))
            num++;
    }

    cout << num;

    return 0;
}
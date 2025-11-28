#include <iostream>
#include <string>

using namespace std;

int main(void)  {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    int total = 0;
    string dial[11] = {
        "NULL", "NULL", "NULL", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"
    };

    string str;
    cin >> str;

    for (int i = 0; i < str.length(); ++i)  {
        for (int j = 3; j <= 10; ++j)    {
            if (dial[j].find(str[i]) != string::npos)
                total += j;
        }
    }

    cout << total;

    return 0;
}
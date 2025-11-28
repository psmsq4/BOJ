#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)  {
    string str = "helloworld";
    string str1, str2;

    str1 = str.substr(0, 0);
    str2 = str.substr(1, 9);

    // cout << str1.append(str2);

    vector<int> a[2];

    a[0].push_back(1);
    a[1].push_back(100);

    cout << a[1].back();

    return 0;
}
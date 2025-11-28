#include <iostream>
using namespace std;

int main(void)  {
    int N;
    cin >> N;

    int long_num = N / 4;

    for (int i = 0; i < long_num; ++i)  {
        cout << "long ";
    }
    cout << "int";

    return 0;
}
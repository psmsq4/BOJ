#include <iostream>
using namespace std;

int main(void)  {
    int op1, op2;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> op1 >> op2)
    {
        cout << op1 + op2 << endl;
    }

    return 0;
}
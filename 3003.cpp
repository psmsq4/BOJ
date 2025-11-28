#include <iostream>

using namespace std;

int main(void)  {
    int Ans[6] = {1, 1, 2, 2, 2, 8};
    int Input[6];

    for (int i = 0; i < 6; ++i) {
        cin >> Input[i];
    }

    for (int i = 0; i < 6; ++i) {
        cout << Ans[i] - Input[i] << " ";
    }

    return 0;
}
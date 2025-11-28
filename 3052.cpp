#include <iostream>
#define FRACTION 42

using namespace std;

int main(void)  {
    int numerator;
    int remain[41] = {0,};

    for (int i = 0; i < 10; ++i)    {
        cin >> numerator;
        remain[numerator % FRACTION]++;
    }
    int remain_num = 0;

    for (int i = 0; i <= 41; ++i)    {
        if (remain[i] > 0)
            remain_num++;
    }

    cout << remain_num;

    return 0;
}
#include <iostream>
using namespace std;

int main(void)  {
    int stud_id;
    int stud[31] = {0,};

    for (int i = 0; i < 28; ++i)    {
        cin >> stud_id;
        stud[stud_id]++;
    }

    for (int i = 1; i <= 30; ++i)   {
        if (stud[i] == 0)   {
            cout << i << endl;
        }
    }

    return 0;
}
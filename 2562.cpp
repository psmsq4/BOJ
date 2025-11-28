#include <iostream>
using namespace std;

int main(void)  {
    int A[9];
    int max, idx;

    for (int i = 0; i < 9; ++i) {
        cin >> A[i];
        if (i == 0)
            max = A[0];
        else    {
            if (max < A[i]) { 
                max = A[i];
                idx = i;
            }
        }
    }
    
    cout << max << endl << (idx + 1);
    return 0;
}
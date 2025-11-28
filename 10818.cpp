#include <iostream>

using namespace std;

int main(void)  {
    int N;
    int *A;
    int max, min;

    cin >> N;
    A = new int[N];

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (i == 0) {
            max = A[0];
            min = A[0];
        }
        else    {
            if (max < A[i])
                max = A[i];
            if (min > A[i])
                min = A[i];
        }
    }

    cout << min << " " << max;

    delete []A;
    return 0;
}
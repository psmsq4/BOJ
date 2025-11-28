#include <iostream>

using namespace std;

int main(void)  {
    int N, M;
    int b1, b2;
    int *A;
    int tmp;

    cin >> N >> M;

    A = new int[N];
    for (int i = 0; i < N; ++i) {
        A[i] = i + 1;
    }

    for (int i = 0; i < M; ++i) {
        cin >> b1 >> b2;

        for (int j = 0; j < (b2 - b1 + 1) / 2; ++j)   {
            tmp = A[(b1 - 1) + j];
            A[(b1 - 1) + j] = A[(b2 - 1) - j];
            A[(b2 - 1) - j] = tmp;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << A[i] << " ";
    }
    
    delete []A;
    return 0;
}
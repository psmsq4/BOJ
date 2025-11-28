#include <iostream>
using namespace std;

int main(void)  {
    int N, M;
    int exc1, exc2;
    int *A;
    int tmp;

    cin >> N >> M;
    A = new int[N + 1];
    for (int i = 1; i <= N; ++i) {
        A[i] = i;
    }

    for (int i = 1; i <= M; ++i)    {
        cin >> exc1 >> exc2;

        tmp = A[exc1];
        A[exc1] = A[exc2];
        A[exc2] = tmp;
    }

    for (int i = 1; i <= N; ++i)    {
        cout << A[i] << " ";
    }

    delete []A;
    return 0;
}
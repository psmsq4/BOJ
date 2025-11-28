#include <iostream>

using namespace std;

int main(void)  {
    int N, M;
    int stt, end, num;
    int *A;

    cin >> N >> M;

    A = new int[N];
    for (int i = 0; i < M; ++i) {
        cin >> stt >> end >> num;

        for (int j = stt - 1; j < end; ++j) {
            A[j] = num;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << A[i] << " ";
    }

    return 0;
}
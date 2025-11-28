#include <iostream>

using namespace std;

int main(void)  {
    int N;
    int *A;
    int find;
    int cnt = 0;

    cin >> N;
    A = new int[N];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cin >> find;

    for (int i = 0; i < N; ++i) {
        if (A[i] == find)   
            cnt++;
    }

    cout << cnt;

    return 0;
}
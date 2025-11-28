#include <iostream>

using namespace std;

int main(void)  {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i)    {
        for (int j = 1; j <= N - i; ++j) {
            cout << " ";
        }
        for (int j = 1; j <= i * 2 - 1; ++j)    {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = N - 1; i >= 1; --i)    {
        for (int j = 1; j < N - i + 1; ++j) {
            cout << " ";
        }
        for (int j = 1; j <= i * 2 - 1; ++j)    {
            cout << "*";
        }
        cout << endl;
    }
}
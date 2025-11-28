#include <iostream>
#include <string>

using namespace std;

int main(void)  {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    int N, sum = 0;
    cin >> N;

    string list_number;
    cin >> list_number;

    for (int i = 0; i < N; ++i) {
        sum += static_cast<int>(list_number[i]) - 48;
    }

    cout << sum;

    return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

int main(void)  {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    int N;
    cin >> N;

    int width = pow(2, N) + 1;

    cout << width * width;

    return 0;
}

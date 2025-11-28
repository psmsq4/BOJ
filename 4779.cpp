#include <cmath>
#include <iostream>

using namespace std;

void cantor(string &target, int stt, int end) {
    if (end - stt == 0)
        return;

    for (int i = stt + (end - stt + 1) / 3; i < stt + (end - stt + 1) / 3 * 2; ++i) {
        target[i] = ' ';
    }

    cantor(target, stt, stt + (end - stt + 1) / 3 - 1);
    cantor(target, stt + (end - stt + 1) / 3 * 2, end);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    while (cin >> N) {
        string target(pow(3, N), '-');

        cantor(target, 0, target.length() - 1);

        cout << target << "\n";
    }
    /*
        eof를 검사하는 문제는 다음으로도 해결이 가능함.
        while (true)    {
            cin >> N;
            if (cin.eof())
                break;
        }
    */

    return 0;
}
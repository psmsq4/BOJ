#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int N;
    cin >> N;

    int cnt[2] = {0};
    for (int i = 1; i <= N; ++i) {
        int tmp = i;
        while (tmp % 2 == 0) {
            cnt[0]++;
            tmp /= 2;
        }

        tmp = i;
        while (tmp % 5 == 0) {
            cnt[1]++;
            tmp /= 5;
        }
    }

    cout << min(cnt[0], cnt[1]) << "\n";

    return 0;
}
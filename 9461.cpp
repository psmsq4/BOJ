#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    int N;
    bool calc = false;
    vector<long long> ans(101, 0);
    for (int i = 0; i < T; ++i) {
        cin >> N;

        if (!calc) {
            ans[1] = 1;
            ans[2] = 1;
            ans[3] = 1;

            for (int i = 4; i <= 100; ++i) {
                ans[i] = ans[i - 3] + ans[i - 2];
            }
            calc = true;
        }

        cout << ans[N] << "\n";
    }

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> nums(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    vector<int> dp(N + 1);
    dp[1] = nums[0];

    for (int i = 1; i <= N; ++i) {
        cout << "dp[" << i << "] = " << dp[i] << "\n";
    }
    cout << "\n";

    int ptr = 1;
    for (int i = 1; i < N; ++i) {
        if (nums[i] > dp[ptr]) {
            dp[++ptr] = nums[i];
        } else {
            int tmp = ptr;
            while (tmp > 1) {
                --tmp;
                if (nums[i] > dp[tmp]) {
                    dp[++tmp] = nums[i];
                    break;
                }
            }
            if (tmp == 1) {
                dp[1] = nums[i];
            }
        }
        for (int i = 1; i <= N; ++i) {
            cout << "dp[" << i << "] = " << dp[i] << "\n";
        }
        cout << "\n";
    }

    cout << ptr << "\n";

    return 0;
}
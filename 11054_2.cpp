#include <algorithm>
#include <deque>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(void) {
    int N;
    cin >> N;

    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    int peak;
    unordered_map<int, int> length;
    deque<int> dp_asc;
    deque<int> dp_des;
    for (int i = 0; i < N; ++i) {
        peak = nums[i];

        vector<int>::reverse_iterator nums_end = nums.rbegin();
        for (int j = 0; j < N; ++j) {
            if (j <= i) {
                if (nums[j] > peak)
                    continue;

                auto iter = lower_bound(dp_asc.begin(), dp_asc.end(), nums[j]);
                if (iter == dp_asc.end()) {
                    dp_asc.push_back(nums[j]);
                } else
                    *iter = nums[j];
            } else {
                if (*nums_end >= peak) {
                    nums_end++; /* 안 해주면 역순 수열 제조 불가능 */
                    continue;
                }

                auto iter = lower_bound(dp_des.rbegin(), dp_des.rend(), *nums_end);
                if (iter == dp_des.rend()) {
                    dp_des.push_front(*nums_end);
                } else
                    *iter = *nums_end;

                nums_end++;
            }
        }

        // cout << "peak: " << peak << " | ";
        // for (auto num : dp_asc)
        //     cout << num << " ";
        // for (auto num : dp_des)
        //     cout << num << " ";
        // cout << "\n";

        if (length[peak] < dp_asc.size() + dp_des.size())
            length[peak] = dp_asc.size() + dp_des.size();

        dp_asc.clear();
        dp_des.clear();
    }

    int MAX = INT32_MIN;
    for (auto len : length) {
        if (MAX < len.second)
            MAX = len.second;
    }

    cout << MAX << "\n";

    return 0;
}
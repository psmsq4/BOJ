#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int N;
    cin >> N;

    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    // LIS[i]: i번째 원소에서 끝나는 가장 긴 증가 부분 수열의 길이
    vector<int> LIS(N, 1);
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                LIS[i] = max(LIS[i], LIS[j] + 1);
            }
        }
    }

    // LDS[i]: i번째 원소에서 시작하는 가장 긴 감소 부분 수열의 길이
    vector<int> LDS(N, 1);
    for (int i = N - 2; i >= 0; --i) {
        for (int j = i + 1; j < N; ++j) {
            if (nums[i] > nums[j]) {
                LDS[i] = max(LDS[i], LDS[j] + 1);
            }
        }
    }

    // 각 위치를 peak로 하는 바이토닉 수열의 최대 길이
    int maxLength = 0;
    for (int i = 0; i < N; ++i) {
        maxLength = max(maxLength, LIS[i] + LDS[i] - 1);
    }

    cout << maxLength << "\n";

    return 0;
}
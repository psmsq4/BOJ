#include <iostream>
#include <vector>

using namespace std;

int SPLIT_MAX_LENGTH = INT32_MIN;

void binary_search(vector<int> &lens, int &N, long long stt, long long end) {
    long long mid = (stt + end) / 2;
    if (stt > end || mid == 0)
        return;

    int split_num = 0;
    for (int i = 0; i < lens.size(); ++i) {
        split_num += (lens[i] / mid);
    }
    // cout << "mid: " << mid << ", split_num: " << split_num << "\n";

    if (split_num >= N) {
        if (SPLIT_MAX_LENGTH < mid)
            SPLIT_MAX_LENGTH = mid;
        binary_search(lens, N, mid + 1, end);
    } else {
        binary_search(lens, N, stt, mid - 1);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K, N;
    cin >> K >> N;

    vector<int> lens(K);
    long long MAX_LENGTH = INT32_MIN;
    for (int i = 0; i < K; ++i) {
        cin >> lens[i];
        if (MAX_LENGTH < lens[i])
            MAX_LENGTH = lens[i];
    }

    binary_search(lens, N, 1ll, MAX_LENGTH);
    cout << SPLIT_MAX_LENGTH << "\n";

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

long long SPLIT_MAX_LENGTH = INT32_MIN;

void binary_search(vector<int> &lens, int &M, long long stt, long long end) {
    long long mid = (stt + end) / 2;
    if (stt > end)
        return;

    long long split_length = 0;
    for (int i = 0; i < lens.size(); ++i) {
        if (lens[i] - mid <= 0)
            continue;
        else {
            split_length += (lens[i] - mid);
        }
    }
    // cout << "mid: " << mid << ", split_num: " << split_num << "\n";

    if (split_length >= M) {
        if (SPLIT_MAX_LENGTH < mid)
            SPLIT_MAX_LENGTH = mid;
        binary_search(lens, M, mid + 1, end);
    } else {
        binary_search(lens, M, stt, mid - 1);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> trees(N);
    long long MAX_LEN = INT32_MIN;
    for (int i = 0; i < N; ++i) {
        cin >> trees[i];
        if (MAX_LEN < trees[i])
            MAX_LEN = trees[i];
    }

    binary_search(trees, M, 0ll, MAX_LEN);

    cout << SPLIT_MAX_LENGTH << "\n";

    return 0;
}
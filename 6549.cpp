#include <climits>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

long long MAX = LONG_MIN;

map<long long, long long> dfs(vector<long long> &heights, long long stt, long long end, long long is_left) {
    if (stt == end) {
        map<long long, long long> ans;
        if (MAX < heights[stt])
            MAX = heights[stt];
        ans[heights[stt]] = 1;
        return ans;
    }

    long long mid = (stt + end) / 2;
    map<long long, long long> left = dfs(heights, stt, mid, true);       // ans[left] 채워짐
    map<long long, long long> right = dfs(heights, mid + 1, end, false); // ans[right] 채워짐

    for (auto &l : left) {
        auto matched_right = right.lower_bound(l.first);
        if (matched_right == right.end())
            continue;
        if (MAX < l.first * (matched_right->second + l.second))
            MAX = l.first * (matched_right->second + l.second);
    }
    for (auto &r : right) {
        auto matched_left = left.lower_bound(r.first);
        if (matched_left == left.end())
            continue;
        if (MAX < r.first * (matched_left->second + r.second))
            MAX = r.first * (matched_left->second + r.second);
    }

    if (stt == 0 && heights.size() - 1 == end)
        return left;

    map<long long, long long> ans;
    long long min;
    long long width = 2;
    if (is_left) {
        min = heights[end];
        ans[min] = 1;
        for (long long i = end - 1; i >= stt; --i) {
            if (min > heights[i]) {
                min = heights[i];
            }

            ans[min] = width;
            width++;
        }
    } else {
        min = heights[stt];
        ans[min] = 1;
        for (long long i = stt + 1; i <= end; ++i) {
            if (min > heights[i]) {
                min = heights[i];
            }

            ans[min] = width;
            width++;
        }
    }

    return ans;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N = 1;
    while (true) {
        cin >> N;

        if (N == 0)
            break;

        vector<long long> heights(N);
        for (long long i = 0; i < N; ++i) {
            cin >> heights[i];
        }

        dfs(heights, 0, N - 1, false);

        cout << MAX << "\n";
        MAX = LONG_MIN;
    }

    return 0;
}
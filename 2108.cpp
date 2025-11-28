#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> nums(N);
    map<int, int> cnts;
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
        cnts[nums[i]]++;
        sum += nums[i];
    }

    cout << int(round(sum / (double)N)) << "\n";

    sort(nums.begin(), nums.end());
    cout << nums[N / 2] << "\n";

    pair<int, int> max_cnt = {0, 0};
    pair<int, int> sub_max_cnt = {0, 0};

    set<int> tmp;
    for (auto cnt : cnts) {
        if (max_cnt.second < cnt.second) {
            max_cnt = cnt;
            tmp.clear();
            tmp.insert(cnt.first);
        } else if (max_cnt.second == cnt.second) {
            max_cnt = cnt;
            tmp.insert(cnt.first);
        }
    }
    // set<int>의 iterator는 random access가 아니기 때문에 begin() + 1과 같이 쓸 수 없습니다.
    // 두 번째 원소에 접근하려면 iterator를 직접 증가시켜야 합니다.
    if (tmp.size() > 1) {
        auto it = tmp.begin();
        ++it;
        cout << *it << "\n";
    } else {
        cout << max_cnt.first << "\n";
    }

    cout << *(nums.end() - 1) - *(nums.begin()) << "\n";

    return 0;
}
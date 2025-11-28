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

    vector<int> nums;
    int tmp;
    for (int i = 0; i < N; ++i) {
        cin >> tmp;
        nums.push_back(tmp);
    }

    set<int> orders(nums.begin(), nums.end());
    map<int, int> maps;

    int idx = 0;
    for (auto &order : orders) {
        maps[order] = idx;
        idx++;
    }

    for (auto &num : nums) {
        cout << maps[num] << " ";
    }
    cout << "\n";

    return 0;
}
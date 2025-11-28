#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, string>> infos(N);

    for (auto &info : infos) {
        cin >> info.first >> info.second;
    }

    /* sort()는 불안정 정렬을 수행하므로 stable_sort를 써야함. */
    stable_sort(infos.begin(), infos.end(), [](pair<int, string> p1, pair<int, string> p2) {
        return p1.first < p2.first;
    });

    for (auto &info : infos) {
        cout << info.first << " " << info.second << "\n";
    }

    return 0;
}
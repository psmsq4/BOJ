#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

typedef long long ll;
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    map<int, int> bags;
    priority_queue<pair<ll, ll>> vals;

    int weight, value;
    for (int i = 0; i < N; ++i) {
        cin >> weight >> value;
        vals.push(make_pair(value, weight));
    }

    int bag;
    for (int i = 0; i < K; ++i) {
        cin >> bag;
        bags[bag]++;
    }

    ll sum = 0;
    for (int i = 0; i < N; ++i) {
        auto val = vals.top();
        vals.pop();

        auto iter = bags.lower_bound(val.second); // val.second == 보석 무게
        if (iter != bags.end()) {
            bags[(*iter).first]--;
            if (bags[(*iter).first] == 0)
                bags.erase(iter);

            sum += val.first;
        }
    }

    cout << sum << "\n";

    return 0;
}

/* 일반 정렬로 풀기 (더 빠름)
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

typedef long long ll;
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    map<int, int> bags;
    vector<pair<ll, ll>> vals(N);

    for (int i = 0; i < N; ++i) {
        cin >> vals[i].first >> vals[i].second;
    }
    sort(vals.begin(), vals.end(), [](pair<ll, ll> a, pair<ll, ll> b) {
        return a.second > b.second;
    });

    int bag;
    for (int i = 0; i < K; ++i) {
        cin >> bag;
        bags[bag]++;
    }

    ll sum = 0;
    for (int i = 0; i < N; ++i) {
        auto iter = bags.lower_bound(vals[i].first);
        if (iter != bags.end()) {
            bags[(*iter).first]--;
            if (bags[(*iter).first] == 0)
                bags.erase(iter);

            sum += vals[i].second;
        }
    }

    cout << sum << "\n";

    return 0;
}
*/
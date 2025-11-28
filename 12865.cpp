#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct obj {
    int weight;
    int value;

    obj() : weight(0), value(0) {}
    obj(int weight, int value) : weight(weight), value(value) {}
    bool operator==(const obj &ref) const {
        return weight == ref.weight && value == ref.value;
    }

    bool operator<(const obj &ref) const {
        if (weight != ref.weight) {
            return weight < ref.weight;
        }
        return value < ref.value;
    }
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<obj> objs(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> objs[i].weight >> objs[i].value;
    }

    vector<set<obj>> dp(N + 1, set<obj>());
    dp[0].insert(obj());
    int max_value;
    if (objs[1].weight <= K) {
        dp[1].insert(objs[1]);
        max_value = objs[1].value;
    } else {
        max_value = 0;
    }

    for (int i = 2; i <= N; ++i) {
        for (int j = 0; j < i; ++j) {
            for (auto prev : dp[j]) {
                /* 무게 초과 시 dp[i]에 추가되지 않으므로 지수적으로 늘어나지는 않을 것이다. */
                if (prev.weight + objs[i].weight <= K) {
                    dp[i].insert(obj(prev.weight + objs[i].weight, prev.value + objs[i].value));
                    if (max_value < prev.value + objs[i].value)
                        max_value = prev.value + objs[i].value;
                }
            }
        }
    }

    // for (auto a : dp) {
    //     for (auto b : a) {
    //         cout << "(" << b.weight << ", " << b.value << ") ";
    //     }
    //     cout << "\n";
    // }

    cout << max_value << "\n";

    return 0;
}
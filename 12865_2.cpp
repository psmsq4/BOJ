#include <iostream>
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
    /* IDEA: 무게로 인덱싱하는 DP 기법 */
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<obj> objs(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> objs[i].weight >> objs[i].value;
    }

    vector<int> dp(K + 1, 0);
    for (int i = 1; i <= N; i++) {
        for (int j = K; j >= objs[i].weight; --j) {
            dp[j] = max(dp[j], dp[j - objs[i].weight] + objs[i].value);
        }
        cout << "[";
        for (auto num : dp) {
            cout << num << ", ";
        }
        cout << "]\n";
    }

    cout << dp[K] << "\n";

    return 0;
}
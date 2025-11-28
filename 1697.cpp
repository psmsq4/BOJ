#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int bfs(int N, int K) {
    queue<pair<int, int>> q;
    vector<bool> tracking(2 * K + 1);

    q.push({N, 0});
    tracking[N] = true;
    int ans = 0;
    while (!q.empty()) {
        auto pos = q.front();
        q.pop();

        // cout << "depth: " << pos.second << ": " << pos.first << "\n";

        if (pos.first == K) {
            ans = pos.second;
            break;
        }

        // tracking: 이미 거쳐간 곳은 더 빠른 루트가 이미 있다는 의미로 더 이상 탐색하지 않는다.
        if (!tracking[pos.first - 1] && pos.first - 1 > 0) {
            tracking[pos.first - 1] = true;
            q.push({pos.first - 1, pos.second + 1});
        }
        // 현재값이 K이상이면 더 이상 양의 방향으로 증가하면 안 된다.
        if (!tracking[pos.first + 1] && pos.first < K) {
            tracking[pos.first + 1] = true;
            q.push({pos.first + 1, pos.second + 1});
        }
        // 현재값이 K이상이면 더 이상 양의 방향으로 증가하면 안 된다.
        if (!tracking[pos.first * 2] && pos.first < K) {
            tracking[pos.first * 2] = true;
            q.push({pos.first * 2, pos.second + 1});
        }
    }

    return ans;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    if (K <= N) {
        cout << N - K << "\n";
    } else {
        cout << bfs(N, K) << "\n";
    }

    return 0;
}
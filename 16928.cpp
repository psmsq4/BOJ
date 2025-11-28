#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> ls(101);
    int from, to;
    for (int i = 0; i < N; ++i) {
        cin >> from >> to;
        ls[from] = to;
    }
    for (int i = 0; i < M; ++i) {
        cin >> from >> to;
        ls[from] = to;
    }

    vector<int> g(101);
    queue<int> q;

    q.push(1);
    g[1] = 1;
    while (!q.empty()) {
        int c = q.front();
        q.pop();

        if (c == 100)
            break;

        for (int i = 1; i <= 6; ++i) {
            if (c + i <= 100 && !g[c + i]) {
                if (ls[c + i] && !g[ls[c + i]]) {
                    q.push(ls[c + i]);
                    g[ls[c + i]] = g[c] + 1;
                    g[c + i] = g[c] + 1;
                } else if (!ls[c + i]) {
                    /* 그냥 else로 해버리면?
                     * 논리적으로 !ls[c + i] || g[ls[c + i]]가 되어버림.
                     * 그럼, ls[c + i]가 참, 즉 !ls[c + i]가 거짓이면서 g[ls[c + i]]가 참이 될 수 있는가?
                     * 다시 말해, ls[c + i] && g[ls[c + i]] == true가 될 수 있는가?
                     * -> 그렇다. 이렇게 되면, !ls[c + i]만 의도한 것과 달리 실행결과가 달라질 수 있다. */
                    q.push(c + i);
                    g[c + i] = g[c] + 1;
                }
            }
        }
    }

    cout << g[100] - 1 << "\n";

    return 0;
}
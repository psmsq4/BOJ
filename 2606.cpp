#include <iostream>
#include <vector>

using namespace std;

int ans = 0;

void dfs(vector<vector<int>> &graph, vector<bool> &tracking, int V) {
    if (tracking[V])
        return;

    tracking[V] = 1;
    ans++;

    for (auto &v : graph[V]) {
        dfs(graph, tracking, v);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1);
    int from, to;
    for (int i = 0; i < M; ++i) {
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    vector<bool> tracking(N + 1);

    dfs(graph, tracking, 1);

    cout << ans - 1 << "\n";

    return 0;
}
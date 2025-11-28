#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>

using namespace std;

vector<int> ans;

void dfs(map<int, set<int>> &graph, unordered_map<int, bool> &tracking, int N, int V, int &num) {
    ans[V] = num++;
    if (tracking.size() == N || graph[V].empty())
        return;

    for (auto vertex = graph[V].rbegin(); vertex != graph[V].rend(); ++vertex) {
        if (tracking.count(*vertex))
            continue;

        tracking[*vertex] = true;
        dfs(graph, tracking, N, *vertex, num);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, V;
    cin >> N >> M >> V;

    ans.resize(N + 1);
    map<int, set<int>> graph;
    int from, to;
    for (int i = 1; i <= M; ++i) {
        cin >> from >> to;
        graph[from].insert(to);
        graph[to].insert(from);
    }

    unordered_map<int, bool> tracking;
    tracking[V] = true;

    int init = 1;
    dfs(graph, tracking, N, V, init);

    for (int i = 1; i <= N; ++i) {
        if (ans[i] == 0)
            cout << "0\n";
        else
            cout << ans[i] << "\n";
    }

    return 0;
}
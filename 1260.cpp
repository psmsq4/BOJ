#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>

using namespace std;

void dfs(map<int, set<int>> &graph, unordered_map<int, bool> &tracking, int N, int V) {
    cout << V << " ";
    if (tracking.size() == N || graph[V].empty())
        return;

    for (auto &vertex : graph[V]) {
        if (tracking.count(vertex))
            continue;

        tracking[vertex] = true;
        dfs(graph, tracking, N, vertex);
    }
}

void bfs(map<int, set<int>> &graph, unordered_map<int, bool> &tracking, queue<int> &depth, int N) {
    while (!depth.empty()) {
        int vertex = depth.front();
        depth.pop();

        cout << vertex << " ";

        for (auto &node : graph[vertex]) {
            if (tracking[node])
                continue;

            tracking[node] = true;
            depth.push(node);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, V;
    cin >> N >> M >> V;

    map<int, set<int>> graph;
    int from, to;
    for (int i = 1; i <= M; ++i) {
        cin >> from >> to;
        graph[from].insert(to);
        graph[to].insert(from);
    }

    unordered_map<int, bool> tracking;
    tracking[V] = true;

    dfs(graph, tracking, N, V);
    cout << "\n";

    /* --------------------------------- */
    tracking.clear();
    tracking[V] = true;

    queue<int> depth;
    depth.push(V);

    bfs(graph, tracking, depth, N);
    cout << "\n";

    return 0;
}
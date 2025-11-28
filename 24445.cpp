#include <algorithm>
#include <bitset>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, V;
    cin >> N >> M >> V;

    vector<vector<int>> graph(N + 1);
    int from, to;
    for (int i = 0; i < M; ++i) {
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    /* set 자료구조로 정렬하는 것보다 vector로 정렬없이 받은 다음 후처리로 정렬하는게 더 빠르다. */
    for (int i = 1; i <= N; ++i) {
        sort(graph[i].begin(), graph[i].end(), [](int &a, int &b) {
            return a > b;
        });
    }

    queue<int> bfs;
    vector<int> visited(N + 1);

    bfs.push(V);

    int order = 1;
    visited[V] = order++;

    while (!bfs.empty()) {
        int vertex = bfs.front();
        bfs.pop();

        for (auto iter = graph[vertex].begin(); iter != graph[vertex].end(); ++iter) {
            if (!visited[*iter]) {
                visited[*iter] = order++;
                bfs.push(*iter);
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        cout << visited[i] << "\n";
    }

    return 0;
}
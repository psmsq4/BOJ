#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>> &g, vector<int> &visited, int p, int v, int depth) {
    /*
        1 - 3
        |   |
        4 - 2
        A: {1, 2}
        B: {3, 4}
        짝수 길이 Cycle은 이분 그래프 정의를 만족함. (중요.)
        1 - 3
          \ |
            2
        A: {1}
        B: {3, 2} # 3과 2는 연결되어 이분 그래프 정의 불만족.
        홀수 길이 Cycle은 이분 그래프 정의를 만족하지 않음. (중요.)
    */
    visited[v] = depth;
    for (auto iter = g[v].begin(); iter != g[v].end(); ++iter) {
        if (*iter == p) {
            /* 양방향성에 의한 visited 오염을 방지 */
            /* Gemini는 아래와 같이 그래프 수정을 안 좋다고 했지만, 일단 채점했을 때 맞았음. */
            g[v].erase(iter);
            --iter;
            continue;
        }

        if (!visited[*iter]) {
            // return dfs(g, visited, v, *iter, depth + 1);
            // 위 코드는 true 시 다른 노드로 분기할 수 없게 만드는 치명적인 코드이다.
            if (!dfs(g, visited, v, *iter, depth + 1))
                return false;
        } else if (visited[*iter] && ((depth + 1) - visited[*iter]) % 2 != 0)
            // 홀수 사이클인지 파악.
            return false;
    }

    return true;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_num;
    cin >> test_num;
    for (int t = 0; t < test_num; ++t) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> g(V + 1);
        vector<int> visited(V + 1);
        int from, to;
        for (int e = 0; e < E; ++e) {
            cin >> from >> to;
            g[from].push_back(to);
            g[to].push_back(from);
        }

        bool ans = true;
        for (int i = 1; i <= V; ++i) {
            /* 끊어진 그래프도 검사하기 위한 로직 */
            if (!visited[i])
                ans = ans && dfs(g, visited, 0, i, 1);
        }

        cout << (ans ? "YES" : "NO") << "\n";
    }

    return 0;
}
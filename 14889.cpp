#include <deque>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
set<int> queue;
int N, M;

deque<vector<int>> teams;

bool permutation(int step, int input) {
    if (step != 0) {
        for (auto iter = queue.begin(); iter != queue.end(); ++iter) {
            if (*iter == input)
                return true;
        }
        queue.insert(input);
    }

    if (step == M) {
        if (queue.size() == 0)
            return false;

        vector<int> tmp;
        for (auto iter = queue.begin(); iter != queue.end(); ++iter) {
            // cout << *iter << " ";
            tmp.push_back(*iter);
        }
        // cout << "\n";
        teams.push_back(tmp);

        return false;
    }

    for (int i = 1; i <= N; ++i) {
        if (input >= i)
            continue;
        int op = permutation(step + 1, i);

        if (!op)
            queue.erase(queue.find(i));
        else if (op)
            continue;
    }
    return false;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    M = N / 2;

    vector<vector<int>> tables(N, vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> tables[i][j];
        }
    }

    permutation(0, 0);
    int MIN = INT32_MAX;

    int C = teams.size();
    for (int i = 0; i < C / 2; ++i) {
        int start_team = 0;
        int link_team = 0;
        for (int j = 0; j < M; ++j) {
            for (int k = 0; k < M; ++k) {
                if (j == k)
                    continue;

                start_team += tables[teams[i][j] - 1][teams[i][k] - 1];
                link_team += tables[teams[(C - 1) - i][j] - 1][teams[(C - 1) - i][k] - 1];
            }
        }
        if (MIN > abs(start_team - link_team))
            MIN = abs(start_team - link_team);
    }

    cout << MIN << "\n";

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

vector<int> queue;
int N, M;

bool permutation(int step, int input) {
    if (step != 0) {
        queue.push_back(input);
    }

    if (step == M) {
        if (queue.size() == 0)
            return false;

        for (auto iter = queue.begin(); iter != queue.end(); ++iter) {
            cout << *iter << " ";
        }
        cout << "\n";
        return false;
    }

    for (int i = 1; i <= N; ++i) {
        int op = permutation(step + 1, i);

        if (!op)
            queue.pop_back();
        else if (op)
            continue;
    }
    return false;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    permutation(0, 0);

    return 0;
}
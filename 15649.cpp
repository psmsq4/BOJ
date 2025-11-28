#include <iostream>
#include <vector>

using namespace std;

vector<int> queue;
int N, M;

int permutation(int step, int input) {
    if (step > M) {
        if (queue.size() == 0)
            return 2;

        for (auto iter = queue.begin(); iter != queue.end(); ++iter) {
            cout << *iter << " ";
        }
        cout << "\n";
        return 2;
    }

    if (step != 0) {
        for (auto iter = queue.begin(); iter != queue.end(); ++iter) {
            if (*iter == input)
                return 1;
        }
        queue.push_back(input);
    }

    for (int i = 1; i <= N; ++i) {
        int op = permutation(step + 1, i);

        if (op == 0)
            queue.pop_back();
        else if (op == 1)
            continue;
        else if (op == 2)
            break;
    }
    return 0;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    permutation(0, 0);

    return 0;
}
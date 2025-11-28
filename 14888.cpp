#include <iostream>
#include <map>
#include <vector>

using namespace std;

int N;
vector<int> A;
/* op[0] == +
 * op[1] == -
 * op[2] == *
 * op[3] == /
 */
int ops[4];
int MAX = INT32_MIN;
int MIN = INT32_MAX;

void put_op(int acc, int seq, int op) {
    switch (op) {
    case 0:
        acc = acc + A[seq + 1];
        break;
    case 1:
        acc = acc - A[seq + 1];
        break;
    case 2:
        acc = acc * A[seq + 1];
        break;
    case 3:
        acc = acc / A[seq + 1];
        break;
    }
    // cout << "acc: " << acc << ", seq: " << seq << " , op: " << op << "\n";
    if (seq == N - 2) { /* N으로 3이 입력되면, seq로 가능한 건 0과 1. */
        if (MAX < acc) {
            MAX = acc;
        }
        if (MIN > acc) {
            MIN = acc;
        }
        return;
    }

    /* pruning(promising 검사) 없어도 backtracking으로 볼 수 있음. */
    for (int i = 0; i < 4; ++i) {
        if (ops[i] > 0) {
            ops[i]--;
            put_op(acc, seq + 1, i);
            ops[i]++;
        }
    }
}

void root() {
    int acc = A[0];
    for (int i = 0; i < 4; ++i) {
        if (ops[i] > 0) {
            ops[i]--;
            put_op(acc, 0, i);
            ops[i]++;
        }
    }
} /* A0 [+-*∻] A1 A2 ...*/

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    int tmp;
    for (int i = 0; i < N; ++i) {
        cin >> tmp;
        A.push_back(tmp);
    }

    for (int i = 0; i < 4; ++i) {
        cin >> ops[i];
    }

    root();

    cout << MAX << "\n"
         << MIN << "\n";

    return 0;
}
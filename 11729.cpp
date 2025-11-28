#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;
vector<pair<int, int>> traces;

/* 하노이 타워. 내가 생각해서 푼 문제. 자랑스럽다. */
void hanoi(int N, int from, int aux, int to) {
    if (N == 0)
        return;

    cnt++;
    hanoi(N - 1, from, to, aux);
    traces.push_back({from, to});
    hanoi(N - 1, aux, from, to);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    hanoi(N, 1, 2, 3);
    cout << cnt << "\n";
    for (auto foot : traces) {
        cout << foot.first << " " << foot.second << "\n";
    }

    return 0;
}
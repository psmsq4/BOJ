#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> series(N + 1);
    vector<int> ps(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> series[i];
        ps[i] = ps[i - 1] + series[i];
    }

    int stt, end;

    for (int i = 0; i < M; ++i) {
        cin >> stt >> end;

        cout << ps[end] - ps[stt - 1] << "\n";
    }
    /*
        MEMO: (stt, end)구간 누적합은 (1 ~ end)누적합 - (1 ~ stt - 1)누적합으로 구하면 된다.
    */

    return 0;
}
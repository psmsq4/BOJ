#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int a = 0;
    int remainder = 0;
    vector<long long> remainers(M); // M의 나머지 범위 (0 <= r <= M - 1)을 커버한다.

    /* 오답 체크: cnt는 Worst Case로 (N + 1) * N / 2의 범위를 가지는 데,
     *           N이 65536만 되어도 int 범위를 넘어서는 테스트 케이스가 존재한다. */
    long long cnt = 0;

    /* 아이디어 검토:
     * -> 1부터 i까지 누적합의 M으로 나누었을 때의 나머지가 k일 경우,
     *    이전에 구했던 M으로 나누었을 때 나머지가 k인 누적합을 뺐을 때,
     *    나머지가 0이 되는 구간 누적합을 구할 수 있음.
     * -> 다만, 1부터 i까지 누적합 자체가 M으로 나누어 떨어질 경우에는
     *    따로 가산해주어야 정확히 계산할 수 있음.
     * -> 시간복잡도를 최소화 하기 위해서는 나머지 k의 누적합 개수가 얼마인지 바로 접근이 가능해야 하므로,
     *    나머지를 인덱스로 하는 배열을 선언하고 값을 나머지 k의 누적합 개수로 설정한다. (O(1)) */
    for (int i = 1; i <= N; ++i) {
        cin >> a;
        remainder = (remainder + a) % M;

        if (remainder == 0)
            cnt++;
        cnt += remainers[remainder];

        remainers[remainder]++;
    }
    cout << cnt << "\n";

    return 0;
}
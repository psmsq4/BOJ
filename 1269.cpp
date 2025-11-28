#include <iostream>
#include <unordered_set>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    unordered_set<int> result;
    int num;
    for (int i = 0; i < N; ++i) {
        cin >> num;
        result.insert(num);
    }

    /* set.erase()는 삭제한 원소 개수를 반환한다.
     * set은 중복 저장을 하지 않으니 최대 1만 반환한다. */

    for (int i = 0; i < M; ++i) {
        cin >> num;
        if (result.erase(num) != 1) {
            result.insert(num);
        }
    }

    cout << result.size() << "\n";

    return 0;
}
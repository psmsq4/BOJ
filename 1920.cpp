#include <iostream>
#include <unordered_map>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    unordered_map<int, int> MAP;
    cin >> N;
    int num;
    for (int i = 0; i < N; ++i) {
        cin >> num;
        MAP[num] = 1;
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> num;
        cout << MAP[num] << "\n";
    }

    return 0;
}

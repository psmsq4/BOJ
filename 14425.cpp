#include <iostream>
#include <map>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    map<string, bool> words;
    string input;
    for (int i = 0; i < N; ++i) {
        cin >> input;
        words[input] = true;
    }

    int cnt = 0;
    for (int i = 0; i < M; ++i) {
        cin >> input;
        if (words[input])
            cnt++;
    }

    cout << cnt << "\n";

    return 0;
}
#include <iostream>
#include <unordered_map>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    unordered_map<string, bool> list;
    string a, b;
    for (int i = 0; i < N; ++i) {
        cin >> a >> b;
        if (a == "ChongChong" || b == "ChongChong") {
            list[a] = true;
            list[b] = true;
        }

        if (list[a] || list[b]) {
            list[a] = true;
            list[b] = true;
        }
    }

    int cnt = 0;
    for (auto elem : list) {
        if (elem.second)
            cnt++;
    }

    cout << cnt << "\n";

    return 0;
}
#include <iostream>
#include <unordered_map>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    bool isEnterVisible = false;
    string input;
    int cnt = 0;
    unordered_map<string, bool> list;
    for (int i = 0; i < N; ++i) {
        cin >> input;

        if (!isEnterVisible && input == "ENTER") {
            isEnterVisible = true;
            continue;
        } else if (isEnterVisible && input == "ENTER") {
            list.clear();
            continue;
        }

        if (!isEnterVisible) {
            continue;
        } else {
            if (list[input]) {
                continue;
            } else {
                cnt++;
                list[input] = true;
            }
        }
    }

    cout << cnt << "\n";

    return 0;
}
#include <iostream>
#include <map>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    map<string, string> logs;
    pair<string, string> log;
    for (int i = 0; i < N; ++i) {
        cin >> log.first >> log.second;
        logs[log.first] = log.second; // 이 방식은 기존 값이 있으면 덮어쓴다.
        // logs.insert(log); 이 방식으로 insert 시, 기존 값이 존재하면 갱신을 하지 않게 된다.
    }

    for (auto iter = logs.rbegin(); iter != logs.rend(); ++iter) {
        if (!iter->second.compare("enter")) {
            cout << iter->first << "\n";
        }
    }

    return 0;
}
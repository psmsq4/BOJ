#include <iostream>
#include <set>
#include <string>
#include <unordered_map>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    unordered_map<string, bool> list;
    string name;
    for (int i = 0; i < N; ++i) {
        cin >> name;
        list[name] = true;
    }

    set<string> intersection;
    for (int i = 0; i < M; ++i) {
        cin >> name;
        if (list[name]) {
            intersection.insert(name);
        }
    }

    cout << intersection.size() << "\n";
    for (auto name : intersection) {
        cout << name << "\n";
    }

    return 0;
}
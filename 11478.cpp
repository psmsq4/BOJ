#include <iostream>
#include <unordered_set>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    cin >> input;

    unordered_set<string> substr_list;
    int len = input.length();
    for (int i = 1; i <= len; ++i) {
        for (int j = 0; j + i <= len; ++j) {
            substr_list.insert(input.substr(j, i));
        }
    }

    cout << substr_list.size() << "\n";

    return 0;
}
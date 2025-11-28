#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main(void) {
    int N;
    cin >> N;

    set<string> non_dup_strings;
    string tmp;
    for (int i = 0; i < N; ++i) {
        cin >> tmp;
        non_dup_strings.insert(tmp);
    }

    vector<string> strings(non_dup_strings.begin(), non_dup_strings.end());

    sort(strings.begin(), strings.end(), [](string s1, string s2) {
        if (s1.length() == s2.length()) {
            // return strcmp(s1.c_str(), s2.c_str()) < 0 ? true : false;
            return s1 < s2;
        }
        return s1.length() < s2.length();
    });

    for (string str : strings) {
        cout << str << "\n";
    }

    return 0;
}
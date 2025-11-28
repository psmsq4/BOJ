#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    vector<vector<short>> ps(str.length() + 1, vector<short>(26));
    int idx = 1;
    int alpha_idx;
    for (char &c : str) {
        alpha_idx = c - 97;

        ps[idx] = ps[idx - 1];
        ps[idx][alpha_idx] = ps[idx - 1][alpha_idx] + 1;
        idx++;
    }

    int q;
    cin >> q;
    char c;
    int stt, end;
    for (int i = 0; i < q; ++i) {
        cin >> c >> stt >> end;
        stt++;
        end++;
        alpha_idx = c - 97;

        cout << ps[end][alpha_idx] - ps[stt - 1][alpha_idx] << "\n";
    }

    return 0;
}
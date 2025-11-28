#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void) {
    int N;
    stack<int> st;
    cin >> N;

    vector<int> vt(N);

    char *ans = new char[N * 2];
    int idx = 0;
    int cnt = 1;
    int desc_top;

    for (int i = 0; i < N; ++i) {
        cin >> vt[i];
        if (i == 0) {
            for (idx = 0; idx < vt[0]; idx++) {
                ans[idx] = '+';
            }
            desc_top = vt[0];
            continue;
        }

        if (desc_top < vt[i]) {
            for (int j = 0; j < cnt; ++j) {
                ans[idx++] = '-';
            }
            cnt = 1;

            for (int j = desc_top; j < vt[i]; ++j) {
                ans[idx++] = '+';
            }
            desc_top = vt[i];
        } else if (desc_top > vt[i]) {
            if (vt[i - 1] < vt[i] && vt[i] < desc_top) {
                cout << "NO\n";
                delete[] ans;
                return 0;
            }
            cnt++;
        }
    }
    for (int i = 0; i < cnt; ++i)
        ans[idx++] = '-';

    for (int i = 0; i < idx; ++i) {
        cout << ans[i] << "\n";
    }

    delete[] ans;
    return 0;
}
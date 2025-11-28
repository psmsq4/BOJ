#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int N, k;
    cin >> N >> k;

    vector<int> victims(N + 1);
    for (int i = 1; i <= N; ++i) {
        victims[i] = i;
    }

    int ptr = 0;
    int idx = 1;
    int cnt = N;
    cout << "<";
    while (cnt > 0) {
        while (true) {
            if (idx > N)
                idx = 1;

            if (victims[idx] != 0) {
                ptr++;
            }

            if (ptr == k)
                break;

            idx++;
        }
        if (cnt == 1)
            cout << victims[idx];
        else
            cout << victims[idx] << ", ";
        victims[idx] = 0;

        ptr = 0;
        cnt--;
    }
    cout << ">\n";

    return 0;
}
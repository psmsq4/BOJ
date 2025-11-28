#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_num;
    cin >> test_num;

    for (int t = 0; t < test_num; ++t) {
        int N;
        int input;
        cin >> N;
        priority_queue<int, vector<int>, less<int>> desc;   // 최대힙
        priority_queue<int, vector<int>, greater<int>> asc; // 최소힙
        vector<int> ans;
        /*
            MIN_HEAP(> MID)               9    9 10 11    10 11

            MID               ->  9    -> 8 -> 8       -> 9         ※ MIN_HEAP과 MAX_HEAP의 균형이 맞을 때까지 중앙값의 위치를 옮긴다.

            MAX_HEAP(< MID)       8 7     7    7          8 7
        */

        cin >> input;
        ans.push_back(input);

        for (int i = 2; i <= N; ++i) {
            cin >> input;
            if (ans.back() < input)
                asc.push(input);
            else
                desc.push(input);

            if (i % 2 == 1) {
                if (asc.size() == desc.size()) {
                    ans.push_back(ans.back());
                } else if (asc.size() > desc.size()) {
                    desc.push(ans.back());
                    ans.push_back(asc.top());
                    asc.pop();
                } else if (asc.size() < desc.size()) {
                    asc.push(ans.back());
                    ans.push_back(desc.top());
                    desc.pop();
                }
            }
        }

        cout << ans.size() << "\n";
        int idx = 1;
        for (int &a : ans) {
            cout << a << " ";
            if (idx % 10 == 0)
                cout << "\n";
            idx++;
        }
        cout << "\n";
    }

    return 0;
}
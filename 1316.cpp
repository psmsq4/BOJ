#include <iostream>
#include <string>
#include <vector>

int main(void)  {
    using namespace std;
    int N;
    string *str;
    int ans = 0;

    cin >> N;
    str = new string[N];

    for (int i = 0; i < N; ++i) {
        vector<int> group[26];
        bool flag = true;
        cin >> str[i];

        for (int j = 0; j < str[i].length(); ++j)   {
            group[str[i][j] - 97].push_back(j);
        }
        for (int k = 0; k < 26; ++k)
        {
            for (int j = 1; j < group[k].size(); ++j)
            {
                // cout << "k: " << k << ", " << group[k][j] << " ";
                if (group[k][j] - group[k][j - 1] > 1)
                    flag = false;
            }
            // cout << endl;
        }
        if (flag)
            ans++;
    }

    cout << ans;

    return 0;
}
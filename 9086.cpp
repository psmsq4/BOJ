#include <iostream>
#include <string>
using namespace std;

int main(void)  {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    int N, length;
    cin >> N;

    string *strs = new string[N];

    for (int i = 0; i < N; ++i) {
        cin >> strs[i];
        length = strs[i].length();
        cout << strs[i][0] << strs[i][length - 1];
        cout << endl;
    }
    
    delete []strs;
    return 0;
}
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    int tmp;
    while (b != 0) {
        tmp = b;
        b = a % b;
        a = tmp;
    }

    return a;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> street_trees(N);
    vector<int> diffs;
    for (int i = 0; i < N; ++i) {
        cin >> street_trees[i];

        if (i == 0)
            continue;

        diffs.push_back(street_trees[i] - street_trees[i - 1]);
    }

    /* 여러 개의 최대공약수를 구하는 요령
     * -> 인접한 두 수의 최대공약수를 먼저 구한 후 구한 최대공약수와 다음 수의 최대공약수를 구하면 됨.
     * -> 집합론적으로 봤을 때 교집합에 해당함.  */
    int a = diffs[0];
    for (int i = 1; i < N - 1; ++i) {
        a = gcd(max(a, diffs[i]), min(a, diffs[i]));
    }

    int cnt = 0;
    for (int diff : diffs) {
        cnt += (diff / a) - 1;
    }

    cout << cnt << "\n";

    return 0;
}
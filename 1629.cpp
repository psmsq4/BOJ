#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

long long dfs(long long A, long long B, long long C) {
    if (B == 0) {
        return 1;
    }
    if (B == 1) {
        return A % C;
    }

    long long half = dfs(A, B / 2, C) % C;
    if (B % 2 == 1) {
        return (half * half % C) * (A % C) % C;
    } else {
        return (half * half % C);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long A, B, C;
    cin >> A >> B >> C;

    long long result = dfs(A, B, C) % C;
    cout << result << "\n";

    return 0;
}
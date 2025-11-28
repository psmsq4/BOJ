#include <iostream>
#include <vector>

using namespace std;

int dp[21][21][21];
bool calculated = false;

void initDP() {
    // 초기화
    for (int i = 0; i < 21; ++i) {
        for (int j = 0; j < 21; ++j) {
            dp[0][i][j] = dp[i][0][j] = dp[i][j][0] = 1;
        }
    }

    // 한 번만 전체 테이블 계산
    for (int i = 1; i < 21; ++i) {
        for (int j = 1; j < 21; ++j) {
            for (int k = 1; k < 21; ++k) {
                if (i < j && j < k)
                    dp[i][j][k] = dp[i][j][k - 1] + dp[i][j - 1][k - 1] - dp[i][j - 1][k];
                else
                    dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] - dp[i - 1][j - 1][k - 1];
            }
        }
    }
    calculated = true;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;
    int result = 0;

    while (true) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;

        if (a <= 0 || b <= 0 || c <= 0) {
            result = 1;
        } else if (a > 20 || b > 20 || c > 20) {
            if (!calculated)
                initDP();
            result = dp[20][20][20];
        } else {
            if (!calculated)
                initDP();
            result = dp[a][b][c];
        }

        cout << "w(" << a << ", " << b << ", " << c << ") = " << result << "\n";
    }

    return 0;
}
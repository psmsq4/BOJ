#include <iostream>
#include <vector>

using namespace std;

long long dfs(long long A, long long B, long long C) {
    if (B == 1)
        return A % C;

    long long half;
    half = dfs(A, B / 2, C);
    if (B % 2 == 1) {
        return (half * half) % C * (A % C) % C;
    } else {
        return (half * half) % C;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N, K;
    cin >> N >> K;

    /* DP로 풀면 메모리 초과 및 O(N^2)으로 시간초과 */
    long long a = 1;
    long long b = 1;
    long long n = N;
    long long k = K;
    for (int i = 0; i < K; ++i) {
        a = (a * n--) % 1'000'000'007;
        b = (b * k--) % 1'000'000'007;
    }

    long long b_reverse = dfs(b, 1'000'000'005, 1'000'000'007);

    cout << a * b_reverse % 1'000'000'007 << "\n";

    /*
        (a % 1'000'000'007) / (b % 1'000'000'007) == (a / b) % 1'000'000'007
        뭔 놈의 역원은 역원...

        A == n / k로 정의한다.
        A의 모듈러 역원은
        A^(1'000'000'005)로 정의할 수 있다. <- 존나게 큰 수이지만, 이전에 구한 거듭제곱 분할정복 기법을 적용하면 될 것 같다.
        근데 A의 역원을 구해서 뭣 하는가?
        다시 생각해보자..

        (a % 1'000'000'007) == r1으로 두고
        (b % 1'000'000'007) == r2으로 두자.
        (a / b) % 1'000'000'007 == r3으로 두자.

        a의 역원을 a^(-1)
        b의 역원을 b^(-1)

        a/b (MOD m)은 a*b^(-1) (MOD m)
        그렇다면.. b의 역원을 구해야 한다는 건가..?
        b의 역원을 구해서 a와 곱하고 m으로 모듈러 연산..?
        애초에 저게 어떻게 성립할 수 있는거지? 페르마의 소정리랑은 무슨 관계가 있지?
        모듈러 나눗셈을 못하니까 모듈러 곱셉으로 변환하는게 목적이고, b를 b의 역원으로 바꿔야 곱셉이 가능하니까 그렇게 하는 것.
        그렇다면 b * b^(-1) (MOD m) == 1
        궁금한 건 a/b (MOD m) == a*b^(-1) (MOD m)이 왜 성립하냐는 것이다.
        15 / 5 (MOD 3) == 0
        5^(3-2) = 5
        15 * 5 (MOD 3) == 75 (MOD 3) == 0

        15 / 3 (MOD 7) == 5
        3^(7-2) = 243
        15 * 243 (MOD 7) == 5

        일단 MOD m에서 m이 소수이면 성립은 하는 것 같다.

        그러면 a를 구하고, b를 구하고 (단순 곱셉이므로 모듈러 분배법칙이 가능하므로 모듈러를 적용한다.)
        b의 역원을 구해서 a와 곱해주면 될 것으로 보인다.
    */

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

int main(void)  {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    int A, B;
    int rA = 0, rB = 0;

    cin >> A >> B;
    rA += A % 10 * 100; A /= 10;
    rA += A % 10 * 10; A /= 10;
    rA += A % 10; A /= 10;

    rB += B % 10 * 100; B /= 10;
    rB += B % 10 * 10; B /= 10;
    rB += B % 10; B /= 10;

    cout << (rA >= rB ? rA : rB) << endl;
}
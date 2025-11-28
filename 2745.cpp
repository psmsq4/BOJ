#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int main(void)  {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    string N;
    int B;
    cin >> N >> B;

    int diff = 0;
    int decimal = 0;

    for (int i = 0; i < N.length(); ++i) {
        if (N[i] >= 'A' && N[i] <= 'Z')
            diff = N[i] - 'A' + 10;
        else if (N[i] >= '0' && N[i] <= '9')
            diff = N[i] - 48;
        
        decimal += pow(B, (N.length() - (i + 1))) * diff;
    }   

    cout << decimal;

    return 0;
}
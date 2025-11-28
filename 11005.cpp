#include <iostream>
#include <stack>

using namespace std;

int main(void)  {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    int N, B;
    cin >> N >> B;

    unsigned char N_B[33]; // 2진수를 고려해야 한다. 10진수 범위가 10억으로 주어졌으므로, 최소 31bit
    stack<unsigned int> st;

    while (N != 0)  {
        int tmp;
        tmp = N % B;
        st.push(tmp);
        N /= B;
    }

    int i;
    int digit = st.size();
    for (i = 0; i < digit; ++i) {
        if (st.top() >= 10 && st.top() <= 35)   {
            N_B[i] = (st.top() - 10) + 'A';
        }
        else if (st.top() >= 0 && st.top() <= 9) {
            N_B[i] = st.top() + 48;
        }
        st.pop();
    }
    N_B[i] = '\0';

    cout << N_B << endl;
    
    return 0;
}
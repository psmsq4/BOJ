#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string formula;
    string num_str;
    int num_int;
    int result = 0;

    char is_minus_on = false;
    cin >> formula;
    for (int i = 0; i < formula.length(); ++i) {
        /* -가 최초로 나오고 난 이후 모든 피연산자는 음수 취급 후 더해주면 된다.
         * 그 이유는 - 이후 +가 나오면 괄호로 묶으면 분배법칙에 따라 피연산자가 모두 음수가 되고
         * -가 나오면 그냥 단순히 빼주면 되기 때문이다. */
        if (formula[i] == '+' || formula[i] == '-') {
            num_int = atoi(num_str.c_str());
            num_str.clear();

            if (is_minus_on) {
                result -= num_int;
            } else {
                result += num_int;
            }

            if (formula[i] == '-')
                is_minus_on = true;
        } else {
            num_str.push_back(formula[i]);
        }
    }

    /* stt: 마지막 피연산자에 대한 처리 */
    num_int = atoi(num_str.c_str());
    num_str.clear();

    if (is_minus_on) {
        result -= num_int;
    } else {
        result += num_int;
    }
    /* end */

    cout << result << "\n";

    return 0;
}
/*
    a - b + : prev == '-'
    a + b + : prev == '+'
    a + b - : prev == '-'
    a - b - : prev == '-'

    1 - 2 + 3 + 4 + 5 - 6 + 7
    1 - 2 = -1
    -1 - 3 = -4
    -4 - 4 = -8
    -8 - 5 = -13
    -13 - 6 = -19
    -19 - 7 = -26
*/
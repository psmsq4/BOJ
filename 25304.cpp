#include <iostream>
using namespace std;

int main(void)  {
    int total;
    int item_type_num;
    int item_price, item_amount;
    int re_total = 0;

    cin >> total;
    cin >> item_type_num;

    for (int i = 0; i < item_type_num; ++i)  {
        cin >> item_price >> item_amount;

        re_total = re_total + item_price * item_amount;
    }

    if (total == re_total)  
        cout << "Yes";
    else    
        cout << "No";

    return 0;
}
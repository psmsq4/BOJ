#include <iostream>
using namespace std;

enum    {
    QUARTER = 25,
    DIME = 10,
    NICKEL = 5,
    PENNY = 1,
};

int main(void)  {
    int test_num;
    int cent;
    int list[4];

    cin >> test_num;
    for (int i = 0; i < test_num; ++i)  {
        cin >> cent;
        
        list[0] = cent / QUARTER;
        cent -= list[0] * QUARTER;

        list[1] = cent / DIME;
        cent -= list[1] * DIME;

        list[2] = cent / NICKEL;
        cent -= list[2] * NICKEL;

        list[3] = cent / PENNY;
        cent -= list[3] * PENNY;

        cout << list[0] << " " << list[1] << " " << list[2] << " " << list[3] << "\n";
    }

    return 0;
}
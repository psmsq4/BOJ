#include <iostream>
#include <cmath>
using namespace std;

int main(void)  {
    int papper_cnt;
    int papper[100][2];

    cin >> papper_cnt;

    for (int i = 0; i < papper_cnt; ++i)    {
        cin >> papper[i][0] >> papper[i][1];
    }

    int step = 1;
    int x_diff = 0;
    int y_diff = 0;

    int total_papper_area = 100 * papper_cnt;
    int co_area = 0;

    while (step != papper_cnt)  {
        for (int i = 0, j = step; j < papper_cnt; i ++, j ++)  {
            x_diff = abs(papper[i][0] - papper[j][0]);
            y_diff = abs(papper[i][1] - papper[j][1]);
            if (x_diff < 10 && y_diff < 10)   {
                co_area += (10 - x_diff) * (10 - y_diff);
            }
        }
        step++;
    }

    cout << total_papper_area - co_area;

    return 0;
}
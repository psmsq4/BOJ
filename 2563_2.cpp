#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    int papper_cnt;
    bool papper[100][100] = {false, };
    int x, y;
    int max_x = 0, max_y = 0;

    cin >> papper_cnt;

    for (int i = 0; i < papper_cnt; ++i)
    {
        cin >> x >> y;
        x--; y--;
        if (x > max_x)
            max_x = x;
        if (y > max_y)
            max_y = y;
        for (int height = y; height < y + 10; ++height)    {
            for (int width = x; width < x + 10; ++width) {
                papper[height][width] = true;
            }
        }
    }

    int area_pixel_running_sum = 0;

    for (int height = 0; height < max_y + 10; ++height)   {
        for (int width = 0; width < max_x + 10; ++width)    {
            papper[height][width] ? area_pixel_running_sum++ : area_pixel_running_sum;
        }
    }

    cout << area_pixel_running_sum;

    return 0;
}
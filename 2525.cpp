#include <iostream>

using namespace std;

int main(void)  {
    int hour, minute;
    int requisite_time;

    cin >> hour >> minute;
    cin >> requisite_time;

    hour = hour + requisite_time / 60;
    minute = minute + requisite_time % 60;
    
    if (minute >= 60)   {
        hour = hour + minute / 60;
        minute = minute % 60;
    }
    if (hour >= 24) {
        hour = hour - 24;
    }

    cout << hour << " " << minute;

    return 0;
}
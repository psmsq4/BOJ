#include <iostream>
using namespace std;

int analyze_type(int dice[])   {
    int idx = 0;
    int max = 0;

    for (int i = 1; i <= 6; ++i) {
        if (dice[i] == 3)   {
            idx = i;
            break;
        }
        else if (dice[i] == 2)  {
            idx = i;
            break;
        }
        
        if (dice[i] == 1 && i > idx)  {
            idx = i;
        }
    }

    return idx;
}

int main(void)  {
    int dice[7] = {0, };
    int try_dice;
    int idx;
    int Answer = 0;

    for (int i = 0; i < 3; ++i) {
        cin >> try_dice;
        dice[try_dice]++;
    }

    idx = analyze_type(dice);
    switch(dice[idx])   {
        case 1:
            Answer = idx * 100;
            break;
        case 2:
            Answer = 1000 + idx * 100;
            break;
        case 3:
            Answer = 10000 + idx * 1000;
            break;
    }

    cout << Answer;

    return 0;
}
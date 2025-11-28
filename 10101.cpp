#include <cmath>
#include <iostream>
#include <set>

using namespace std;

int main(void) {
    set<unsigned int> angles;

    unsigned int angle;
    unsigned int sum = 0;
    for (int i = 0; i < 3; ++i) {
        cin >> angle;

        sum += angle;
        angles.insert(angle);
    }

    if (sum != 180) {
        cout << "Error" << "\n";
        return 0;
    }

    if (angles.size() == 3)
        cout << "Scalene" << "\n";
    else if (angles.size() == 2)
        cout << "Isosceles" << "\n";
    else if (angles.size() == 1)
        cout << "Equilateral" << "\n";

    return 0;
}
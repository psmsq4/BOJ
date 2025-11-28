#include <iostream>
#include <map>

using namespace std;

int main(void) {
    map<int, int> test;
    test[5] = 10;
    test[8] = 12;
    test[9] = 20;

    cout << test.lower_bound(8)->first << "\n";
}
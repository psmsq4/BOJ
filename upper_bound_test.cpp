#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);

    auto iter = upper_bound(a.begin(), a.end() - 1, 3);
    if (iter != a.end() - 1) {
        cout << *iter << "\n";
    } else {
        cout << "Not found in range, but last element is: " << *(a.end() - 1) << "\n";
    }
}
#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<unsigned short> &nums) {
    int position = 0;
    int inserted = 0;

    for (int i = 1; i < nums.size(); ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (nums[i] < nums[j]) {
                position = j + 1;
                break;
            }
        }

        inserted = nums[i];
        for (int j = i; j > position; --j) {
            nums[j] = nums[j - 1];
        }
        nums[position] = inserted;
    }
}

int main(void) {
    unsigned long long N;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    vector<unsigned short> digits;

    while (N != 0) {
        digits.push_back(static_cast<unsigned short>(N % 10));
        N /= 10;
    }

    insertionSort(digits);

    for (auto digit : digits) {
        cout << digit;
    }
    cout << "\n";

    return 0;
}
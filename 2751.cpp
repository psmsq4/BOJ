#include <ctime>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

int partition(int stt, int end, int pivot, vector<int> &nums) {
    int i, j;
    int pivotitem = nums[pivot];
    bool flag = false;
    int tmp;

    if (stt == pivot) {
        i = j = stt + 1;
        flag = true;
    } else
        i = j = stt;

    while (j <= end) {
        if (j == pivot) {
            j++;
            continue;
        }

        if (nums[j] < pivotitem) {
            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;

            if (i + 1 == pivot) {
                i += 2;
                flag = true;
            } else
                i++;
        }
        j++;
    }

    i = flag ? i - 1 : i;

    tmp = nums[pivot];
    nums[pivot] = nums[i];
    nums[i] = tmp;

    return i;
}

void quickSort(int stt, int end, vector<int> &nums) {
    if (stt >= end)
        return;

    int pivot = random() % (end - stt + 1) + stt;

    pivot = partition(stt, end, pivot, nums);

    quickSort(stt, pivot - 1, nums);
    quickSort(pivot + 1, end, nums);
}

int main(void) {
    int N;
    cin >> N;

    srand(time(NULL));

    vector<int> nums;
    int num;

    for (int i = 0; i < N; ++i) {
        cin >> num;
        nums.push_back(num);
    }

    quickSort(0, N - 1, nums);

    for (auto num : nums) {
        cout << num << "\n";
    }

    return 0;
}
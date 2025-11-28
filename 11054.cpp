#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> nums(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    vector<int> dp_asc(N + 1);
    dp_asc[1] = nums[0];

    // for (int i = 1; i <= N; ++i) {
    //     cout << "dp_asc[" << i << "] = " << dp_asc[i] << "\n";
    // }
    // cout << "\n";

    int ptr_asc = 1;
    int pivot = 0;
    for (int i = 1; i < N; ++i) {
        if (nums[i] > dp_asc[ptr_asc]) {
            dp_asc[++ptr_asc] = nums[i];
            pivot = i;
        } else if (nums[i] == dp_asc[ptr_asc]) {
            // pivot = i;
        } else {
            int tmp = ptr_asc;
            while (tmp > 1) {
                --tmp;
                if (nums[i] > dp_asc[tmp]) {
                    dp_asc[++tmp] = nums[i];
                    break;
                }
            }
            if (tmp == 1) {
                dp_asc[1] = nums[i];
            }
        }
        // for (int i = 1; i <= N; ++i) {
        //     cout << "dp_asc[" << i << "] = " << dp_asc[i] << "\n";
        // }
        // cout << "\n";
    }

    int pivotitem = nums[pivot];
    int ptr_des = 1;
    while (pivotitem == nums[pivot + 1]) {
        pivot++;
    }
    pivotitem = nums[pivot];

    // cout << "pivot: " << pivot << "\n";
    if (pivot == N - 1) {
        cout << ptr_asc << "\n";
        return 0;
    }

    vector<int> dp_des(N + 1);
    dp_des[1] = nums[pivot + 1];
    for (int i = pivot + 2; i < N; ++i) {
        if (pivotitem > nums[i] && dp_des[ptr_des] > nums[i]) {
            dp_des[++ptr_des] = nums[i];
        } else if (pivotitem > nums[i] && dp_des[ptr_des] < nums[i]) {
            int tmp = ptr_des;
            while (tmp > 1) {
                --tmp;
                if (nums[i] < dp_des[tmp]) {
                    dp_des[++tmp] = nums[i];
                    break;
                }
            }
            if (tmp == 1) {
                dp_des[1] = nums[i];
            }
        }
        // for (int i = 1; i <= N; ++i) {
        //     cout << "dp_des[" << i << "] = " << dp_des[i] << "\n";
        // }
        // cout << "\n";
    }
    if (dp_des[ptr_des] == pivotitem) {
        ptr_des = 0;
    }

    // cout << "ptr_asc(" << ptr_asc << ") + ptr_des(" << ptr_des << ") = " << ptr_asc + ptr_des << "\n";
    cout << ptr_asc + ptr_des << "\n";

    return 0;
}
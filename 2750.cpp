#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void merge(int stt, int end, vector<int> &raw) {
    vector<int> tmp;

    int left_ptr = stt;
    int right_ptr = (stt + end) / 2 + 1;
    int mid = (stt + end) / 2;

    while (left_ptr <= mid && right_ptr <= end) {
        if (raw[left_ptr] < raw[right_ptr]) {
            tmp.push_back(raw[left_ptr]);
            left_ptr++;
        } else {
            tmp.push_back(raw[right_ptr]);
            right_ptr++;
        }
    }

    if (left_ptr > mid) {
        while (right_ptr <= end) {
            tmp.push_back(raw[right_ptr]);
            right_ptr++;
        }
    } else if (right_ptr > end) {
        while (left_ptr <= mid) {
            tmp.push_back(raw[left_ptr]);
            left_ptr++;
        }
    }

    for (int i = stt; i <= end; ++i) {
        raw[i] = tmp[i - stt];
    }
}

void mergeSort(int stt, int end, vector<int> &raw) {
    if (stt >= end)
        return;

    int mid = (stt + end) / 2;

    mergeSort(stt, mid, raw);
    mergeSort(mid + 1, end, raw);
    merge(stt, end, raw);
}

int main(void) {
    int N;
    vector<int> raw;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int elem;
    for (int i = 0; i < N; ++i) {
        cin >> elem;
        raw.push_back(elem);
    }

    mergeSort(0, N - 1, raw);

    for (auto elem : raw) {
        cout << elem << "\n";
    }

    return 0;
}
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void merge(int stt, int end, vector<pair<int, string>> &raw) {
    vector<pair<int, string>> tmp;

    int left_ptr = stt;
    int right_ptr = (stt + end) / 2 + 1;
    int mid = (stt + end) / 2;

    while (left_ptr <= mid && right_ptr <= end) {
        /* stable 정렬을 위해서는 부등식에 등호가 반드시 필요하다. */
        if (raw[left_ptr].first <= raw[right_ptr].first) {
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

void mergeSort(int stt, int end, vector<pair<int, string>> &raw) {
    if (stt >= end)
        return;

    int mid = (stt + end) / 2;

    mergeSort(stt, mid, raw);
    mergeSort(mid + 1, end, raw);
    merge(stt, end, raw);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, string>> infos(N);

    for (auto &info : infos) {
        cin >> info.first >> info.second;
    }

    mergeSort(0, N - 1, infos);

    for (auto &info : infos) {
        cout << info.first << " " << info.second << "\n";
    }

    return 0;
}
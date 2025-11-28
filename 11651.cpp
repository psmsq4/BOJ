#include <iostream>
#include <vector>

using namespace std;

void merge(int stt, int end, vector<pair<int, int>> &raw) {
    vector<pair<int, int>> tmp;

    int left_ptr = stt;
    int right_ptr = (stt + end) / 2 + 1;
    int mid = (stt + end) / 2;

    while (left_ptr <= mid && right_ptr <= end) {
        if (raw[left_ptr].second < raw[right_ptr].second) {
            tmp.push_back(raw[left_ptr]);
            left_ptr++;
        } else if (raw[left_ptr].second == raw[right_ptr].second) {
            if (raw[left_ptr].first < raw[right_ptr].first) {
                tmp.push_back(raw[left_ptr]);
                left_ptr++;
            } else {
                tmp.push_back(raw[right_ptr]);
                right_ptr++;
            }
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

void mergeSort(int stt, int end, vector<pair<int, int>> &raw) {
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

    vector<pair<int, int>> coords;
    pair<int, int> tmp;
    for (int i = 0; i < N; ++i) {
        cin >> tmp.first >> tmp.second;
        coords.push_back(tmp);
    }

    mergeSort(0, N - 1, coords);

    for (auto coord : coords) {
        cout << coord.first << " " << coord.second << "\n";
    }

    return 0;
}
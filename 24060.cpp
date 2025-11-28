#include <iostream>
#include <vector>

using namespace std;

int cnt = 1;
int N, K, result = -1;

void merge(int stt, int end, vector<unsigned int> &raw) {
    vector<unsigned int> tmp;

    int left_ptr = stt;
    int right_ptr = (stt + end) / 2 + 1;
    int mid = (stt + end) / 2;

    while (left_ptr <= mid && right_ptr <= end) {
        if (raw[left_ptr] <= raw[right_ptr]) {
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
        if (cnt == K)
            result = tmp[i - stt];
        cnt++;
    }
}

void mergeSort(int stt, int end, vector<unsigned int> &raw) {
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

    cin >> N >> K;

    unsigned int input;
    vector<unsigned int> inputs;
    for (int i = 0; i < N; ++i) {
        cin >> input;
        inputs.push_back(input);
    }

    mergeSort(0, N - 1, inputs);
    cout << result << "\n";

    return 0;
}
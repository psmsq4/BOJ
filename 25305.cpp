#include <ctime>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

int partition(unsigned int stt, unsigned int end, unsigned int pivot, vector<unsigned int> &scores) {
    unsigned int i, j;
    unsigned int pivotitem = scores[pivot];
    bool flag = false;
    unsigned int tmp;

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

        if (scores[j] > pivotitem) {
            tmp = scores[i];
            scores[i] = scores[j];
            scores[j] = tmp;

            if (i + 1 == pivot) {
                i += 2;
                flag = true;
            } else
                i++;
        }
        j++;
    }

    i = flag ? i - 1 : i;

    // cout << i << " " << j << "\n";

    tmp = scores[pivot];
    scores[pivot] = scores[i];
    scores[i] = tmp;

    return i;
}

void quickSort(int stt, int end, vector<unsigned int> &scores) {
    if (stt >= end)
        return;

    int pivot = random() % (end - stt + 1) + stt;
    // cout << "pivot: " << pivot << "\n";

    pivot = partition(stt, end, pivot, scores);
    // for (auto i : scores) {
    //     cout << i << " ";
    // }
    // cout << "\n";
    quickSort(stt, pivot - 1, scores);
    quickSort(pivot + 1, end, scores);
}

int main(void) {
    int N, k;
    cin >> N >> k;

    srand(time(NULL));

    vector<unsigned int> scores;
    unsigned int score;

    for (int i = 0; i < N; ++i) {
        cin >> score;
        scores.push_back(score);
    }

    quickSort(0, N - 1, scores);

    cout << scores[k - 1] << "\n";

    return 0;
}
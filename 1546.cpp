#include <iostream>
using namespace std;

int main(void)  {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    float *score;
    float max = 0;
    float sum = 0, avg = 0;

    cin >> N; score = new float[N];

    for (int i = 0; i < N; ++i) {
        cin >> score[i];
        if (score[i] > max) {
            max = score[i];
        }
    }

    for (int i = 0; i < N; ++i) {
        score[i] = score[i] / max * 100;
        sum += score[i];
    }
    avg = sum / N;

    cout << avg;

    delete []score;
    return 0;
}
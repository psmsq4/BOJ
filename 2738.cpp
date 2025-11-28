#include <iostream>
#include <string>

using namespace std;

int main(void)  {
    int N, M;
    int MATRIX[2][100][100];
    int RESULT[100][100];

    cin >> N >> M;

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < M; ++k) {
                cin >> MATRIX[i][j][k];
            }
        }
    }

    for (int j = 0; j < N; ++j) {
        for (int k = 0; k < M; ++k) {
            RESULT[j][k] = MATRIX[0][j][k] + MATRIX[1][j][k];
            cout << RESULT[j][k] << " ";
        }
        cout << endl;
    }

    return 0;
}
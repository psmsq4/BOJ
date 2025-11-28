#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    vector<short> black(M + 1);
    vector<short> white(M + 1);
    vector<vector<int>> black_kset(N + 1, vector<int>(M - K + 1));
    vector<vector<int>> white_kset(N + 1, vector<int>(M - K + 1));

    /* 행 기준 누적합 */
    /*
        black: 왼쪽 상단 한 블록이 검정색인 체스판
        white: 왼쪽 상단 한 블록이 하얀색인 체스판
        black[i][j]: i행의 j번 째에서 black 체스판일 경우 색칠해야 하는 블록 개수의 누적합
    */
    int MIN = INT32_MAX;

    char color;
    char black_mode;
    char white_mode;
    for (int i = 1; i <= N; ++i) {
        if (i % 2 == 1) {
            black_mode = 'B';
            white_mode = 'W';
        } else {
            black_mode = 'W';
            white_mode = 'B';
        }
        for (int j = 1; j <= M; ++j) {
            cin >> color;

            if (color == black_mode) {
                white[j] = white[j - 1] + 1;
                black[j] = black[j - 1];
            } else {
                white[j] = white[j - 1];
                black[j] = black[j - 1] + 1;
            }

            if (j >= K) {
                black_kset[i][j - K] = black_kset[i - 1][j - K] + (black[j] - black[j - K]);
                white_kset[i][j - K] = white_kset[i - 1][j - K] + (white[j] - white[j - K]);
                if (i >= K) {
                    if (MIN > black_kset[i][j - K] - black_kset[i - K][j - K])
                        MIN = black_kset[i][j - K] - black_kset[i - K][j - K];
                    if (MIN > white_kset[i][j - K] - white_kset[i - K][j - K])
                        MIN = white_kset[i][j - K] - white_kset[i - K][j - K];
                }
            }

            black_mode = (black_mode == 'B') ? 'W' : 'B';
            white_mode = (white_mode == 'W') ? 'B' : 'W';
        }
    }

    // cout << "<< black_kset >>" << "\n";
    // for (auto a : black_kset) {
    //     for (auto b : a) {
    //         cout << b << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "<< white_kset >>" << "\n";
    // for (auto a : white_kset) {
    //     for (auto b : a) {
    //         cout << b << " ";
    //     }
    //     cout << "\n";
    // }

    // cout << "<< answer >>" << "\n";
    // int black_sum = 0;
    // int white_sum = 0;
    // for (int row = K; row <= N; ++row) {
    //     for (int col = K; col <= M; ++col) {
    //         for (int i = (row - K + 1); i <= row; ++i) {
    //             black_sum += black[i][col] - black[i][(col - K)];
    //             white_sum += white[i][col] - white[i][(col - K)];
    //         }
    //         // cout << "black_sum: " << black_sum << "\n";
    //         // cout << "white_sum: " << white_sum << "\n";
    //         if (black_sum < MIN)
    //             MIN = black_sum;
    //         if (white_sum < MIN)
    //             MIN = white_sum;

    //         black_sum = white_sum = 0;
    //     }
    // }

    cout << MIN << "\n";

    return 0;
}
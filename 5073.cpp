#include <cmath>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    set<unsigned int> state;
    vector<unsigned int> edges;

    int edge;
    while (true) {
        for (int i = 0; i < 3; ++i) {
            cin >> edge;

            state.insert(edge);
            edges.push_back(edge);
        }

        /* 종료 조건 */
        if (state.size() == 1 && *(state.begin()) == 0) {
            return 0;
        }

        /* 삼각형 유효성 검사 */
        int max = edges.front();
        int nonmax_sum = 0;
        for (int i = 1; i < 3; ++i) {
            if (max < edges[i])
                max = edges[i];
            nonmax_sum += edges[i];
        }
        nonmax_sum -= max;

        if (nonmax_sum <= max) {
            cout << "Invalid" << "\n";
            state.clear();
            edges.clear();
            continue;
        }

        /* 유효 시 상태 출력 */
        if (state.size() == 1)
            cout << "Equilateral" << "\n";
        else if (state.size() == 2)
            cout << "Isosceles" << "\n";
        else if (state.size() == 3)
            cout << "Scalene" << "\n";

        state.clear();
        edges.clear();
    }

    return 0;
}
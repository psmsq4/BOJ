#include <iostream>
#include <vector>

using namespace std;

short cnt[3] = {0};
vector<vector<short>> table;

void init(short N) {
    table.resize(N);
    for (auto &vec : table) {
        vec.resize(N);
    }
}

short dfs(pair<short, short> stt, pair<short, short> end) {
    if (stt == end) {
        cnt[table[stt.first][stt.second]]++;
        // cout << "(" << stt.first << ", " << stt.second << ")\n";
        return table[stt.first][stt.second];
    }

    pair<short, short> section_1_stt = stt;
    pair<short, short> section_1_end = {(stt.first + end.first) / 2, (stt.second + end.second) / 2};
    pair<short, short> section_2_stt = {(stt.first + end.first) / 2 + 1, stt.second};
    pair<short, short> section_2_end = {end.first, (stt.second + end.second) / 2};
    pair<short, short> section_3_stt = {stt.first, (stt.second + end.second) / 2 + 1};
    pair<short, short> section_3_end = {(stt.first + end.first) / 2, end.second};
    pair<short, short> section_4_stt = {(stt.first + end.first) / 2 + 1, (stt.second + end.second) / 2 + 1};
    pair<short, short> section_4_end = end;

    short section[5] = {0};
    section[1] = dfs(section_1_stt, section_1_end);
    section[2] = dfs(section_2_stt, section_2_end);
    section[3] = dfs(section_3_stt, section_3_end);
    section[4] = dfs(section_4_stt, section_4_end);

    if (section[1] == section[2] && section[2] == section[3] && section[3] == section[4]) {
        cnt[section[1]] -= 3;
        return section[1];
    } else {
        return 2;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short N;
    cin >> N;

    init(N);

    for (short i = 0; i < N; ++i) {
        for (short j = 0; j < N; ++j) {
            cin >> table[i][j];
        }
    }

    dfs({0, 0}, {N - 1, N - 1});

    cout << cnt[0] << "\n"
         << cnt[1] << "\n";

    return 0;
}
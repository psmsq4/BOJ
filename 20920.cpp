#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    string input;
    map<string, int> word_freq;
    for (int i = 0; i < N; ++i) {
        cin >> input;
        if (input.length() < M) // M 조건 필터링 완료
            continue;

        word_freq[input]++;
    }
    /*
        1. 자주 나오는 단어일수록 앞에 배치한다.
        2. 해당 단어의 길이가 길수록 앞에 배치한다.
        3. 알파벳 사전 순으로 앞에 있는 단어일수록 앞에 배치한다.
    */

    /* word_freq는 key 기준(알파벳 순서)으로 정렬되어 있음.
     * word_freq를 통해 알 수 있는 정보
     * 1. 어떤 단어 -> 길이는 어느 정도
     * 2. 얼마나 자주 */
    vector<pair<string, int>> sorted_word(word_freq.begin(), word_freq.end());
    sort(sorted_word.begin(), sorted_word.end(), [](pair<string, int> a, pair<string, int> b) {
        if (a.second == b.second) {                     /* 1번 정렬(조건 미충족 시): 단어 빈도 큰순 -> 내림차순 */
            if (a.first.length() == b.first.length()) { /* 2번 정렬(조건 미충족 시): 단어 길이 긴순 -> 내림차순 */
                return a.first < b.first;               /* 3번 정렬: 알파벳 순서 -> 오름차순 */
            }
            return a.first.length() > b.first.length();
        }
        return a.second > b.second;
    }); // sort 활용의 정점

    for (auto word : sorted_word) {
        cout << word.first << "\n";
    }

    return 0;
}
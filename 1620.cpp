#include <cstdlib>
#include <iostream>
#include <map>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    string numToPok[100'001];
    map<string, int> pokToNum;

    pair<string, int> pok;
    for (int i = 1; i <= N; ++i) {
        cin >> pok.first;
        pok.second = i;

        numToPok[i] = pok.first;
        pokToNum[pok.first] = pok.second;
    }

    string question;
    for (int i = 1; i <= M; ++i) {
        cin >> question;
        int isNum = atoi(question.c_str());
        if (isNum != 0) {
            cout << numToPok[isNum] << "\n";
        } else {
            cout << pokToNum[question] << "\n";
        }
    }

    return 0;
}
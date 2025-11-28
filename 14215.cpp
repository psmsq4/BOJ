#include <cmath>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(void) {
    vector<unsigned int> edges;

    unsigned int edge;
    for (int i = 0; i < 3; ++i) {
        cin >> edge;

        edges.push_back(edge);
    }

    unsigned int edge_max = edges.front();
    unsigned int nonmax_sum = edges.front();
    for (int i = 1; i < 3; ++i) {
        if (edge_max < edges[i])
            edge_max = edges[i];

        nonmax_sum += edges[i];
    }
    nonmax_sum -= edge_max;

    while (nonmax_sum <= edge_max) {
        edge_max--;
    }

    unsigned int perimeter = nonmax_sum + edge_max;

    cout << perimeter << "\n";

    return 0;
}
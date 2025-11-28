#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)  {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    string course;
    float course_weight;
    string score_tmp;

    float total_weight = 0;
    float total_score = 0;

    for (int i = 0; i < 20; ++i)    {
        cin >> course >> course_weight >> score_tmp;
        if (score_tmp == "A+")  {
            total_weight += course_weight;
            total_score += 4.5 * course_weight;
        } else if (score_tmp == "A0") {
            total_weight += course_weight;
            total_score += 4.0 * course_weight;
        } else if (score_tmp == "B+")   {
            total_weight += course_weight;
            total_score += 3.5 * course_weight;
        } else if (score_tmp == "B0")    {
            total_weight += course_weight;
            total_score += 3.0 * course_weight;
        } else if (score_tmp == "C+")   {
            total_weight += course_weight;
            total_score += 2.5 * course_weight;
        } else if (score_tmp == "C0")   {
            total_weight += course_weight;
            total_score += 2.0 * course_weight;
        } else if (score_tmp == "D+")   {
            total_weight += course_weight;
            total_score += 1.5 * course_weight;
        } else if (score_tmp == "D0")   {
            total_weight += course_weight;
            total_score += 1.0 * course_weight;
        } else if (score_tmp == "F")    {
            total_weight += course_weight;
            total_score += 0.0 * course_weight;
        }
    }

    if (total_weight == 0)  {
        cout << total_score;
    }
    else    {
        cout << total_score / total_weight;
    }

    return 0;
}
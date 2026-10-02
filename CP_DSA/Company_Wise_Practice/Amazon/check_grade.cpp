
#include <bits/stdc++.h>
using namespace std;


char checkGrade(int score)
{
    if (score <= 60)
        return 'D';
    else if ((61 <= score) && (score <= 75))
        return 'C';
    else if ((76 <= score) && (score <= 90))
        return 'B';
    else
        return 'A';
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int score;
    cin >> score;

    cout << checkGrade(score) << "\n";

    return 0;
}

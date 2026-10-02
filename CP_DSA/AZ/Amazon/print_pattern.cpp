
#include <bits/stdc++.h>
using namespace std;


void printPattern(int n)
{
    int cur = 2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < cur; j++)
        {
            cout << "1";
        }
        cout << "\n";
        cur += 2;
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    printPattern(n);
    
    return 0;
}

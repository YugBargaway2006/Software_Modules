
#include <bits/stdc++.h>
using namespace std;


int countOccurence(int *A, int len, int value)
{
    int i = 0, count = 0;
    while (i < len) {
        if (A[i] == value)
            count++;
        i++;
    }
    return count;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int len, value;
    cin >> len;

    int A[len];
    
    for (int i = 0; i < len; i++)
    {
        cin >> A[i];
    }

    cin >> value;
    
    cout << countOccurence(A, len, value) << "\n";
}

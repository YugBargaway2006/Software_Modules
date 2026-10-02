
#include <bits/stdc++.h>
using namespace std;

// #define ll long long

int* reverseArray(int* A, int n)
{
    for(int i = 0; i < n/2; i++) {
        swap(A[i], A[n-i-1]);
    }

    return A;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int A[n];

    for (int i = 0; i < n; i++)
        cin >> A[i];
    
    int* b = reverseArray(A, n);
    
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << "\n";
}
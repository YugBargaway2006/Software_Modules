
#include<bits/stdc++.h>
using namespace std;


int* sortArray(int *A,int len)
{
    int i, min, location, j, temp;
    for (i = 0; i < len; i++)
    {
        min = A[i];
        location = i;
        for (j = i; j < len; j++) 
        {
            if (min < A[j])
            {
                min = A[j];
                location = j;
            }
        }
        temp = A[i];
        A[i] = A[location];
        A[location] = temp;
    }
    return A;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int len;
    cin >> len;
    
    int A[len];
    for (int i = 0; i < len; i++)
        cin >> A[i];
    
    int* b = sortArray(A, len);

    for (int i = 0; i < len; i++)
        cout << b[i] << " ";
    cout << "\n";

    return 0;
}

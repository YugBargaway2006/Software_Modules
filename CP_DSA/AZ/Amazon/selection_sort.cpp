
#include<bits/stdc++.h>
using namespace std;


int* selectionSortArray(int* arr, int len)
{
    int x = 0, y = 0;
    for (x = 0; x < len; x++)
    {
        int index_of_min = x;
        for (y = x; y < len; y++)
        {
            if (arr[index_of_min] > arr[y])
            {
                index_of_min = y;
            }
        }
        int temp = arr[x];
        arr[x] = arr[index_of_min];
        arr[index_of_min] = temp;
    }
    return arr;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int len;
    cin >> len;

    int arr[len];
    for (int i = 0; i < len; i++)
        cin >> arr[i];
    
    int* b = selectionSortArray(arr, len);

    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}

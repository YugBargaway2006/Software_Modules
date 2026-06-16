class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n = arr.size();
        int c0 = 0;
        int c1 = 0;
        int c2 = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] == 0) c0++; 
            else if(arr[i] == 1) c1++; 
            else if(arr[i] == 2) c2++; 
        }

        int idx = 0;
        while(c0 != 0) {
            arr[idx] = 0;
            c0--;
            idx++;
        }
        while(c1 != 0) {
            arr[idx] = 1;
            c1--;
            idx++;
        }
        while(c2 != 0) {
            arr[idx] = 2;
            c2--;
            idx++;
        }
    }
};
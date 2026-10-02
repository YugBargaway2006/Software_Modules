class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int n = arr.size();
        int ele1 = -1, ele2 = -1, cnt1 = 0, cnt2 = 0;

        for (int ele : arr) {
            if (ele1 == ele) {
                cnt1++;
            }
            else if (ele2 == ele) {
                cnt2++;
            }
            else if (cnt1 == 0) {
                ele1 = ele;
                cnt1++;
            }
            else if (cnt2 == 0) {
                ele2 = ele;
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        vector<int> res;
        cnt1 = 0;
        cnt2 = 0;
        for (int ele : arr) {
            if (ele1 == ele) cnt1++;
            if (ele2 == ele) cnt2++;
        }

        if (cnt1 > n / 3) res.push_back(ele1);
        if (cnt2 > n / 3 && ele1 != ele2) res.push_back(ele2);
        
        if(res.size() == 2 && res[0] > res[1])
            swap(res[0], res[1]);
        return res;
    }
};
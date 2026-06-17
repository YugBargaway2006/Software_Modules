class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int ct = 0;
        int l = 0, r = n-1;
        while(l <= r) {
            int wt = people[l];
            if(l != r) wt += people[r];

            if(wt <= limit) {
                ct++; l++; r--;
            } else {
                ct++; r--;
            }
        }
        return ct;
    }
};
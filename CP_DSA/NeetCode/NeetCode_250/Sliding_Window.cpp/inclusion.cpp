class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26, 0);
        for(auto x : s1) {
            freq[x - 'a']++;
        }
        int k = s1.size();
        int n = s2.size();

        if(k > n) return false;
        vector<int> curr(26, 0);
        for(int i = 0; i < k; i++) {
            curr[s2[i]-'a']++;
        }

        for(int i = k; i < n; i++) {
            if(freq == curr) return true;
            curr[s2[i-k]-'a']--;
            curr[s2[i]-'a']++;
        }
        if(curr == freq) return true;
        return false;
    }
};

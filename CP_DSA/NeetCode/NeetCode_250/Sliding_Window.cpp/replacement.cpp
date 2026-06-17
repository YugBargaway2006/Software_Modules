class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26, 0);

        int l = 0;
        int maxFreq = 0;
        int ans = 0;

        for(int r = 0; r < s.size(); r++) {
            cnt[s[r] - 'A']++;

            maxFreq = max(maxFreq, cnt[s[r] - 'A']);

            while((r - l + 1) - maxFreq > k) {
                cnt[s[l] - 'A']--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
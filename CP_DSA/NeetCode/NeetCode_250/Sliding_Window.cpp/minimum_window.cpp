class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(128, 0);

        for(char c : t)
            need[c]++;

        int required = 0;
        for(int x : need)
            if(x > 0)
                required++;

        vector<int> have(128, 0);

        int formed = 0;
        int l = 0;

        int bestLen = INT_MAX;
        int bestStart = 0;

        for(int r = 0; r < s.size(); r++) {
            char c = s[r];

            have[c]++;

            if(need[c] > 0 && have[c] == need[c])
                formed++;

            while(formed == required) {
                if(r - l + 1 < bestLen) {
                    bestLen = r - l + 1;
                    bestStart = l;
                }

                char leftChar = s[l];

                have[leftChar]--;

                if(need[leftChar] > 0 &&
                   have[leftChar] < need[leftChar]) {
                    formed--;
                }

                l++;
            }
        }

        return bestLen == INT_MAX
                   ? ""
                   : s.substr(bestStart, bestLen);
    }
};
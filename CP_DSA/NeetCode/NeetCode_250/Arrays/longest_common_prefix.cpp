class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string prefix = "";
        int len = 1e9;
        for(int i = 0; i < n; i++) {
            len = min(len, static_cast<int>(strs[i].size()));
        }
        for(int i = 0; i < len; i++) {
            char match = strs[0][i];
            for(int j = 1; j < n; j++) {
                if(strs[j][i] != match) return prefix;
            }
            prefix.push_back(match);
        }
        return prefix;
    }
};
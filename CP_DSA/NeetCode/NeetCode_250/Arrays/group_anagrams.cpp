class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector<vector<int>> freq;
        for(int i = 0; i < strs.size(); i++) {
            vector<int> cur(26, 0);
            for(auto x : strs[i]) {
                cur[x-'a']++;
            }
            bool done = false;
            for(int j = 0; j < freq.size(); j++) {
                if(freq[j] == cur) {
                    res[j].push_back(strs[i]);
                    done = true;
                    break;
                }
            } 
            if(!done) {
                freq.push_back(cur);
                res.push_back({strs[i]});
            }
        }
        return res;
    }
};

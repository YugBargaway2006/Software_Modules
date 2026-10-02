class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(auto s : strs) {
            res.push_back(s.size());
            res += s;
        }
        cerr << res << endl;
        return res;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int n = s.size();
        int i = 0;
        while(i < n) {
            int len = static_cast<unsigned char>(s[i]);
            int j = 1;
            string cur = "";
            while(j <= len) {
                cur.push_back(s[i+j]);
                j++;
            }
            i += j;
            ans.push_back(cur);
        }
        return ans;
    }
};

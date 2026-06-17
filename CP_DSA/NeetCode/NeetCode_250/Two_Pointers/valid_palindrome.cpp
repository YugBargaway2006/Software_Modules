class Solution {
public:
    bool isPalindrome(string s) {
        string processed = "";
        for(auto c : s) {
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
                processed.push_back(tolower(c));
            }
        }
        // cerr << processed << endl;
        string rev = processed;
        reverse(rev.begin(), rev.end());
        return (processed == rev);
    }
};

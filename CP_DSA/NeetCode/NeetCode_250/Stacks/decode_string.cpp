class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> strs;

        string curr = "";
        int num = 0;

        for(char c : s) {
            if(isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if(c == '[') {
                nums.push(num);
                strs.push(curr);

                num = 0;
                curr = "";
            }
            else if(c == ']') {
                int k = nums.top(); nums.pop();

                string temp = strs.top(); strs.pop();

                while(k--) temp += curr;

                curr = temp;
            }
            else {
                curr += c;
            }
        }

        return curr;
    }
};
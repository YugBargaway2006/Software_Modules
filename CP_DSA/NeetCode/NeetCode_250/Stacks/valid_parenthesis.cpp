class Solution {
public:
    bool isValid(string st) {
        stack<char> s;
        for(auto c : st) {
            if(c == '(' || c == '{' || c == '[') {
                s.push(c);
            } else if(c == ')') {
                if(s.empty() || s.top() != '(') return false;
                else s.pop();
            } else if(c == '}') {
                if(s.empty() || s.top() != '{') return false;
                else s.pop();
            } else if(c == ']') {
                if(s.empty() || s.top() != '[') return false;
                else s.pop();
            }
        }
        if(s.empty()) return true;
        else return false;
    }
};

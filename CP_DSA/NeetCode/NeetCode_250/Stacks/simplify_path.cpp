class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int n = path.size();

        int i = 0;
        while(i < n) {
            while(path[i] == '/') {
                i++;
            }

            string cur = "";
            while(i < n && path[i] != '/') {
                cur.push_back(path[i]);
                i++;
            }

            if(cur == ".") continue;
            else if(cur == "..") {
                if(!st.empty()) st.pop();
            }
            else st.push(cur);
        }

        string ans = "";
        stack<string> nst;
        while(!st.empty()) {
            nst.push(st.top()); st.pop();
        }
        st = nst;
        while(!st.empty()) {
            if(st.top() == "") {
                st.pop();
                continue;
            }
            ans.push_back('/');
            ans += st.top(); st.pop();
        }

        if(ans == "") return "/";
        else return ans;
    }
};
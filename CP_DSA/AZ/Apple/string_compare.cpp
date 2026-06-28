
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

bool StringCompare(string s, string t) {
    stack<char> qs;
    for(auto c : s) {
        if(c == '#') {
            if(!qs.empty()) {
                qs.pop();
            }
        } else {
            qs.push(c);
        }
    }

    string rs = "";
    while(!qs.empty()) {
        rs.push_back(qs.top()); qs.pop();
    }

    stack<char> qt;
    for(auto c : t) {
        if(c == '#') {
            if(!qt.empty()) {
                qt.pop();
            }
        } else {
            qt.push(c);
        }
    }

    string rt = "";
    while(!qt.empty()) {
        rt.push_back(qt.top()); qt.pop();
    }

    return rs == rt;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s, t;
	cin >> s >> t;
	if (StringCompare(s, t))
		cout << "Yes";
	else
		cout << "No";
}

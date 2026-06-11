#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
#define int long long
 
const int mod = 1e9 + 7;
vector<int> dp(5005);
vector<vector<int>> trie(1e6 + 5, vector<int>(26));
vector<bool> endW(1e6+5);
int node = 0;
 
 
void insert(string& word) {
    int cn = 0;
    for(char& ch : word) {
        if(!trie[cn][ch - 'a']) {
            trie[cn][ch - 'a'] = ++node;
        }
        cn = trie[cn][ch - 'a'];
    }
    endW[cn] = true;
}
 
int count(int start, string& s) {
    int cn = 0, ways = 0;
    for(int i = start; i < s.size(); i++) {
        if(!trie[cn][s[i] - 'a']) {
            return ways;
        }
        cn = trie[cn][s[i] - 'a'];
        if(endW[cn]) {
            ways = (ways + dp[i+1]) % mod;
        }
    }
    return ways;
}
 
void solve(string& s, int k, vector<string> word) {
    for(int i = 0; i < k; i++) {
        insert(word[i]);
    }
    dp[s.size()] = 1;
    for(int i = s.size()-1; i >= 0; i--) {
        dp[i] = count(i, s);
    }
    cout << dp[0];
}
 
 
signed main(void) {
    string s; cin >> s;
    int k; cin >> k;
    vector<string> words(k);
    for(int i = 0; i < k; i++) {
        cin >> words[i];
    }
 
    solve(s, k, words);
}

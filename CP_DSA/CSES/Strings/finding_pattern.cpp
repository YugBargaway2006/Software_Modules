// 14 : 50   ::::::: Just copy pasted
#include <bits/stdc++.h>
using namespace std;

struct State {
    int len;
    int link;
    int next[26];

    State() {
        len = 0;
        link = -1;
        memset(next, -1, sizeof(next));
    }
};

vector<State> st;
int sz = 1;
int last = 0;

void extend(char ch) {
    int c = ch - 'a';

    int cur = sz++;
    st[cur].len = st[last].len + 1;

    int p = last;

    while (p != -1 && st[p].next[c] == -1) {
        st[p].next[c] = cur;
        p = st[p].link;
    }

    if (p == -1) {
        st[cur].link = 0;
    } 
    else {
        int q = st[p].next[c];

        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } 
        else {
            int clone = sz++;
            st[clone] = st[q];
            st[clone].len = st[p].len + 1;

            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }

            st[q].link = clone;
            st[cur].link = clone;
        }
    }

    last = cur;
}

bool exists(const string &pat) {
    int v = 0;

    for (char ch : pat) {
        int c = ch - 'a';

        if (st[v].next[c] == -1)
            return false;

        v = st[v].next[c];
    }

    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text;
    cin >> text;

    st.resize(2 * text.size() + 5);

    for (char c : text)
        extend(c);

    int q;
    cin >> q;

    while (q--) {
        string pat;
        cin >> pat;

        cout << (exists(pat) ? "YES\n" : "NO\n");
    }

    return 0;
}
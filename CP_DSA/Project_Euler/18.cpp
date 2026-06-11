#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

#define int long long

signed main(void) {
    vector<vector<int>> triangle;
    string line;

    ifstream file("input.txt");
    while(getline(file, line)) {
        if(line.empty()) continue;

        stringstream ss(line);
        vector<int> row;
        int x;

        while(ss >> x) {
            row.push_back(x);
        }
        triangle.push_back(row);
    }
    
    vector<vector<int>> dp = triangle;
    for(int i = 1; i < triangle.size(); i++) {
        for(int j = 0; j < triangle[i].size(); j++) {
            // cout << "done" << endl;
            if(j == 0) dp[i][j] += dp[i-1][j];
            else if(j == triangle[i].size()-1) dp[i][j] += dp[i-1][j-1];
            else {
                dp[i][j] += max(dp[i-1][j-1], dp[i-1][j]);
            }
        }
    }
    
    int ans = 0;
    for(auto i : dp[dp.size()-1]) {
        ans = max(ans, i);
    }

    cout << ans << endl;
}
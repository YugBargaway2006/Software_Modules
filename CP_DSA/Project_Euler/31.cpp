#include <iostream>
#include <vector>
using namespace std;

#define int long long



signed main(void) {
    vector<int> ways(201, 0);
    vector<int> coins = {1,2,5,10,20,50,100, 200};
    ways[0] = 1;
    for(auto c : coins) {
        for(int i = 1; i <= 200; i++) {
            if(i-c >= 0) ways[i] += ways[i-c];
        }
    }
    cout << ways[200] << endl;
}
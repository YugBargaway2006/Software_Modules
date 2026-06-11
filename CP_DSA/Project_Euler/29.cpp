#include <iostream>
#include <set>
#include <map>
using namespace std;


#define int long long

map<int, int> prime(int a, int b) {
    map<int, int> factors;
    for(int i = 2; i*i <= a; i++) {
        while(a%i == 0) {
            factors[i] += b;
            a /= i;
        }
    }

    if(a > 1) {
        factors[a] += b;
    }
    return factors;
}

signed main(void) {
    set<map<int, int>> distinct;

    for(int a = 2; a  <= 100; a++) {
        for(int b = 2; b <= 100; b++) {
            distinct.insert(prime(a, b));
        }
    } 

    cout << distinct.size() << endl;
}
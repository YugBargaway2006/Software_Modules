#include <iostream>
using namespace std;

#define int long long

signed main(void) {
    int max_p = 0;
    int max_solutions = 0;
    for(int p = 1; p <= 1000; p++) {
        int count = 0;
        for(int a = 1; a <= p / 3; a++) {
            for(int b = a; b <= (p - a) / 2; b++) {
                int c = p - a - b;
                if(a * a + b * b == c * c) {
                    count++;
                }
            }    
        }
        if(count > max_solutions) {
            max_solutions = count;
            max_p = p;
        }
    }
    cout << max_p << endl;
}
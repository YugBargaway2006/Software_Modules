#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int count(int n) {
    if(__gcd(n, 10) != 1) return 0;

    int rem = 2, len = 0;
    do {
        rem = (rem * 10) % n;
        len++;
    } while(rem != 2);

    return len;
}

int main(void) {
    int bd = 0;
    int ml = 0;

    for(int i = 2; i < 1000; i++) {
        int l = count(i);
        if(ml < l) {
            ml = l;
            bd = i;
        }
    }
    cout << bd << endl;
}
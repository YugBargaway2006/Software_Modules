#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "";
    int i = 1;
    while (s.length() < 1000000) {
        s += to_string(i);
        i++;
    }
    
    int result = (s[0] - '0') * (s[9] - '0') * (s[99] - '0') * (s[999] - '0') * (s[9999] - '0') * (s[99999] - '0') * (s[999999] - '0');
    cout << result << endl;
    return 0;
}

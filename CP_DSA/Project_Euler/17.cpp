#include <iostream>
#include <vector>
using namespace std;

#define int long long

vector<int> ones = {
    0, // 0 (unused)
    3, // one
    3, // two
    5, // three
    4, // four
    4, // five
    3, // six
    5, // seven
    5, // eight
    4, // nine
    3, // ten
    6, // eleven
    6, // twelve
    8, // thirteen
    8, // fourteen
    7, // fifteen
    7, // sixteen
    9, // seventeen
    8, // eighteen
    8  // nineteen
};

vector<int> tens = {
    0, 0,
    6, // twenty
    6, // thirty
    5, // forty
    5, // fifty
    5, // sixty
    7, // seventy
    6, // eighty
    6  // ninety
};

int countLetters(int n) {
    int count = 0;

    if (n == 1000) {
        return 11; // "one thousand"
    }

    if (n >= 100) {
        count += ones[n / 100]; // "one", "two", ...
        count += 7;             // "hundred"

        if (n % 100 != 0) {
            count += 3;         // "and"
        }

        n %= 100;
    }

    if (n >= 20) {
        count += tens[n / 10];
        n %= 10;
    }

    if (n > 0) {
        count += ones[n];
    }

    return count;
}

signed main(void) {
    int total = 0;

    for (int i = 1; i <= 1000; i++) {
        total += countLetters(i);
    }

    cout << total << endl; 
}
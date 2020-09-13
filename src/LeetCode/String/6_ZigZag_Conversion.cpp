
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// https://leetcode.com/problems/zigzag-conversion/

// Problem:
/* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to
display this pattern in a fixed font for better legibility) */

// Level: Medium

// Results:
/* First try: Time limit exceeded but custom test cases all passed */
/* Second try: Runtime: 20 ms, faster than 91.80% of C++ online submissions for ZigZag Conversion.
Memory Usage: 10.4 MB, less than 47.13% of C++ online submissions for ZigZag Conversion. */

// solution
string convert(string s, int numRows) {
    // edge case
    if(s.empty()) { return ""; }
    if(s.size() <= numRows) { return s; }

    string zigzag = "";
    vector<string> rows(numRows);
    int index = 0;
    while(index < s.size()) {
        // Filling rows vector with chars downward
        for(int r = 0; r < numRows && index < s.size(); r++) {
            rows[r] += s[index];
            ++index;
        }

        // Filling rows vector with chars upward
        for(int r = numRows - 2; r > 0 && index < s.size(); r--) {
            rows[r] += s[index];
            ++index;
        }

    }

    for_each(rows.cbegin(), rows.cend(), [&zigzag](const string &s) { zigzag += s; });
    return zigzag;
}

int main() {
    string test = "PAYPALISHIRING";
    string output = convert(test, 3);
    cout << test << endl;
    cout << output << endl;
    return 0;
}

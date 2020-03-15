
#include <algorithm>
#include <iostream>
using namespace std;

/* https://leetcode.com/problems/add-strings/ */
//Problem:
/*
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
 */

//Level: Easy

//Result:
//program stopped for very large numbers but works fine for most unsigned int values as string inputs

string addStrings(string num1, string num2) {
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    //making both strings the same length by padding zeros
    if(num1.size() > num2.size()) {
        for(int i = 0; i < num1.size() - num2.size(); i++) {
            num2 += "0";
        }
    } else if(num2.size() > num1.size()) {
        for(int i = 0; i < num2.size() - num1.size(); i++) {
            num1 += "0";
        }
    }

    cout << "num1: " << num1 << ",\tnum2: " << num2 << endl;

    unsigned long sum = 0;
    unsigned long multiplier = 1;
    for(int i = 0; i < num1.size(); i++) {
        sum += ((unsigned long)num1[i] + (unsigned long)num2[i] - 96) * multiplier;
        cout << sum << "\t";
        multiplier *= 10;
    }

    return to_string(sum);
}

int main() {
    string ans = addStrings("9133", "12");
    cout << ans << endl;
}








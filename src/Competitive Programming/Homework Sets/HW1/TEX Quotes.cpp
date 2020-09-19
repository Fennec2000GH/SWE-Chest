
// 9/10/2020
// https://vjudge.net/contest/391584#problem/D

// Trial 1
#include <iostream>
#include <string>
using namespace std;

int main() {
    bool slanted = true;  // true if first of each pair of quotes
    string s = "";
    while(getline(cin, s)) {
        for(const char &c : s) {
            if (c == '\"') {
                cout << (slanted ? "``" : "''");
                slanted = !slanted;
            } else { cout << c; }
        }
        cout << endl;
    }

    return 0;
}
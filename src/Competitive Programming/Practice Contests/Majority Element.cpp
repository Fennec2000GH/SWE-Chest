
// https://vjudge.net/contest/394521#problem/B
// 09/21/2020.
// Trial 1

#include <iostream>
#include <unordered_map>
#include <iterator>
#include <cmath>
using namespace std;

int main() {
    unordered_map<unsigned, unsigned> m;

    unsigned n;
    cin >> n;

    unsigned temp;
    for(unsigned i = 0; i < n; i++) {
        cin >> temp;
        m[temp]++;
    }

    unsigned pass_bar = floor(n / 2.0);
//    cout << "pass_bar: " << pass_bar << endl;

    for(auto it = m.cbegin(); it != m.cend(); it++) {
        if(it -> second > pass_bar) { cout << it -> first; return 0; }
    }

    cout << -1;
    return 0;
}
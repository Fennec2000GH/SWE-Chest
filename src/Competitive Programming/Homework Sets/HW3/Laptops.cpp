
// https://vjudge.net/contest/394524#problem/B
// Created by qcaij on 9/22/2020.
// Trial 1

#include <iostream>
#include <map>
#include <iterator>
using namespace std;

int main() {
    map<unsigned, unsigned> m;  // maps price as key, and lowest quality for each price, if multiple laptops have equal prices

    unsigned n, a, b;
    cin >> n;

    // filling the map
    for(unsigned i = 0; i < n; i++) {
        cin >> a >> b;
        if(m.count(a) == 0) {
//            cout << "new element: {" << a << ", " << b << "}" << endl;
            m.insert_or_assign(a, b);
        } else {
            m[a] = min(m[a], b);
//            cout << "updated element: {" << a << ", " << m[a] << "}" << endl;
        }
    }

    // edge case
    if(n == 1) { cout << "Poor Alex"; return 0; }

    unsigned prevQuality = m.cbegin() -> second;  // quality for cheapest laptop

    // delete
//    cout << "initial prevQuality: " << prevQuality << endl;

    for(auto it = next(m.cbegin()); it != m.cend(); it++) {
//        cout << "quality: " << it -> second << endl;
        if(it -> second < prevQuality) { cout << "Happy Alex"; return 0; }
        prevQuality = it -> second;
    }

    cout << "Poor Alex";
    return 0;
}

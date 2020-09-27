
// https://vjudge.net/contest/394521#problem/A
// 09/21/2020.
// Trial #1

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    map<unsigned, unsigned> m;

    unsigned n, a, b;
    cin >> n >> a >> b;

    unsigned temp;
    for(unsigned i = 0; i < n; i++) {
        cin >> temp;
        m[temp]++;
    }

    unsigned a_chore_count = 0; // Number of chores done by Petrya
    unsigned a_lower_bound = -1;  // Smallest complexity of any chore done by Petrya (smallest of top a chores)
    auto outside_it = m.crbegin();
    for(auto it = m.crbegin(); it != m.crend(); it++) {
        a_chore_count += it -> second;

//        cout << "key: " << it -> first << ", ";
//        cout << "a_chore_count: " << a_chore_count << "\t";
        if(a_chore_count > a) { cout << 0; return 0; }
        else if(a_chore_count == a) {
            a_lower_bound = it -> first;
            outside_it = it;
            break;
        }
    }
//    cout << endl;
    advance(outside_it, 1);
    unsigned b_upper_bound = outside_it -> first; // Largest complexity for the smallest b complex chores
//    cout << "b_upper_bound: " << b_upper_bound << endl;

    cout << a_lower_bound - b_upper_bound;

    return 0;
}


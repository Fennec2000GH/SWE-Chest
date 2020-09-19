
// https://vjudge.net/contest/391624#problem/B
// Created by qcaij on 9/18/2020.
// Trial 1: Runtime Error
//
//#include <iostream>
//#include <list>
//#include <iterator>
//#include <algorithm>
//#include <string>
//#include <vector>
//using namespace std;
//
//int main() {
//    unsigned numPlays = 0;  // number of plays or letter cancellations made
//    list<char> li;
//    string s;
//    getline(cin, s);
//
//    // edge cases
//    if (s.size() <= 1) { cout << "No"; return 0; }
//    if (s.substr(2, 4) == "bbbb" && s[1] == 'a') { cout << "No"; return 0; }
//
//    for(char c : s) { li.push_back(c); }
//
//    s.clear();
//
//    // delete
////    cout << "max_size: " << li.max_size() << endl;
//
//    auto it = li.begin();
//
//    while (next(it) != li.end()) {
//        // delete
////        cout << "li during game: ";
////        copy(li.cbegin(), li.cend(), ostream_iterator<char>(cout, ", "));
////        cout << endl;
////        cout << "c: " << *it << endl;
//
//        if (*it == *next(it)) {
//            advance(it, -1);
//            li.erase(next(it));
//            li.erase(next(it));
//            numPlays++;
//        } else { advance(it, 1); }
////        cout << "numPlays: " << numPlays << endl;
//    }
//
//    // delete
////    cout << "li after game: ";
////    copy(li.cbegin(), li.cend(), ostream_iterator<char>(cout, ", "));
////    cout << endl;
//
//    if (numPlays % 2 == 1) { cout << "Yes"; }
//    else { cout << "No"; }
//
//    return 0;
//}
//

// Trial 2: Use vector rather than list with an iterator to dlete matching letters
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    unsigned numPlays = 0;  // number of plays or letter cancellations made
    vector<char> v;
    string s;
    getline(cin, s);

    // edge cases
    if (s.size() <= 1) { cout << "No"; return 0; }

    char c;
    istringstream iss(s);
    while (iss >> c) {
        // delete
//        cout << "v during game: ";
//        copy(v.cbegin(), v.cend(), ostream_iterator<char>(cout, ", "));
//        cout << endl;
//        cout << "c: " << c << endl;

        if (v.empty() || c != v.back()) { v.push_back(c); }
        else { // new char matches back char of vector
            v.pop_back();
            numPlays++;
        }
//        cout << "numPlays: " << numPlays << endl;
    }

    // delete
//    cout << "v after game: ";
//    copy(v.cbegin(), v.cend(), ostream_iterator<char>(cout, ", "));
//    cout << endl;

    if (numPlays % 2 == 1) { cout << "Yes"; }
    else { cout << "No"; }

    return 0;
}



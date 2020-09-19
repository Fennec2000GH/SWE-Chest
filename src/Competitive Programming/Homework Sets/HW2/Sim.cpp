
// https://vjudge.net/contest/391624#problem
// 09/16/2020.
// Trial 1: Failed
// Trial 2: Passed (#1 failed because forgot for loop for T test cases)

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

int main() {

    string s, part = "";  // s holds input string, part is part of string between brackets
    vector<string> endKey;  // vector holds all substrings inserted by home key ']' in insertion order (read forwards)
    vector <string> homeKey;  // vector holds all substrings inserted by home key '[' in insertion order (read backwards)
    bool home = false;  // true if current substring belongs to the left end of string (home key), otherwise substring belongs to the end (endKey)
    unsigned homeKeyStartIndex = 0;  // the first non-blank string element in homeKey, in case endKey is empty and '<' snips off homeKey

    unsigned short T;
    cin >> T;
    cin.ignore();
   for(unsigned short test_case = 0; test_case < T; test_case++) {
       getline(cin, s);
       for (const char &c : s) {
           //delete
//           cout << "c: " << c << endl;

           switch (c) {
               // Move to home (front)
               case '[': {
                   if (!part.empty()) {
                       if (home) { homeKey.push_back(part); }
                       else { endKey.push_back(part); }
                       part.clear();
                   }
                   home = true;
                   break;
               }
                   // Move to end
               case ']': {
                   if (!part.empty()) {
                       if (home) { homeKey.push_back(part); }
                       else { endKey.push_back(part); }
                       part.clear();
                   }
                   home = false;
                   break;
               }
               case '<': {
                   if (part.empty() && !home) {
                       // pop off chars from homeKey '[' strings in case endKey ']' strings already got depleted
                       if (endKey.empty()) {
                           if (homeKey.empty()) { continue; }
                           if (homeKey[homeKeyStartIndex].empty()) { homeKeyStartIndex++; }
                           if (homeKeyStartIndex == homeKey.size() - 1) { continue; }

                           // delete
//                           cout << "delete from homeKey..." << endl;
//                           cout << "delete c: " << homeKey[homeKeyStartIndex].back() << endl;

                           homeKey[homeKeyStartIndex].pop_back();
                       } else {
                           // delete
//                           cout << "delete from endKey..." << endl;
//                           cout << "delete c: " << endKey.back().back() << endl;

                           endKey.back().pop_back();
                           if (endKey.back().empty()) { endKey.pop_back(); }
                       }
                   } else if (!part.empty()) {
                       // delete
//                       cout << "deleting c from part..." << endl;
//                       cout << part.back() << endl;

                       part.pop_back();
                   }
                   break;
               }
               default:
                   part.push_back(c);
           }
       }
       if (home) { homeKey.push_back(part); }
       else { endKey.push_back(part); }

       copy(homeKey.crbegin(), homeKey.crend(), ostream_iterator<string>(cout, ""));
       copy(endKey.cbegin(), endKey.cend(), ostream_iterator<string>(cout, ""));
       cout << endl;

       // clearing for next test case
       s.clear();
       part.clear();
       endKey.clear();
       homeKey.clear();
       homeKeyStartIndex = 0;
       home = false;
   }

    return 0;
}



// https://vjudge.net/contest/391584#problem/A
// 09/09/2020

// Trial 1: TIME LIMIT EXCEEDED

//#include <algorithm>
//#include <iostream>
//#include <iterator>
//#include <regex>
//#include <string>
//using namespace std;
//
//int main() {
//    string original;
//    string fixed = "";
//    const regex re("<+");
//
//    getline(cin, original);
//
//    auto it =  sregex_iterator(original.cbegin(), original.cend(), re);
//    int index = 0;
//    for_each(it, sregex_iterator(), [&](const smatch &sm){
//        // add substring from index to next pattern match
//        fixed += original.substr(index, sm.position() - sm.length() - index);
//        index = sm.position() + sm.length();
//    });
//
//    if (index < original.size()) { fixed += original.substr(index, original.size() - index); }
//    cout << fixed << endl;
//
//    return 0;
//}

// Trial 2: TIME LIMIT EXCEEDED

//#include <algorithm>
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//    string original;
//    string fixed = "";
//    vector<unsigned> v = {0};  // Indexes of substrings in original to keep
//
//    getline(cin, original);
//
//    unsigned index = 1;  // index of original string
//    unsigned start, counter = 0;  // start index of contiguous sequence of '<', counter for length of '<' sequence
//    while(index < original.size()) {
//        if(original[index] == '<') {
//            start = index;
//            while(original[index] == '<') { counter++; index++; }
//            v.push_back(start - counter);
//            v.push_back(index);
//            counter = 0;
//        } else { index++; }
//    }
//    v.push_back(original.size());  // last index of last kept substring
//
//    for(index = 0; index <= v.size() - 2; index += 2) { fixed += original.substr(v[index], v[index + 1] - v[index]); }
//    cout << fixed;
//    return 0;
//}

// Trial 3: Timeout Error
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() {
//    string original;
//    getline(cin, original);
//
//    unsigned index = 1;  // index of original string
//    unsigned counter = 0;  // counts number of '<' in contiguous sequence
//    while(index < original.size()) {
//        if(original[index] == '<') {
//            counter++;
//            original.erase(index, 1);
//        } else if(counter > 0) {
//            index -= counter;
//            for(; counter > 0; counter--) { original.erase(index, 1); }
//        } else { index++; }
//    }
//    original.erase(original.size() - counter, counter);  // erasing tail sequence of '<'
//    cout << original;
//    return 0;
//}

// Trial 3
#include <iostream>
#include <string>
using namespace std;

int main() {
    string original, fixed = "";
    getline(cin, original);
    for(char &c : original) {
        if (c == '<') { fixed.pop_back(); }
        else { fixed.push_back(c); }
    }
    cout << fixed;
    return 0;
}

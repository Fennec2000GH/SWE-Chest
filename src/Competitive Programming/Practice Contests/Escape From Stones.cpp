
// https://vjudge.net/contest/391623#problem/B
//  9/14/2020
// Trial 1: TIMEOUT ERROR
//
//#include <iostream>
//#include <stack>
//#include <queue>
//using namespace std;
//
//int main() {
//    stack<unsigned> st;
//    queue<unsigned> queue;
//    string s;
//    getline(cin, s);
//
//    unsigned stone_number = 1;
//    for(const char &c : s) {
//        if (c == 'l') { st.push(stone_number++); }
//        else { queue.push(stone_number++); }
//    }
//
//    unsigned next;  // next number in either queue or stack to get off
//    while (!queue.empty()) { next = queue.front(); queue.pop(); cout << next << endl; }
//    while (!st.empty()) { next = st.top(); st.pop(); cout << next << endl; }
//    return 0;
//}

// Trial 2
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main() {
    vector<unsigned> st;
    vector<unsigned> queue;
    string s;
    getline(cin, s);

    unsigned stone_number = 1;
    for(const char &c : s) {
        if (c == 'l') { st.push_back(stone_number++); }
        else { queue.push_back(stone_number++); }
    }

    copy(queue.cbegin(), queue.cend(), ostream_iterator<unsigned>(cout, "\n"));
    copy(st.crbegin(), st.crend(), ostream_iterator<unsigned>(cout, "\n"));
    return 0;
}


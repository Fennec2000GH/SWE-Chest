
// https://vjudge.net/contest/391623#problem/A
// 09/14/2020
// Trial 1
#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s;
    char top;  // top of char stack
    unsigned long long n;
    cin >> n;
    cin.ignore();

    for(unsigned long long trial = 0; trial < n; trial++) {
        stack<char> st;
        s.clear();
        getline(cin, s);

        //edge cases
        if (s.empty()) { cout << "Yes" << endl; continue; }
        if (s.size() % 2 == 1) { cout << "No" << endl; continue; }

        for (unsigned short i = 0; i < s.size(); i++) {
            if (st.empty()) {
                if (s[i] == ')' || s[i] == ']') {
                    st.push('#');  // filler value
                    break;
                } else {
                    st.push(s[i]);
                    continue;
                }
            }
            top = st.top();
            if (top == '(') {
                if (s[i] == ')') { st.pop(); }
                else if (s[i] == ']') { break; }
                else { st.push(s[i]); }
            } else if (top == '[') {
                if (s[i] == ']') { st.pop(); }
                else if (s[i] == ')') { break; }
                else { st.push(s[i]); }
            }
        }

        if (st.empty()) { cout << "Yes" << endl; }
        else { cout << "No" << endl; }
    }

    return 0;
}

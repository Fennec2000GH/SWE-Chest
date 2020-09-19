
// https://vjudge.net/contest/391624#problem/C
// 09/17/2020.
// Trial 1: Fail due to lack of loop for multiple test cases
// Trial 2: Fail
// Trial 3: Cleared out innerSum (set to 0) of each element after removal from stack

#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    unordered_map<unsigned, unsigned long long> innerSum;  // holds accumulated values of all inner toys for a given toy abs(key)
    vector<int> st;  // stack linearly follows inputted integers left to right, cancelling top element when abs values match with new input

    string line;
    int n, oldTop;  // n holds currently read integer, prevTop holds top of stack for current iteration
    while(getline(cin, line)) {
        // edge cases
        if (line.empty()) {
            cout << ":-) Matrioshka!" << endl;
            continue;
        }

        istringstream iss(line);

        // Initially filling stack with first integer for top
        iss >> n;
        st.push_back(n);
//        cout << "Initial top: " << n << endl;

        while (iss.peek() != '\n' && iss >> n) {
            // debugging
//            cout << "n: " << n << endl;

            oldTop = st.back();
            if (n < 0) {  // next parsed integer is negative
                // debugging
//                cout << "negative" << endl;

                if (n > oldTop) { st.push_back(n); }
                else {
                    cout << ":-( Try again." << endl;
                    break;
                }
            } else if (n == abs(oldTop)) { // next parsed integer is positive and matches top of stack by abs value (no zero (0) inputs)
                // debugging
//            cout << "positive" << endl;

                st.pop_back();
                if (st.empty()) {
                    if (iss.tellg() != -1) { cout << ":-( Try again." << endl; }
                    break;
                }

                // clearing out inner sum value for number just popped off stack
                if(innerSum.find(abs(oldTop)) != innerSum.end()) { innerSum.erase(abs(oldTop)); }

                if (innerSum.find(abs(st.back())) != innerSum.end()) { innerSum[abs(st.back())] += n; }
                else { innerSum.insert({abs(st.back()), n}); }

                // debugging
//                cout << "Inner sum for " << abs(st.back()) << ": " << innerSum[abs(st.back())] << endl;

                // check if sum of inner toys is at or greater than current toy (top of stack)
                if (innerSum[abs(st.back())] >= abs(st.back())) {
                    cout << ":-( Try again." << endl;
                    break;
                }
            } else {  // positive but not matching negative top of stack
                cout << ":-( Try again." << endl;
                break;
            }
        }

        if (st.empty() && iss.tellg() == -1) { cout << ":-) Matrioshka!" << endl; }

        // clean up after test case
        innerSum.clear();
        st.clear();
        line.clear();
        iss.clear();
    }

    return 0;
}


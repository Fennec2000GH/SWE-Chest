
// https://vjudge.net/contest/396471#problem/B
// 09/29/2020

// Trial 1
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// pair represents contiguous segment of 1's or 0's
// first - true is 1, false is 0
// second - count of number of 1's (or 0's) for that specific contiguous segment
typedef pair<bool, unsigned> p;

int main() {
    unsigned t, n, digit;
    cin >> t;

    // delete
//    cout << "t: " << t << endl;

    string s;  // Bit string in string type
    vector<p> bitString;
    for(unsigned trial = 1; trial <= t; trial++) {
        // delete
//        cout << "---------------------------------------------------------------------------------------------" << endl;

        cin >> n;
        cin.ignore();

        getline(cin, s);
        istringstream iss(s);

        // delete
//        cout << "---------------------------------------------------------------------------------------------" << endl;
//        cout << "trial number: " << trial << endl;
//        cout << "length of bit string: " << n << endl;
//        cout << "bit string: " << s << endl;

        // First pair in bit string
        digit = iss.get() - 48;
        p element(digit == 1, 1);

        // delete
//        cout << "First inputted digit: " << digit << endl;
//        cout << boolalpha << "First element initially: (" << element.first << ", " << element.second << ")" << endl;

        // edge case - single digit
        if(n == 1) {
            // delete
//            cout << "Bit string is 1 digit long only" << endl;

            cout << digit << endl;
            bitString.clear();
            continue;
        }

        for(unsigned index = 1; index < n; index++) {
            digit = iss.get() - 48;  // Next digit in line
            if(element.first == (digit == 1)) {
                element.second++;

                // delete
//                cout << "Count incremented..." << endl;
//                cout << boolalpha << "Element: (" << element.first << ", " << element.second << ")" << endl;
            } else {
                // delete
//                cout << "Element is added to vector..." << endl;
//                cout << boolalpha << "Element: (" << element.first << ", " << element.second << ")" << endl;

                bitString.push_back(element);
                element.first = (digit == 1);
                element.second = 1;

                // delete
//                cout << "Starting new element..." << endl;
//                cout << boolalpha << "Element: (" << element.first << ", " << element.second << ")" << endl;
            }
        }

        bitString.push_back(element);

        // delete
//        cout << "Last element to add to vector..." << endl;
//        cout << boolalpha << "Element: (" << element.first << ", " << element.second << ")" << endl;
//        cout << endl << "Vector: " << endl;
//        for(auto& el : bitString) { cout << boolalpha << "\t(" << el.first << ", " << el.second << "),"; }
//        cout << endl;

        // Same repeating digit
        if(bitString.size() == 1) {
            // delete
//            cout << "Bit string is a single contiguous stream of repeating digits..." << endl;

            digit = bitString.front().first ? 1 : 0;
            for(unsigned count = 1; count <= bitString.front().second; count++)
                cout << digit;
            cout << endl;
        } else {
            // delete
//            cout << "Bit string has both 0's and 1's..." << endl;

            // Any prefix of contiguous zeros cannot be erased no matter what
            if(!bitString.front().first) {
                // delete
//                cout << "Prefix of 0's..." << endl;

                for(unsigned count = 1; count <= bitString.front().second; count++)
                    cout << 0;
            }

            // Last digit being zero would erase all 1's and 0's in front when erasing optimally
            if(!bitString.back().first) {
                cout << 0 << endl;
                bitString.clear();
                continue;
            }

            // Lossy-compressed final bit string is 01
            if(bitString.size() == 2) {
                for(unsigned count = 1; count <= bitString.back().second; count++)
                    cout << 1;
                cout << endl;
                bitString.clear();
                continue;
            }

            // Lossy-compressed final bit string is 001
            cout  << 0;
            for(unsigned count = 1; count <= bitString.back().second; count++)
                cout << 1;
            cout << endl;
        }

        // Cleanup for the trial
        bitString.clear();
    }

    return 0;
}


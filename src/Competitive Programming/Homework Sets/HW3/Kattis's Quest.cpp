
// https://vjudge.net/contest/394524#problem/C
// Created by qcaij on 9/25/2020.

/*
// Trial 1: TIME LIMIT
// Time Complexity: O( (log N) ^ 2)
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    map<unsigned, multiset<unsigned>> EG;  // holds the weight and all gold values for each added quest
    unsigned long long sumGold = 0;

    unsigned N;
    cin >> N;
    cin.ignore();

    // delete
//    cout << "N: " << N << endl;


    string command;
    string operation;
    unsigned arg1, arg2;  // arguments after operation
    auto weight_iterator = EG.begin();  // iterator over weight keys in EG

    for(unsigned cmd = 1; cmd <= N; cmd++) {
        // delete
//        cout << "cmd: " << cmd << endl;
        cin >> operation;

        // delete
//        cout << "operation: " << operation << endl;

        if (operation == "add") {
            cin >> arg1 >> arg2;

            // delete
//            cout << "arg1: " << arg1 << ", arg2: " << arg2 << endl;

            weight_iterator = EG.find(arg1);
            if(weight_iterator == EG.end()) {
                EG.insert({arg1, multiset<unsigned>({arg2})});
            } else {
                (weight_iterator -> second).insert(arg2);
            }

        } else {
            cin >> arg1;

            // delete
//            cout << "arg1: " << arg1 << endl;
//            cout << "EG before query " << arg1 << ", cmd " << cmd << ":" << endl;
//            for(auto it = EG.cbegin(); it != EG.cend(); it++) {
//                cout << "Weight: " << it -> first << endl;
//                cout << "\t";
//                for(const unsigned &gold : it -> second) {
//                    cout << gold << ", ";
//                }
//                cout << endl;
//            }

            while(arg1 >= 1) {
                if (EG.empty()) {
//                    cout << "EG is empty" << endl;
                    break;
                }
                weight_iterator = EG.lower_bound(arg1);
                if (weight_iterator -> first > arg1 || weight_iterator == EG.end()) {
                    // query weight is lesser than smallest existing weight in map
                    if (weight_iterator == EG.begin()) {
//                        cout << "query weight is lesser than smallest existing weight in map" << endl;
                        break;
                    }
                    // delete
//                    if(weight_iterator == EG.end()) { cout << "query weight is greater than largest existing weight in map" << endl; }

                    advance(weight_iterator, -1);
                }

                // delete
//                cout << "Checkpoint 1" << endl;

                multiset<unsigned>& tempGold = weight_iterator -> second;  // References multiset of gold values for highest weight <= arg1
                auto goldAmount = max_element(tempGold.cbegin(), tempGold.cend());

                // delete
//                cout << "Weight marginally consumed: " << weight_iterator -> first << endl;
//                cout << "Gold marginally consumed: " << *goldAmount << endl;

                sumGold += *goldAmount;
                arg1 -= weight_iterator -> first;
                tempGold.erase(goldAmount);
                if (tempGold.empty()) { EG.erase(weight_iterator); }
            }
//            cout << "sumGold: " << sumGold << endl << "-----------------------------------------------------__" << endl;
            cout << sumGold << endl;
            sumGold = 0;
        }
    }

    return 0;
}
*/

/*
// Trial 2: Used multimap instead of map of multiset, TIMEOUT ERROR
// Time Complexity
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    multimap<unsigned, unsigned> EG;  // holds the weight and all gold values for each added quest
    unsigned long long sumGold = 0;

    unsigned N;
    cin >> N;
    cin.ignore();

    // delete
//    cout << "N: " << N << endl;


    string command;
    string operation;
    unsigned arg1, arg2;  // arguments after operation
    auto weight_iterator = EG.begin();  // iterator over weight keys in EG

    for(unsigned cmd = 1; cmd <= N; cmd++) {
        // delete
//        cout << "cmd: " << cmd << endl;
        cin >> operation;

        // delete
//        cout << "operation: " << operation << endl;

        if (operation == "add") {
            cin >> arg1 >> arg2;

            // delete
//            cout << "arg1: " << arg1 << ", arg2: " << arg2 << endl;

            EG.insert({arg1, arg2});
        } else {
            cin >> arg1;

            // delete
//            cout << "arg1: " << arg1 << endl;
//            cout << "EG before query " << arg1 << ", cmd " << cmd << ":" << endl;
//            for(auto it = EG.cbegin(); it != EG.cend(); it++) {
//                cout << "Weight: " << it -> first << endl;
//                cout << "\t";
//                for(const unsigned &gold : it -> second) {
//                    cout << gold << ", ";
//                }
//                cout << endl;
//            }

            while(arg1 >= 1) {
                if (EG.empty()) {
//                    cout << "EG is empty" << endl;
                    break;
                }
                weight_iterator = EG.lower_bound(arg1);
                if (weight_iterator -> first > arg1 || weight_iterator == EG.end()) {
                    // query weight is lesser than smallest existing weight in map
                    if (weight_iterator == EG.begin()) {
//                        cout << "query weight is lesser than smallest existing weight in map" << endl;
                        break;
                    }
                    // delete
//                    if(weight_iterator == EG.end()) { cout << "query weight is greater than largest existing weight in map" << endl; }

                    advance(weight_iterator, -1);
                }

                // delete
//                cout << "Checkpoint 1" << endl;

                // Retrieves all map elements with maximum weight <= arg1
                auto sameWeight = EG.equal_range(weight_iterator -> first);

                // Points to map elemnt with highest gold for maximum possible weight
                auto goldAmount = max_element(sameWeight.first, sameWeight.second, [](const pair<unsigned, unsigned>& p1, const pair<unsigned, unsigned>& p2) {
                    return p1.second < p2.second;
                });

                // delete
//                cout << "Weight marginally consumed: " << weight_iterator -> first << endl;
//                cout << "Gold marginally consumed: " << *goldAmount << endl;

                sumGold += goldAmount -> second;
                arg1 -= weight_iterator -> first;
                EG.erase(goldAmount);
            }
//            cout << "sumGold: " << sumGold << endl << "-----------------------------------------------------__" << endl;
            cout << sumGold << endl;
            sumGold = 0;
        }
    }

    return 0;
}
*/

/*
// Trial 3: Map of counter map; TIMEOUT ERROR
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    // outer map (EG) uses unique weight as key
    // for each existing weight, inner map keeps track of unique gold values as key and count of repeated gold values
    // for the same weight as inner map values
    map<unsigned, map<unsigned, unsigned>> EG;
    unsigned long long sumGold = 0;

    unsigned N;
    cin >> N;
    cin.ignore();

    // delete
//    cout << "N: " << N << endl;

    string command;
    string operation;
    unsigned arg1, arg2;  // arguments after operation
    auto weight_iterator = EG.begin();  // iterator over weight keys in EG

    for(unsigned cmd = 1; cmd <= N; cmd++) {
        // delete
//        cout << "cmd: " << cmd << endl;
        cin >> operation;

        // delete
//        cout << "operation: " << operation << endl;

        if (operation == "add") {
            cin >> arg1 >> arg2;

            // delete
//            cout << "arg1: " << arg1 << ", arg2: " << arg2 << endl;

            weight_iterator = EG.find(arg1);
            if(weight_iterator == EG.end()) {
                EG.insert_or_assign(arg1, map<unsigned, unsigned>({{arg2, 1}}));
            } else {
                (weight_iterator -> second)[arg2]++;
            }

        } else {
            cin >> arg1;

            // delete
//            cout << "arg1: " << arg1 << endl;
//            cout << "EG before query " << arg1 << ", cmd " << cmd << ":" << endl;
//            for(auto it = EG.cbegin(); it != EG.cend(); it++) {
//                cout << "Weight: " << it -> first << endl;
//                cout << "\t";
//                for(const unsigned &gold : it -> second) {
//                    cout << gold << ", ";
//                }
//                cout << endl;
//            }

            while(arg1 >= 1) {
                if (EG.empty()) {
//                    cout << "EG is empty" << endl;
                    break;
                }
                weight_iterator = EG.lower_bound(arg1);
                if (weight_iterator -> first > arg1 || weight_iterator == EG.end()) {
                    // query weight is lesser than smallest existing weight in map
                    if (weight_iterator == EG.begin()) {
//                        cout << "query weight is lesser than smallest existing weight in map" << endl;
                        break;
                    }
                    // delete
//                    if(weight_iterator == EG.end()) { cout << "query weight is greater than largest existing weight in map" << endl; }

                    advance(weight_iterator, -1);
                }

                // delete
//                cout << "Checkpoint 1" << endl;

                map<unsigned, unsigned>& goldCounter = weight_iterator -> second;  // References counting map of gold values for highest weight <= arg1
                auto goldAmount = max_element(goldCounter.begin(), goldCounter.end());

                // delete
//                cout << "Weight marginally consumed: " << weight_iterator -> first << endl;
//                cout << "Gold marginally consumed: " << *goldAmount << endl;

                sumGold += goldAmount -> first;
                (goldAmount -> second)--;
                arg1 -= weight_iterator -> first;

                // Erasing any depleted resources
                if (goldAmount -> second == 0) { goldCounter.erase(goldAmount); }
                if (goldCounter.empty()) { EG.erase(weight_iterator); }
            }
//            cout << "sumGold: " << sumGold << endl << "-----------------------------------------------------__" << endl;
            cout << sumGold << endl;
            sumGold = 0;
        }
    }

    return 0;
}
*/


// Trial 4: Same data structure as Trial 3, but with minor adjustments; maximum key in inner map is accessed directly
//by rbegin iterator for constant time access
// Time Complexity: O(log N)
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    // outer map (EG) uses unique weight as key
    // for each existing weight, inner map keeps track of unique gold values as key and count of repeated gold values
    // for the same weight as inner map values
    map<unsigned, map<unsigned, unsigned>> EG;
    unsigned long long sumGold = 0;

    unsigned N;
    cin >> N;
    cin.ignore();

    // delete
//    cout << "N: " << N << endl;

    string command;
    string operation;
    unsigned arg1, arg2;  // arguments after operation
    auto weight_iterator = EG.begin();  // iterator over weight keys in EG

    for(unsigned cmd = 1; cmd <= N; cmd++) {
        // delete
//        cout << "cmd: " << cmd << endl;
        cin >> operation;

        // delete
//        cout << "operation: " << operation << endl;

        if (operation == "add") {
            cin >> arg1 >> arg2;

            // delete
//            cout << "arg1: " << arg1 << ", arg2: " << arg2 << endl;

            weight_iterator = EG.find(arg1);
            if(weight_iterator == EG.end()) {
                EG.insert_or_assign(arg1, map<unsigned, unsigned>({{arg2, 1}}));
            } else {
                (weight_iterator -> second)[arg2]++;
            }

        } else {
            cin >> arg1;

            // delete
//            cout << "arg1: " << arg1 << endl;
//            cout << "EG before query " << arg1 << ", cmd " << cmd << ":" << endl;
//            for(auto it = EG.cbegin(); it != EG.cend(); it++) {
//                cout << "Weight: " << it -> first << endl;
//                cout << "\t";
//                for(const unsigned &gold : it -> second) {
//                    cout << gold << ", ";
//                }
//                cout << endl;
//            }

            while(arg1 >= 1) {
                if (EG.empty()) {
//                    cout << "EG is empty" << endl;
                    break;
                }
                weight_iterator = EG.lower_bound(arg1);
                if (weight_iterator -> first > arg1 || weight_iterator == EG.end()) {
                    // query weight is lesser than smallest existing weight in map
                    if (weight_iterator == EG.begin()) {
//                        cout << "query weight is lesser than smallest existing weight in map" << endl;
                        break;
                    }
                    // delete
//                    if(weight_iterator == EG.end()) { cout << "query weight is greater than largest existing weight in map" << endl; }

                    advance(weight_iterator, -1);
                }

                // delete
//                cout << "Checkpoint 1" << endl;

                map<unsigned, unsigned>& goldCounter = weight_iterator -> second;  // References counting map of gold values for highest weight <= arg1
                auto goldAmount = goldCounter.rbegin();

                // delete
//                cout << "Weight marginally consumed: " << weight_iterator -> first << endl;
//                cout << "Gold marginally consumed: " << *goldAmount << endl;

                sumGold += goldAmount -> first;
                (goldAmount -> second)--;
                arg1 -= weight_iterator -> first;

                // Erasing any depleted resources
                if (goldAmount -> second == 0) { goldCounter.erase(--goldAmount.base()); }
                if (goldCounter.empty()) { EG.erase(weight_iterator); }
            }
//            cout << "sumGold: " << sumGold << endl << "-----------------------------------------------------__" << endl;
            cout << sumGold << endl;
            sumGold = 0;
        }
    }

    return 0;
}


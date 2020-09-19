
// https://vjudge.net/contest/391624#problem/E
// 09/17/2020.
// Trial 1: TIMOUT ERRORR
//
//#include <iostream>
//#include <list>
//#include <iterator>
//#include <algorithm>
//#include <deque>
//#include <iterator>
//using namespace std;
//
//
//int main() {
//    list<long long> li;  // consecutive ADD builds sorted list
//    list<long long>::iterator getter = li.end(); // points to number when GET is called
//    list<long long>::iterator inserter;  // inserts new element in sorted order when ADD is called
//    deque<long long> deck;  // holds initially inputted elements before adding to database (li)
//
//    unsigned long long M, N; // number of ADD and GET operations, respectively
//    long long temp;  // temporary element holder
//    unsigned liSize;  // holds current size of li
//
//    unsigned K;  // number of test cases
//    cin >> K;
//    cin.ignore();
//
//    for(unsigned long long test_case = 0; test_case < K; test_case++) {
//        cin >> M >> N;
//        for (unsigned long long add_index = 0; add_index < M; add_index++) {
//            cin >> temp;
//            deck.push_back(temp);
//        }
//
//        for (unsigned long long get_index = 1; get_index <= N; get_index++) {
//            cin >> temp;  // holds number of elements needed before next GET call
//
//            // delete
////            cout << endl << "get index: " << get_index << endl;
////            cout << "number of elements needed: " << temp << endl;
//
//            liSize = li.size();
//            for (unsigned add_counter = 0; add_counter < temp - liSize; add_counter++) {
//                inserter = lower_bound(li.begin(), li.end(), deck.front());
//                if (inserter == li.end()) { li.push_back(deck.front()); }
//                else { li.insert(inserter, deck.front()); }
//
//                // delete
////                cout << "li: ";
////                copy(li.cbegin(), li.cend(), ostream_iterator<long long>(cout, ", "));
////                cout << endl;
//
//                if (getter != li.end() && deck.front() <= *getter) { getter = prev(getter); }
//                deck.pop_front();
//            }
//            if (getter != li.end()) { getter = next(getter); }
//            else {
//                getter = li.begin();
//                cout << endl;
//            }
//            cout << *getter << endl;
//
//        }
//
//        // clean up for next test case
//        cout << endl;
//        li.clear();
//        getter = li.end();
//        deck.clear();
//    }
//
//    return 0;
//}
//

// Trial 2: Manually (linear time) find lower bound for each insertion, and deque is replaced with vector
// Total time complexity: O(n^2)

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

int main() {
    list<long long> li;  // consecutive ADD builds sorted list
    list<long long>::iterator getter = li.end(); // points to number when GET is called
    list<long long>::iterator inserter;  // inserts new element in sorted order when ADD is called
    vector<long long> elements;  // holds initially inputted elements before adding to database (li)
    long long toAdd;  // next eleemnt to be added to list (li)

    unsigned long long M, N; // number of ADD and GET operations, respectively
    long long temp;  // temporary element holder
    unsigned liSize;  // holds current size of li

    unsigned K;  // number of test cases
    cin >> K;
    cin.ignore();

    for(unsigned long long test_case = 0; test_case < K; test_case++) {
        cin >> M >> N;
        for (unsigned long long add_index = 0; add_index < M; add_index++) {
            cin >> temp;
            elements.push_back(temp);
        }

        // delete
//        cout << "elements: ";
//        copy(elements.cbegin(), elements.cend(), ostream_iterator<long long>(cout, ", "));
//        cout << endl;

        reverse(elements.begin(), elements.end());
        for (unsigned long long get_index = 1; get_index <= N; get_index++) {
            cin >> temp;  // holds number of elements needed before next GET call
            // delete
//            cout << endl << "get index: " << get_index << endl;
//            cout << "number of elements needed: " << temp << endl;

            liSize = li.size();  // list size before adding new elements
            for (unsigned add_counter = 0; add_counter < temp - liSize; add_counter++) {
                toAdd = elements.back();
                elements.pop_back();

                // delete
                cout << "toAdd: " << toAdd << endl;

                if (li.empty()) { li.push_back(toAdd); }
                else {
                    inserter = li.begin();
                    while(toAdd > *inserter && next(inserter) != li.end()) { advance(inserter, 1); }
                    if (toAdd > *inserter) { li.push_back(toAdd); }
                    else { li.insert(inserter, toAdd); }
                }

                // delete
//                cout << "li: ";
//                copy(li.cbegin(), li.cend(), ostream_iterator<long long>(cout, ", "));
//                cout << endl;

                if (getter != li.end() && toAdd <= *getter) { getter = prev(getter); }
            }

//            cout << "checkpoint A" << endl;
            if (getter != li.end()) { getter = next(getter); }
            else {
//                cout << "first solution" << endl;
                getter = li.begin();
                cout << endl;
            }
            cout << *getter << endl;

        }

        // clean up for next test case
        cout << endl;
        li.clear();
        getter = li.end();
        elements.clear();
    }

    return 0;
}

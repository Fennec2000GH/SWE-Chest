#include <algorithm>
#include <bitset>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

//std::lower_bound
/* default (1)
 * template <class ForwardIterator, class T>
 * ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val);
 *
 */
/* custom (2)
 * template <class ForwardIterator, class T, class Compare>
 * ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val, Compare comp);
 */

//std::upper_bound
/*
 *
 */
/*
 *
 */

//predicate function returns true only if first parameter is a factor of second parameter
bool factor(int a, int b) { return b % a == 0; }

int main() {
    //main vector
    vector<bool> v(10);
    bitset<10> b(60);

    string s = b.to_string();
    transform(s.cbegin(), s.cend(), v.begin(), [](char c){ return c == '1'; });
    cout << "v: { ";
    copy(v.cbegin(), v.cend(), ostream_iterator<bool>(cout << boolalpha, ", "));
    cout << "} " << endl;

    //find lower and upper bounds of true (expected: 4, 10)
    //note that nothing is higher than true for booleans
    vector<bool>::const_iterator lb = lower_bound(v.cbegin(), v.cend(), true);
    vector<bool>::const_iterator ub = upper_bound(v.cbegin(), v.cend(), true);
    cout << "CHECK: the index of the lower bound for true is " << lb - v.cbegin() << endl;
    cout << "CHECK: the index of the upper bound for true is " << ub - v.cbegin() << endl;

    //testing with integer vector (expected: 3, 7}
    vector<int> w = {12, 14, 0, 16, 16, 16, 20, 22, 16, 36};
    sort(w.begin(), w.end()); // {0, 12, 14, 16, 16, 16, 16, 20, 22, 36}
    cout << "w: { ";
    copy(w.cbegin(), w.cend(), ostream_iterator<int>(cout, ", "));
    cout << "} " << endl;
    vector<int>::const_iterator lb_int = lower_bound(w.cbegin(), w.cend(), 16);
    vector<int>::const_iterator ub_int = upper_bound(w.cbegin(), w.cend(), 16);
    cout << "CHECK: the index of the lower bound for 16 is " << lb_int - w.cbegin() << endl;
    cout << "CHECK: the index of the upper bound for 16 is " << ub_int - w.cbegin() << endl;

    //testing with integer vector using predicate function (expected: 0, 2} //error
    vector<int>::const_iterator lb_int_pred = lower_bound(w.cbegin(), w.cend(), 3, factor);
    vector<int>::const_iterator ub_int_pred = upper_bound(w.cbegin(), w.cend(), 3, factor);
    cout << "CHECK: the index of the lower bound using predicate function is " << lb_int_pred - w.cbegin() << endl;
    cout << "CHECK: the index of the upper bound using predicate function is " << ub_int_pred - w.cbegin() << endl;

    return 0;
}
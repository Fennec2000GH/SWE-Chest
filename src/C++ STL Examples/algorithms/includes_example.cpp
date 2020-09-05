#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

//std::includes
/* (1) default
 * template <class InputIterator1, class InputIterator2>
 * bool includes ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2 );
 */
/* (2) pred
 * template <class InputIterator1, class InputIterator2, class Compare>
 * bool includes ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp );
 */

//predicate function always returns true
bool pred(double a, double b) { return true; }

int main(){
    //main vector
    vector<double> v = {-2.22, -1.34, -0.42, 0.65, 7.82, 12.12};
    cout << "v: { ";
    copy(v.cbegin(), v.cend(), ostream_iterator<double>(cout, ", "));
    cout << "} " << endl;

    //tests for inclusion of sub-vector without changing ordering (expected: true)
    vector<double> test1(v.cbegin(), v.cbegin() + 4); // {-2.22, -1.34, -0.42, 0.65}
    cout << "test1: { ";
    copy(test1.cbegin(), test1.cend(), ostream_iterator<double>(cout, ", "));
    cout << "} " << endl;
    cout << boolalpha << "CHECK: v includes test1 ? " << includes(v.cbegin(), v.cend(), test1.cbegin(), test1.cend()) << endl;

    //tests for inclusion of sub-vector in scrambled ordering  (expected: false)
    vector<double> test2(test1);
    random_shuffle(test2.begin(), test2.end());
    cout << "test2: { ";
    copy(test2.cbegin(), test2.cend(), ostream_iterator<double>(cout, ", "));
    cout << "} " << endl;
    cout << boolalpha << "CHECK: v includes test2 ? " << includes(v.cbegin(), v.cend(), test2.cbegin(), test2.cend()) << endl;

    //tests for inclusion of single element (expected: true)
    vector<double> test3(v.begin(), v.begin() + 1); // {-2.22}
    cout << "test3: { ";
    copy(test3.cbegin(), test3.cend(), ostream_iterator<double>(cout, ", "));
    cout << "} " << endl;
    cout << boolalpha << "CHECK: v includes test3 ? " << includes(v.cbegin(), v.cend(), test3.cbegin(), test3.cend()) << endl;

    //tests for inclusion based on predicate function (expected: true)
    vector<double> test4(v);
    random_shuffle(test4.begin(), test4.end());
    cout << "test4: { ";
    copy(test4.cbegin(), test4.cend(), ostream_iterator<double>(cout, ", "));
    cout << "} " << endl;
    cout << boolalpha << "CHECK: v includes test4 ? " << includes(v.cbegin(), v.cend(), test4.cbegin(), test4.cend(), pred) << endl;

    //tests for inclusion of empty vector (expected: true)
    vector<double> test5;
    cout << "test5: { ";
    copy(test5.cbegin(), test5.cend(), ostream_iterator<double>(cout, ", "));
    cout << "} " << endl;
    cout << boolalpha << "CHECK: v includes test5 (empty) ? " << includes(v.cbegin(), v.cend(), test5.cbegin(), test5.cend(), pred) << endl;

    return 0;
}
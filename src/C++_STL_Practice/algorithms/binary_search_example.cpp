#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

//std::binary_search
/* default (1)
 * template <class ForwardIterator, class T>
 * bool binary_search (ForwardIterator first, ForwardIterator last, const T& val);
 */
/* custom (2)
 * template <class ForwardIterator, class T, class Compare>
 * bool binary_search (ForwardIterator first, ForwardIterator last, const T& val, Compare comp);
 */

int main() {
    //main vector
    vector<short> v = { 4, 6, 1, 3, 18, 13};
    cout << "v: { ";
    copy(v.cbegin(), v.cend(), ostream_iterator<short>(cout, ", "));
    cout << "} " << endl;

    //search for 6 in sorted vector (expected: true)
    sort(v.begin(), v.end());
    cout << "v: { ";
    copy(v.cbegin(), v.cend(), ostream_iterator<short>(cout, ", "));
    cout << "} " << endl;
    cout << boolalpha << "CHECK: 6 exists in v (sorted) ? " << binary_search(v.cbegin(), v.cend(), 6) << endl;

    //search for 6 in unsorted vector (expected: true)
    random_shuffle(v.begin(), v.end());
    cout << "v: { ";
    copy(v.cbegin(), v.cend(), ostream_iterator<short>(cout, ", "));
    cout << "} " << endl;
    cout << boolalpha << "CHECK: 6 exists in v (unsorted) ? " << binary_search(v.cbegin(), v.cend(), 6) << endl;

    //search in vextor for any element that is a multiple of 4 using predicate (expected: true)
    sort(v.begin(), v.end());
    cout << "v: { ";
    copy(v.cbegin(), v.cend(), ostream_iterator<short>(cout, ", "));
    cout << "} " << endl;
    cout << "CHECK: multiple of 4 exists in v ? ";
    cout << boolalpha << binary_search(v.cbegin(), v.cend(), 4, [](short a, short b) { return a % b == 0;}) << endl;

}



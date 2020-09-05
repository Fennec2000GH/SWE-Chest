#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
using namespace std;

//std::adjacent_find
/* equality (1)
 * template <class ForwardIterator>
 * ForwardIterator adjacent_find (ForwardIterator first, ForwardIterator last);
*/
/* predicate (2)
 * template <class ForwardIterator, class BinaryPredicate>
 * ForwardIterator adjacent_find (ForwardIterator first, ForwardIterator last, BinaryPredicate pred);
*/

//predicate function tests for first number less than second number
bool pred(unsigned long a, unsigned long b) { return a < b; }

int main() {
    //main vector
    vector<unsigned long> v(10);
    iota(v.begin(), v.end(), 0);
    random_shuffle(v.begin(), v.end());
    v[5] = v[4]; // elements at indices 4 and 5 are adjacent and equivalent
    cout << "v: { ";
    copy(v.cbegin(), v.cend(), ostream_iterator<unsigned long>(cout, ", "));
    cout << "} " << endl;

    //confirm that chosen elements are selected by std::adjacent_find
    vector<unsigned long>::const_iterator it1 = adjacent_find(v.cbegin(), v.cend());
    cout << "CHECK: the first element appearing twice adjacently in v is " << *it1 << endl;

    //test vector with std::adjacent_find using a binary predicate
    vector<unsigned long>::const_iterator it2 = adjacent_find(v.cbegin(), v.cend(), pred);
    cout << "CHECK: the first element appearing twice adjacently based on binary predicate in v is " << *it2 << endl;

    return 0;
}

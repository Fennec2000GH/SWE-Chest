
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

//std::find_end
/* equality (1)
 * template <class ForwardIterator1, class ForwardIterator2>
 * ForwardIterator1 find_end (ForwardIterator1 first1, ForwardIterator1 last1,ForwardIterator2 first2, ForwardIterator2 last2);
*/
 /* predicate (2)
  * template <class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
  * ForwardIterator1 find_end (ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2, BinaryPredicate pred);
 */

 //predicate function confirms equality if second integer is a multiple of first integer
 bool multiple(int a, int b) { return b % a == 0; }

 int main() {
    //main vector
    vector<int> v = {-2, 1, 4, 2, 4, 0, -3, -4, 4, 2};
    cout << "v: { ";
    copy(v.cbegin(), v.cend(), ostream_iterator<int>(cout, ", "));
    cout << "} " << endl;

    //finding first occurrence of {4, 2}
    vector<int> test = {4, 2};
    cout << "test: { ";
    copy(test.cbegin(), test.cend(), ostream_iterator<int>(cout, ", "));
    cout << "} " << endl;
    vector<int>::const_iterator it1 = search(v.cbegin(), v.cend(), test.cbegin(), test.cend());
    cout << "first occurrence index: " << it1 - v.cbegin() << endl;

    //finding last occurrence of {4, 2}
    vector<int>::const_iterator it2 = find_end(v.cbegin(), v.cend(), test.cbegin(), test.cend());
    cout << "last occurrence index: " << it2 - v.cbegin() << endl;

    //finding first occurrence of {4, 2} with predicate function
    vector<int>::const_iterator it3 = search(v.cbegin(), v.cend(), test.cbegin(), test.cend(), multiple);
    cout << "first occurrence pred index: " << it3 - v.cbegin() << endl;

    //finding last occurrence of {4, 2} with predicate function
    vector<int>::const_iterator it4 = find_end(v.cbegin(), v.cend(), test.cbegin(), test.cend(), multiple);
    cout << "last occurrence pred index: " << it4 - v.cbegin() << endl;


    return 0;
}
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

//std::mismatch
/* (1) default
 * template <class InputIterator1, class InputIterator2>
 * pair<InputIterator1, InputIterator2> mismatch (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2);
*/
/* predicate (2)
 * template <class InputIterator1, class InputIterator2, class BinaryPredicate>
 * pair<InputIterator1, InputIterator2> mismatch (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred);
 */

//predicate function evalutates to true if and only if same-index integers from both vectors are both even or both odd
bool pred(unsigned a, unsigned b) { return a % 2 == b % 2; }

int main() {
    //main vector
    vector<unsigned> v = {1, 3, 5, 8, 10, 12};
    cout << "v: { ";
    copy(v.cbegin(), v.cend(), ostream_iterator<unsigned>(cout, ", "));
    cout << "} " << endl;

    //finding mismatch based on equality
    vector<unsigned> test1(v.cbegin(), v.cbegin() + 2); // {1, 3}
    test1.push_back(4);
    cout << "test1: { ";
    copy(test1.cbegin(), test1.cend(), ostream_iterator<unsigned>(cout, ", "));
    cout << "} " << endl;
    pair<vector<unsigned>::const_iterator, vector<unsigned>::const_iterator> p1 = mismatch(v.cbegin(), v.cend(), test1.cbegin());
    cout << "CHECK: first mismatch in v and test1 are the elements " << *p1.first << ", " << *p1.second << endl;

    //finding mismatch based on predicate function
    vector<unsigned> test2(v);
    replace_if(test2.begin(), test2.end(), [](unsigned a){ return a % 2 == 0; }, 1); // {1, 3, 5, 1, 1, 1}
    cout << "test2: { ";
    copy(test2.cbegin(), test2.cend(), ostream_iterator<unsigned>(cout, ", "));
    cout << "} " << endl;
    pair<vector<unsigned>::const_iterator, vector<unsigned>::const_iterator> p2 = mismatch(v.cbegin(), v.cend(), test2.cbegin(), pred);
    cout << "CHECK: first mismatch in v and test2 (pred) are the elements " << *p2.first << ", " << *p2.second << endl;

    return 0;
}
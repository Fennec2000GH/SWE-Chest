
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

//std::move
/* template <class InputIterator, class OutputIterator>
 * OutputIterator move (InputIterator first, InputIterator last, OutputIterator result);
 */

//move::move_backwords
/* template <class BidirectionalIterator1, class BidirectionalIterator2>
 * BidirectionalIterator2 move_backward (BidirectionalIterator1 first BidirectionalIterator1 last,BidirectionalIterator2 result);
 *
 */

int main() {
    //main vector
    vector<unsigned long long> v = {2345234509, 42583730458, 2534253245, 89023457230, 4987432509878, 4598434330};
    cout << "v: { ";
    copy(v.cbegin(), v.cend(), ostream_iterator<unsigned long long>(cout, ", "));
    cout << "} " << endl;

    //moving all elements from v to empty vector w
    vector<unsigned long long> w(v.size());
    vector<unsigned long long>::iterator it1 = move(v.cbegin(), v.cend(), w.begin());
    cout << "after std::move was called..." << endl;
    cout << "v: { ";
    copy(v.cbegin(), v.cend(), ostream_iterator<unsigned long long>(cout, ", "));
    cout << "} " << endl;
    cout << "w: { ";
    copy(w.cbegin(), w.cend(), ostream_iterator<unsigned long long>(cout, ", "));
    cout << "} " << endl;
    cout << "v.size(): " << v.size() << endl;
    cout << "w.size(): " << w.size() << endl;
    cout << "index of iterator in w: " << it1 - w.cbegin() << endl;

    //moving (backwards) all elements from v to empty vector z
    vector<unsigned long long> z(v.size() + 4);
    vector<unsigned long long>::iterator it2 = move_backward(v.cbegin(), v.cend(), z.end());
    //w: {0, 0, 0, 0, ... elements of v ...}
    cout << "after std::move_backward was called..." << endl;
    cout << "v: { ";
    copy(v.cbegin(), v.cend(), ostream_iterator<unsigned long long>(cout, ", "));
    cout << "} " << endl;
    cout << "z: { ";
    copy(w.cbegin(), w.cend(), ostream_iterator<unsigned long long>(cout, ", "));
    cout << "} " << endl;
    cout << "v.size(): " << v.size() << endl;
    cout << "w.size(): " << w.size() << endl;
    cout << "index of iterator in z: " << it2 - z.cbegin() << endl;

    return 0;
}
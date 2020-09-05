#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

//std::fill
/* template <class ForwardIterator, class T>
 * void fill (ForwardIterator first, ForwardIterator last, const T& val);
 */

//std::fill_n
/* template <class OutputIterator, class Size, class T>
 * void fill_n (OutputIterator first, Size n, const T& val);
 */

int main(){
    //main vector
    vector<unsigned long> v(10, 2); //{2, 2, 2, 2, 2, 2, 2, 2, 2, 2}
    cout << "v: { ";
    copy(v.cbegin(), v.cend(), ostream_iterator<unsigned long>(cout, ", "));
    cout << "} " << endl;

    //changing each element in the last half of v to 4
    fill(v.begin() + v.size() / 2, v.end(), 4);
    cout << "v: { ";
    copy(v.cbegin(), v.cend(), ostream_iterator<unsigned long>(cout, ", "));
    cout << "} " << endl;

    //changing first two (2) elements of v each to 12
    fill_n(v.begin(), 2, 12);
    cout << "v: { ";
    copy(v.cbegin(), v.cend(), ostream_iterator<unsigned long>(cout, ", "));
    cout << "} " << endl;

    return 0;
}


















#define _USE_MATH_DEFINES

#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
using namespace std;

//std::replace
/* template <class ForwardIterator, class T>
 * void replace (ForwardIterator first, ForwardIterator last, const T& old_value, const T& new_value);
 */
//std::replace_if
/* template <class ForwardIterator, class UnaryPredicate, class T>
 * void replace_if (ForwardIterator first, ForwardIterator last, UnaryPredicate pred, const T& new_value );
 */
//std::replace_copy
/* template <class InputIterator, class OutputIterator, class T>
 * OutputIterator replace_copy (InputIterator first, InputIterator last, OutputIterator result, const T& old_value, const T& new_value);
 */
//std::replace_copy_if
/* template <class InputIterator, class OutputIterator, class UnaryPredicate, class T>
 * OutputIterator replace_copy_if (InputIterator first, InputIterator last, OutputIterator result, UnaryPredicate pred,const T& new_value);
 */

int main() {
    //main vector
    //replace all values >= 104 and < 108 with 0
    vector<float> v(10);
    iota(v.begin(), v.end(), 100.25); // {100.24, 101.24, 102.24, 103.24, 104.24, 105.24, 106.24, 107.24, 108.24, 109.24}
    replace_if(v.begin(), v.end(), [](float f){ return (f >= 104 && f < 108); }, 0);
    //{100.24, 101.24, 102.24, 103.24, 0, 0, 0, 0, 108.24, 109.24}

    cout << "v: { ";
    copy(v.cbegin(), v.cend(), ostream_iterator<float>(cout, ", "));
    cout << "} " << endl;

    //replace 100.24 with -1.23456789
    //this test failed previously before 100.24 was changed to 100.25, as 100.25 can be exactly represented in binary form
    //while 100.24 is 1100100.001111.... with erroneous precision
    replace(v.begin(), v.end(), 100.25, -1.23456789); //{-1.23456789, 101.24, 102.24, 103.24, 0, 0, 0, 0, 108.24, 109.24}
    cout << "v: { ";
    copy(v.cbegin(), v.cend(), ostream_iterator<float>(cout, ", "));
    cout << "} " << endl;

    //copy all elements from v into new vector but replace 0 with -1.1111
    vector<float> w(v.size());
    replace_copy(v.cbegin(), v.cend(), w.begin(), float(0), float(-1.1111));
    //{-1.23456789, 101.24, 102.24, 103.24, -1.1111, -1.1111, -1.1111, -1.1111, 108.24, 109.24}
    cout << "v (unchanged): { ";
    copy(v.cbegin(), v.cend(), ostream_iterator<float>(cout, ", "));
    cout << "} " << endl;
    cout << "w: { ";
    copy(w.cbegin(), w.cend(), ostream_iterator<float>(cout, ", "));
    cout << "} " << endl;


    //copy all elements from w but replace all negative elements with pi
    vector<float> z(w.size());
    replace_copy_if(w.cbegin(), w.cend(), z.begin(), [z](float f){ return f < float(0);  }, M_PI);
    //{M_PI, 101.24, 102.24, 103.24, M_PI, M_PI, M_PI, M_PI, 108.24, 109.24}
    cout << "z: { ";
    copy(z.cbegin(), z.cend(), ostream_iterator<float>(cout, ", "));
    cout << "} " << endl;
    return 0;
}

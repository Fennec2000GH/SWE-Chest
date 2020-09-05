
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

//std::count
/* template <class InputIterator, class T>
 * typename iterator_traits<InputIterator>::difference_type
 * count (InputIterator first, InputIterator last, const T& val);
 */

//std::count_if
/* template <class InputIterator, class UnaryPredicate>
 * typename iterator_traits<InputIterator>::difference_type
 * count_if (InputIterator first, InputIterator last, UnaryPredicate pred);
 */

//predicate function determines whether an integer is even or not
bool isEven(int a) { return a % 2 == 0; }

int main() {
    //main vector
    vector<int> v = {-1, 0, 6, 4, 1, -1, 9, -1, 3, 4};
    cout << "v: { ";
    copy(v.cbegin(), v.cend(), ostream_iterator<int>(cout, ", "));
    cout << "} " << endl;

    //count number of occurrences of -1 in v
    cout << "-1 frequency: " << count(v.cbegin(), v.cend(), -1) << endl;

    //count number of even integers in v
    cout << "even integer frequency: " << count_if(v.cbegin(), v.cend(), isEven) << endl;

    return 0;
}









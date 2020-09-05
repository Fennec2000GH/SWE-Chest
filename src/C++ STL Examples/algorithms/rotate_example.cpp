#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
using namespace std;

//std::rotate
/* template <class ForwardIterator>
 * ForwardIterator rotate (ForwardIterator first, ForwardIterator middle, ForwardIterator last);
 */

int main(){
    //main vector
    vector<char> v(26);
    {
        int intAlphabet[26]; // ASCII values of lowercase alphabet a-z
        iota(intAlphabet, intAlphabet + 26, 97);
        transform(intAlphabet, intAlphabet + 26, v.begin(), [](int a){ return (char)a; });
    }

    cout << "v: { ";
    copy(v.cbegin(), v.cend(), ostream_iterator<char>(cout, ", "));
    cout << "} " << endl;

    //rotate such that 'q' is front
    rotate(v.begin(), find(v.begin(), v.end(), 'q'), v.end());
    cout << "v: { ";
    copy(v.cbegin(), v.cend(), ostream_iterator<char>(cout, ", "));
    cout << "} " << endl;
    cout << boolalpha << "CHECK: 'q' is front ? " << (v.front() == 'q') << endl;

    //rotate such that 'q' is last
    rotate(v.begin(), v.begin() + 1, v.end());
    cout << "v: { ";
    copy(v.cbegin(), v.cend(), ostream_iterator<char>(cout, ", "));
    cout << "} " << endl;
    cout << boolalpha << "CHECK: 'q' is back ? " << (v.back() == 'q') << endl;

    //rotate only sub-vector 'a, b, c' such that 'c' is front
    rotate(v.begin(), find(v.begin(), v.end(), 'a'), v.end());
    rotate(v.begin(), v.begin() + 2, v.begin() + 3);
    cout << "v: { ";
    copy(v.cbegin(), v.cend(), ostream_iterator<char>(cout, ", "));
    cout << "} " << endl;
    cout << boolalpha << "CHECK: 'c, b, a' is front ? " << equal(v.begin(), v.begin() + 3, new int[3]{'c', 'a', 'b'}) << endl;

    return 0;
}
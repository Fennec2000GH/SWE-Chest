
#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
using namespace std;

//std::minmax_element
/* default (1)
 * template <class ForwardIterator>
 * pair<ForwardIterator,ForwardIterator> minmax_element (ForwardIterator first, ForwardIterator last);
*/
/* custom (2)
 * template <class ForwardIterator, class Compare>
 * pair<ForwardIterator,ForwardIterator> minmax_element (ForwardIterator first, ForwardIterator last, Compare comp);
 */

int main() {
    //main vector
    vector<unsigned> v(10);
    iota(v.begin(), v.end(), 20);
    random_shuffle(v.begin(), v.end());
    cout << "v: { ";
    copy(v.cbegin(), v.cend(), ostream_iterator<unsigned>(cout, ", "));
    cout << "} " << endl;

    //getting min max pair
    pair<vector<unsigned>::const_iterator, vector<unsigned>::const_iterator> p1 = minmax_element(v.cbegin(), v.cend());
    cout << "min value: " << *p1.first << ", min index: " << p1.first - v.cbegin() << endl;
    cout << "max value: " << *p1.second << ", max index: " << p1.second - v.cbegin() << endl;

    //getting min max pair using with vector of doubles
    vector<double> w(v.size());
    w[0] = 20.0;
    sort(v.begin(), v.end());
    transform(v.cbegin() + 1, v.cend(), w.begin(), [](unsigned a){ return 2.0 / (a % 20); });
    sort(w.begin(), w.end());
    cout << "w: { ";
    copy(w.cbegin(), w.cend(), ostream_iterator<double>(cout, ", "));
    cout << "} " << endl;
    pair<vector<double>::const_iterator, vector<double>::const_iterator> p2 = minmax_element(w.cbegin(), w.cend());
    cout << "min value: " << *p2.first << ", min index: " << p2.first - w.cbegin() << endl;
    cout << "max value: " << *p2.second << ", max index: " << p2.second - w.cbegin() << endl;

    //apply custom comp function, e.g. distance from the mean
    vector<unsigned> z = {0, 4, 8, 4, 12, 20};
    cout << "z: { ";
    copy(z.cbegin(), z.cend(), ostream_iterator<double>(cout, ", "));
    cout << "} " << endl;
    double z_mean = accumulate(z.cbegin(), z.cend(), 0) / double(z.size());
    cout << "z_mean: " << z_mean << endl;
    pair<vector<unsigned>::const_iterator, vector<unsigned>::const_iterator> p3 = minmax_element(z.cbegin(), z.cend(),
            [z_mean](unsigned a, unsigned b){ return (double(a) - z_mean) < (double(b) - z_mean); });
    cout << "min value: " << *p3.first << ", min index: " << p3.first - z.cbegin() << endl;
    cout << "max value: " << *p3.second << ", max index: " << p3.second - z.cbegin() << endl;

}

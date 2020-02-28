
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

//std::minmax
/* default (1)
 * template <class T>
 * constexpr pair <const T&,const T&> minmax (const T& a, const T& b);
*/
/* custom (2)
 * template <class T, class Compare>
 * constexpr pair <const T&,const T&> minmax (const T& a, const T& b, Compare comp);
 */
/* initializer list (3)
 * template <class T>
 * constexpr pair<T,T> minmax (initializer_list<T> il);
 */
/* template <class T, class Compare>
 * constexpr pair<T,T> minmax (initializer_list<T> il, Compare comp);
 */

int main() {
    //testing different ints
    pair<int, int> p1 = minmax(24, 42);
    cout << "min(24, 42): " << p1.first << ", max(24, 42): " << p1.second << endl;

    //testing different floats
    pair<int, int> p2 = minmax(1.234, 0.144);
    cout << "min(1.234, 0.144): " << p2.first << ", max(1.234, 0.144): " << p2.second << endl;

    //testing different doubles
    pair<double, double> p3 = minmax(-2314.3242, -4352.7342);
    cout << "min(-2314.3242, -4352.7342): " << p3.first << ", max(-2314.3242, -4352.7342): " << p3.second << endl;

    //testing different chars
    pair<char, char> p4 = minmax('d', 'c');
    cout << "min('d', 'c'): " << p4.first << ", max('d', 'c'): " << p4.second << endl;

    //testing different strings
    pair<string, string> p5 = minmax(string("scooby"), string("scooby-doo"));
    cout << "min(\"scooby\", \"scooby-doo\"): " << p5.first << ", max(\"scooby\", \"scooby-doo\"): " << p5.second << endl;

    //testing different bools
    pair<bool, bool> p6 = minmax(false, true);
    cout << "min(false, true): " << p6.first << ", max(false, true): " << p6.second << endl;

    //testing equal ints
    pair<int, int> p7 = minmax(12, 12);
    cout << "min(12, 12): " << p7.first << ", max(12, 12): " << p7.second << endl;

    //testing with custom function, in this case, compare by magnitude only
    pair<short, short> p8 = minmax(-12, 0, [](short a, short b){ return abs(b) > abs(a); });
    cout << "custom min(-12, 0): " << p8.first << ", custom max(-12, 0): " << p8.second << endl;

    //testing with initializer list of different ints
    pair<int, int> p9 = minmax({-25, 25});
    cout << "init list min({-25, 25}): " << p9.first << ", init list max({-25, 25}): " << p9.second << endl;
}
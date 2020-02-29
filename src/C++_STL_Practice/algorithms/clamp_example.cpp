
#include <algorithm>
#include <iostream>
using namespace std;

//std::clamp
/* (1) default
 * template<class T>
 * constexpr const T& clamp( const T& v, const T& lo, const T& hi );
*/
/* (2) predicate
 * template<class T, class Compare>
 * constexpr const T& clamp( const T& v, const T& lo, const T& hi, Compare comp );
 */

int main() {
    //testing with integer values
    cout << "bounds: [10, 20] " << endl;

    //argument < lower bound (expected: 10)
    cout << "clamp(4, 10, 20): " << clamp(4, 10, 20) << endl;

    //argument within bounds
    cout << "clamp(18, 10, 20): " << clamp(18, 10, 20) << endl;

    //argument > upper bound (expected: 20)
    cout << "clamp(22, 10, 20): " << clamp(22, 10, 20) << endl;
    cout << "----------------------------------------" << endl;

    //testing with strings
    cout << "bounds: [\"goat\", \"sheep\"] " << endl;

    //argument < lower bound (expected: "goat")
    cout << "clamp(\"cow\", \"goat\", \"sheep\" ): " << clamp(string("cow"), string("goat"), string("sheep")) << endl;

    //argument within bounds (expected: "panda")
    cout << "clamp(\"panda\", \"goat\", \"sheep\"): " << clamp(string("panda"), string("goat"), string("sheep")) << endl;

    //argument > upper bound (expected: "sheep")
    cout << "clamp(\"rabbit\", \"goat\", \"sheep\"): " << clamp(string("rabbit"), string("goat"), string("sheep")) << endl;
    cout << "----------------------------------------" << endl;

    return 0;
}








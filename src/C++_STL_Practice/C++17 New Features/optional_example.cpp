
#include <iostream>
#include <cmath>
#include <functional>
#include <optional>
using namespace std;

//std::optional
/* template< class T >
 * class optional;
 */

//MEMBER FUNCTIONS
// std::optional<T>::operator bool, std::optional<T>::has_value
/* constexpr explicit operator bool() const noexcept;
 * constexpr bool has_value() const noexcept;
 */

//std::optional<T>::value
/* constexpr T& value() &;
 * constexpr const T & value() const &;
 */
/* constexpr T&& value() &&;
 * constexpr const T&& value() const &&;
 */

//std::optional<T>::value
/* template< class U >
 * constexpr T value_or( U&& default_value ) const&;
 */
/* template< class U >
 * constexpr T value_or( U&& default_value ) &&;
 */

//std::optional<T>::swap
/* void swap( optional& other ) noexcept(//see below);
*/

//std::optional<T>::reset
/* void reset() noexcept;
 */

//std::optional<T>::emplace
/* template< class... Args >
 * T& emplace( Args&&... args );
 */
/* template< class U, class... Args >
 * T& emplace( std::initializer_list<U> ilist, Args&&... args );
 */

//OPTION DECLARATIONS
optional<string> opt2(bool b) { if(b) { return "opt1 value"; } else { return {}; }}
optional<bool> opt3(long a) { return a >= 0; }

int main() {
    //using std::optional as a pointer
    optional<char> opt1 = 'c';
    cout << "*opt1: " << *opt1 << endl;
    cout << "toupper(*opt1): " << (char) toupper(*opt1) << endl;
    cout << "---------------------------------------------------" << endl << endl;

    //creating std::optional using function (note that the function-definition must be first defined outside main)
    cout << "opt2(true).value(): " << opt2(true).value() << endl;
    cout << "opt2(true) -> size(): " << opt2(true)->size() << endl;
    cout << boolalpha << "opt2(true).has_value(): " << opt2(true).has_value() << endl;
    cout << boolalpha << "opt2(false).has_value(): " << opt2(false).has_value() << endl;
    try { opt2(false).value(); }
    catch (const bad_optional_access &e) { cout << e.what() << endl; }
    cout << "---------------------------------------------------" << endl << endl;

    //testing std::optional<T>::has_value when any input value generates some return value
    cout << boolalpha << "opt3(18).value(): " << opt3(18).value() << endl;
    cout << boolalpha << "opt3(-4).value(): " << opt3(-4).value() << endl;
    cout << boolalpha << "opt3(25).has_value(): " << opt3(25).has_value() << endl;
    cout << boolalpha << "opt3(25).has_value(): " << opt3(25).has_value() << endl;
    cout << "---------------------------------------------------" << endl << endl;

    //testing std::optional<T>::swap
    optional<char> opt4 = 'Q';
    opt4.swap(opt1);
    cout << "*opt: " << *opt1 << endl;
    cout << "*opt4: " << *opt4 << endl;
    cout << boolalpha << "opt4.has_value(): " << opt4.has_value() << endl;
    cout << "Destroying value in opt4 " << endl;
    opt4.reset();
    cout << boolalpha << "opt4.has_value(): " << opt4.has_value() << endl;
    opt4.emplace('J');
    cout << boolalpha << "opt4.has_value(): " << opt4.has_value() << endl;
    cout << "opt4.value(): " << opt4.value() << endl;
    cout << "---------------------------------------------------" << endl << endl;

    //testing std::make_optional
    optional<double> opt5 = make_optional(1.414);
    cout << "opt5.has_value(): " << opt4.has_value() << endl;
    cout << "*opt5: " << *opt5 << endl;
    cout << "---------------------------------------------------" << endl << endl;

    return 0;
}

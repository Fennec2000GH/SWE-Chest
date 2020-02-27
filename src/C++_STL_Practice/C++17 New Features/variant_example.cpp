//Credit (examples based off of): Anthony Calandra on Github
//https://github.com/AnthonyCalandra/modern-cpp-features/blob/master/CPP17.md#stdvariant

#include <cmath>
#include <iostream>
#include <variant>
using namespace std;

//std::variant
/* template <class... Types>
 * class variant;
 */

//MEMBER FUNCTIONS
//std::holds_alternative
/* template< class T, class... Types >
 * constexpr bool holds_alternative( const std::variant<Types...>& v ) noexcept;
 */

//std::get_if
/* template< std::size_t I, class... Types >
 * constexpr std::add_pointer_t<std::variant_alternative_t<I, std::variant<Types...>>> get_if( std::variant<Types...>* pv ) noexcept;
*/
/* template< std::size_t I, class... Types >
 * constexpr std::add_pointer_t<const std::variant_alternative_t<I, variant<Types...>>>
 * get_if( const std::variant<Types...>* pv ) noexcept;
 */
/* template< class T, class... Types >
 * constexpr std::add_pointer_t<T> get_if( std::variant<Types...>* pv ) noexcept;
 */
/* template< class T, class... Types >
 * constexpr std::add_pointer_t<const T> get_if( const std::variant<Types...>* pv ) noexcept;
 */

//std::variant<Types...>::index
/* constexpr std::size_t index() const noexcept;
 */

//std::variant<Types...>::emplace
/* template <class T, class... Args>
 * T& emplace(Args&&... args);
 */
/* template <class T, class U, class... Args>
 * T& emplace( std::initializer_list<U> il, Args&&... args );
 * /
/* template <size_t I, class... Args>
 std::variant_alternative_t<I, variant>& emplace( Args&&... args );
*/
/* template <size_t I, class U, class... Args>
 * std::variant_alternative_t<I, variant>& emplace( std::initializer_list<U> il, Args&&... args );
 */

//std::variant<Types...>::swap
/* void swap( variant& rhs ) noexcept(//see below);
 */

//type-safe union that can convert the sole value into the equivalent in another available alternative type

int main() {
    //getting elements with index and type
    variant<int, double> v{ 144 };
    cout << "get<0>(v): " << get<0>(v) << endl; //using index to get element
    cout << "get<int>(v): " << get<int>(v) << endl; //using type to get element
    cout << boolalpha << "Does v hold an alternative int value ? " << holds_alternative<int>(v) << endl;
    cout << boolalpha << "Does v hold an alternative double value ? " << holds_alternative<double>(v) << endl;
    cout << "Current index of (int) value: " << v.index() << endl;
    v = { 12.12 };
    cout << "v now holds the double 12.12 " << endl;

    //testing hold_alternative function
    cout << boolalpha << "Does v hold an alternative double value ? " << holds_alternative<double>(v) << endl;
    cout << "Current index of (double) value: " << v.index() << endl;
    cout << "get<1>(v): " << get<1>(v) << endl;
    cout << "get<double>(v): " << get<double>(v) << endl;

    //using get_if to return pointers to values
    add_pointer_t<int> it1 = get_if<int>(&v);
    add_pointer_t<double> it2 = get_if<double>(&v);
    if(it1 == nullptr) { cout << "v does not hold int " << endl; }
    else { cout << "v has an (int) value of " << *it1 << endl; }
    if(it2 == nullptr) { cout << "v does not hold double " << endl; }
    else { cout << "v has a (double) value of " << *it2 << endl; }
    v = { };
    //cout << "size of v (empty): " << v<int>::value << endl;

    //using emplace to restate values
    cout << "Emplacing new (int) value -25 " << endl;
    v.emplace<0>(-25);
    cout << "value in v: " << get<0>(v) << endl;

    //swapping values in old variant with values in another new variant
    cout << "creating new variant " << endl;
    variant<int, double> w;
    w.emplace<double>(pow(25, 25) / double(pow(10, 20)));
    v.swap(w);
    cout << "value in v: " << get<1>(v) << endl;
    cout << "value in w: " << get<0>(w) << endl;

}
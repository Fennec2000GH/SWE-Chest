
#define CATCH_CONFIG_MAIN
#include "../../catch.hpp"
#include <cstddef>
#include <iostream>
#include <string>
#include <type_traits>
using namespace std;

//std::is_void

/* template< class T >
inline constexpr bool is_void_v = is_void<T>::value;
*/

/* value
 true if T is the type void (possibly cv-qualified) , false otherwise
*/

/* operator bool
 converts the object to bool, returns value
*/

/* operator() returns value (public member function) */

void void_func() { return; }

TEST_CASE("void") {

    cout << "type: " << typeid(void_func()).name() << endl;
    cout << boolalpha << "Is nothing variable void? " << is_void<decltype(void_func())>::value << endl;
    cout << "Is int void? " << is_void<int>::value << endl;
    cout << "Is void void? " << is_void<void>::value << endl;

    CHECK(string(typeid(void_func()).name()) == "v");
    CHECK(is_void<decltype(void_func())>::value);
    CHECK(is_void<decltype(void_func())>());
    CHECK_FALSE(is_void<int>::value);
    CHECK(is_void<void>::value);

}

//std::nullptr_t

/* value
true if T is the type std::nullptr_t (possibly cv-qualified) , false otherwise
*/

/* operator bool
converts the object to bool, returns value
*/

/* operator()
returns value
*/

TEST_CASE("nullptr_t") {
    nullptr_t garbage = nullptr;
    cout << "type: " << typeid(garbage).name() << endl;
    cout << boolalpha << "Is garbage variable nullptr? " << is_null_pointer<decltype(garbage)>::value << endl;
    cout <<  "Is garbage variable nullptr? " << is_null_pointer<decltype(nullptr)>::value << endl;

    CHECK(string(typeid(garbage).name()).compare("Dn") == 0);
    CHECK(is_null_pointer<decltype(garbage)>::value);
    CHECK(is_null_pointer<decltype(garbage)>());
    CHECK(is_null_pointer<decltype(nullptr)>::value);

}

//std::is_integral

/* value
true if T is an integral type , false otherwise
*/

/* operator bool
converts the object to bool, returns value
*/

/* operator()
returns value
*/

TEST_CASE("is_integral") {
    short s = 25;
    int i = 25;
    long l = 1234567890;
    long long ll = 1234567890124567890;
    double d = 25.25;
    float f = 25.25;
    char c = 'j';
    bool b = true;
    string str = "not integral";

    cout << boolalpha << "Is short variable integral? " << is_integral<decltype(s)>::value << endl;
    cout << "Is int variable integral? " << is_integral<decltype(i)>::value << endl;
    cout << "Is long variable integral? " << is_integral<decltype(l)>::value << endl;
    cout << "Is long long variable integral? " << is_integral<decltype(ll)>::value << endl;
    cout << "Is double variable integral? " << is_integral<decltype(d)>::value << endl;
    cout << "Is float variable integral? " << is_integral<decltype(f)>::value << endl;
    cout << "Is char variable integral? " << is_integral<decltype(c)>::value << endl;
    cout << "Is bool variable integral? " << is_integral<decltype(b)>::value << endl;
    cout << "Is string variable integral? " << is_integral<decltype(s)>::value << endl;

    CHECK(is_integral<short>());
    CHECK(is_integral<int>());
    CHECK(is_integral<long>());
    CHECK(is_integral<long long>());
    CHECK_FALSE(is_integral<double>());
    CHECK_FALSE(is_integral<float>());
    CHECK(is_integral<char>());
    CHECK(is_integral<bool>());
    CHECK_FALSE(is_integral<string>());

}

//std::is_floating_point
/* value
true if T is a floating-point type (possibly cv-qualified) , false otherwise
*/

/* operator bool
converts the object to bool, returns value
*/

/* operator()
returns value
*/

TEST_CASE("is_floating_point") {
    float f = 18.18;
    double d = 18.18;
    long double ld = 18.18;
    unsigned u = 18;

    cout << boolalpha << "Is float variable floating point? " << is_floating_point<decltype(f)>::value << endl;
    cout << "Is double variable floating point? " << is_floating_point<decltype(f)>::value << endl;
    cout << "Is long double variable floating point? " << is_floating_point<decltype(d)>::value << endl;
    cout << "Is unsigned int variable floating point? " << is_floating_point<decltype(u)>::value << endl;

    CHECK(is_floating_point<float>());
    CHECK(is_floating_point<double>());
    CHECK(is_floating_point<long double>());
    CHECK_FALSE(is_floating_point<unsigned int>());

}



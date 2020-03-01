
#define _USE_MATH_DEFINES
#define CATCH_CONFIG_MAIN
#include "../../catch.hpp"
#include <any>
#include <cmath>
#include <iostream>
#include <iterator>
using namespace std;

//std::any

//MEMBER FUNCTIONS
//std::any::emplace
/* template< class ValueType, class... Args >
 * std::decay_t<ValueType>& emplace( Args&&... args );
*/
 /* template< class ValueType, class U, class... Args >
  * std::decay_t<ValueType>& emplace( std::initializer_list<U> il, Args&&... args );
 */

 //std::any::reset
 /* void reset() noexcept; */

//std::any::swap
/* void swap(any& other) noexcept; */

//std::any::has_value
/* bool has_value() const noexcept; */

//std::any::type
/* const std::type_info& type() const noexcept; */

//std::make_any
/*  template< class T, class... Args >
 * std::any make_any( Args&&... args );
*/
 /* template< class T, class U, class... Args >
  * std::any make_any( std::initializer_list<U> il, Args&&... args );
 */

TEST_CASE("constructors") {
    //testing constructor and basic functions
    any a = 12;
    cout << "TESTING ANY VARIABLE a... " << endl;
    cout << "a type: " << a.type().name() << ", a value: " << any_cast<int>(a) << endl;
    CHECK(string(a.type().name()) == "i");
    CHECK(any_cast<int>(a) == 12);

    //testing parameterized constructors
    any x(double(M_PI));
    cout << "x type: " << x.type().name() << ", x value: " << any_cast<double>(x) << endl;
    CHECK(string(x.type().name()) == "d");
    CHECK(any_cast<double>(x) == Approx(3.141592654).epsilon(0.01));

    any y(string("string inside y"));
    cout << "y type: " << y.type().name() << ", y value: " << any_cast<string>(y) << endl;
    CHECK(string(y.type().name()) == "NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE");
    CHECK(any_cast<string>(y) == "string inside y");

    any z { string("string inside z") };
    cout << "z type: " << z.type().name() << ", z value: " << any_cast<string>(z) << endl;
    CHECK(string(z.type().name()) == "NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE");
    CHECK(any_cast<string>(z) == "string inside z");

}

TEST_CASE("modifiers") {
    //testing std::any::emplace using double
    any a;
    a.emplace<double>(-6.78);
    cout << "a type: " << a.type().name() << ", a value: " << any_cast<double>(a) << endl;
    CHECK(string(a.type().name()) == "d");
    CHECK(any_cast<double>(a) == Approx(-6.78).epsilon(0.01));

    //testing std::any::emplace using long double
    a.emplace<long double>(-12354652634154254.1289735928137462);
    cout << "a type: " << a.type().name() << ", a value: " << any_cast<long double>(a) << endl;
    CHECK(string(a.type().name()) == "e");
    CHECK(any_cast<long double>(a) == Approx(-12354652634154254.1289735928137462).epsilon(0.01));

    //testing std::any::emplace using bool
    a.emplace<bool>(true);
    cout << boolalpha << "a type: " << a.type().name() << ", a value: " << any_cast<bool>(a) << endl;
    CHECK(string(a.type().name()) == "b");
    CHECK(any_cast<bool>(a) == true);

    try { cout << "value as int: " << any_cast<int>(a) << endl; }
    catch(bad_any_cast e) { e.what(); }
    CHECK_THROWS_AS(any_cast<int>(a), bad_any_cast);

    //testing std::any::reset
    a.reset();
    try { cout << "a value: " << any_cast<bool>(a) << endl; }
    catch(bad_any_cast e) { e.what(); }
    CHECK_THROWS_AS(any_cast<bool>(a), bad_any_cast);
    CHECK_FALSE(a.has_value());

    //testing std::any::swap
    any b = unsigned(25);
    cout << "TESTING ANY VARIABLE b... " << endl;
    cout << "b type: " << b.type().name() << ", b value: " << any_cast<unsigned>(b) << endl;
    CHECK(string(b.type().name()) == "j");
    CHECK(any_cast<unsigned>(b) == 25);

    a.emplace<unsigned>(36);
    a.swap(b);
    cout << "b type: " << b.type().name() << ", b value: " << any_cast<unsigned>(b) << endl;
    CHECK(string(b.type().name()) == "j");
    CHECK(any_cast<unsigned>(b) == 36);

}

TEST_CASE("make_any") {
    //testing std::make_any
    any a = make_any<char>('c');
    cout << "a type: " << a.type().name() << ", a value: " << any_cast<char>(a) << endl;
    CHECK(string(a.type().name()) == "c");
    CHECK(any_cast<char>(a) == 'c');

}



#define CATCH_CONFIG_MAIN
#include "../../catch.hpp"
#include <iostream>
#include <type_traits>
using namespace std;

//std::is_fundamental
/* If T is a fundamental type (that is, arithmetic type, void, or nullptr_t), provides the member constant value equal
 true. For any other type, value is false.
 */

/* value
 true if T is a fundamental type , false otherwise
*/

/* operator bool
converts the object to bool, returns value
*/

/* operator()
returns value
*/

void void_func() { return; }

TEST_CASE("is_fundamental") {
    int * null = nullptr;
    cout << "Is nullptr fundamental? " << is_fundamental<decltype(null)>::value << endl;
    cout << "Is void fundamental? " << is_fundamental<decltype(void_func())>::value << endl;
    cout << "Is int fundamental? " << is_fundamental<int>::value << endl;

    class cls {};
    cls cls_obj;
    cout << "Is class type fundamental? " << is_fundamental<decltype(cls_obj)>::value << endl;

    CHECK(is_fundamental<nullptr_t>());
    CHECK(is_fundamental<decltype(void_func())>());
    CHECK(is_fundamental<int>());
    CHECK_FALSE(is_fundamental<decltype(cls_obj)>());

}

//std::is_arithmetic
/* If T is an arithmetic type (that is, an integral type or a floating-point type) or a cv-qualified version thereof,
 * provides the member constant value equal true. For any other type, value is false.
 */

/* value
true if T is an arithmetic type , false otherwise
*/

/* operator bool
converts the object to bool, returns value
*/

/* operator()
returns value
*/

TEST_CASE("is_arithmetic") {
    unsigned u = 36;
    int i = 36;
    char c = 'z';
    bool b = true;
    double d = 36.36;
    const char * cc = "cc";

    cout << boolalpha << "Is unsigned variable arithmetic? " << is_fundamental<decltype(u)>::value << endl;
    cout << "Is int variable arithmetic? " << is_fundamental<decltype(i)>::value << endl;
    cout << "Is char variable arithmetic? " << is_fundamental<decltype(c)>::value << endl;
    cout << "Is bool variable arithmetic? " << is_fundamental<decltype(b)>::value << endl;
    cout << "Is double variable arithmetic? " << is_fundamental<decltype(d)>::value << endl;
    cout << "Is const char * variable arithmetic? " << is_fundamental<decltype(cc)>::value << endl;

    CHECK(is_arithmetic<unsigned int>());
    CHECK(is_arithmetic<int>());
    CHECK(is_arithmetic<char>());
    CHECK(is_arithmetic<bool>());
    CHECK(is_arithmetic<double>());
    CHECK_FALSE(is_arithmetic<const char *>());

}

//std::is_scalar
/* scalar types are (possibly cv-qualified) object types that are not array types or class types (see also
std::is_scalar); If T is a scalar type (that is a possibly cv-qualified arithmetic, pointer, pointer to member,
enumeration, or std::nullptr_t type), provides the member constant value equal true. For any other type, value is false
*/

/* value
true if T is a scalar type , false otherwise
*/

/* operator bool
converts the object to bool, returns value
*/

/* operator()
returns value
*/

int zero_func() { return 0; }

TEST_CASE("is_scalar") {
    double * null = nullptr;
    int i = 0;
    bool arr[6];
    class cls {};
    cls cls_obj;

    cout << boolalpha << "Is nullptr a scalar type? " << is_scalar<decltype(null)>::value << endl;
    cout << "Is void a scalar type? " << is_scalar<decltype(void_func())>::value << endl;
    cout << "Is int a scalar type? " << is_scalar<decltype(i)>::value << endl;
    cout << "Is function a scalar type? " << is_scalar<decltype(zero_func)>::value << endl;
    cout << "Is array a scalar type? " << is_scalar<decltype(arr)>::value << endl;
    cout << "Is class a scalar type? " << is_scalar<decltype(cls_obj)>::value << endl;

    CHECK(is_scalar<nullptr_t>());
    CHECK(is_scalar<decltype(void_func())>());
    CHECK(is_scalar<int>());
    CHECK_FALSE(is_scalar<function<void()>>());
    CHECK_FALSE(is_scalar<bool[]>());
    CHECK_FALSE(is_scalar<decltype(cls_obj)>());

}

//std::is_object
/* If T is an object type (that is any possibly cv-qualified type other than function, reference, or void types),
 * provides the member constant value equal true. For any other type, value is false. object types are
 * (possibly cv-qualified) types that are not function types, reference types, or the type void
 */

/* value
 true if T is an object type , false otherwise
*/

/* operator bool
converts the object to bool, returns value
*/

/* operator()
returns value
*/

TEST_CASE("is_object") {
    int i = 18;
    int * null = nullptr;
    class cls {};
    cls cls_obj;
    int &i_ref = i;

    cout << "Is int an object type? " << is_object<decltype(i)>::value << endl;
    cout << "Is class an object type? " << is_object<decltype(cls_obj)>::value << endl;
    cout << "Is void an object type? " << is_object<decltype(void_func())>::value << endl;
    cout << "Is nullptr an object type? " << is_object<decltype(null)>::value << endl;
    cout << "Is function an object type? " << is_object<decltype(zero_func)>::value << endl;
    cout << "Is reference an object type? " << is_object<decltype(i_ref)>::value << endl;

    CHECK(is_object<int>());
    CHECK(is_object<decltype(cls_obj)>());
    CHECK_FALSE(is_object<void>());
    CHECK(is_object<nullptr_t>());
    CHECK_FALSE(is_object<decltype(zero_func)>());
    CHECK_FALSE(is_object<int&>());

}



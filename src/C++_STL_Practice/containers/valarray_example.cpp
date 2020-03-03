
#define CATCH_CONFIG_MAIN
#include "../../catch.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <valarray>
using namespace std;

//std::valarray

//NMEMBER FUNCTIONS
//std::slice::slice
/* slice() */
/* slice( std::size_t start, std::size_t size, std::size_t stride ); */
/* slice( const slice& other ); */

//std::valarray<T>::swap
/* void swap( valarray& other ); */
/* void swap( valarray& other ) noexcept; */

//std::valarray<T>::size
/* std::size_t size() const; */

//std::valarray<T>::resize
/* void resize( std::size_t count, T value = T() ); */

//std::valarray<T>::sum
/* T sum() const; */

//std::valarray<T>::min
/* T min() const; */

//std::valarray<T>::max
/* T max() const; */

//std::valarray<T>::shift
/* valarray<T> shift( int count ) const; */

//std::valarray<T>::cshift
/* valarray<T> cshift( int count ) const; */

//std::valarray<T>::apply
/* valarray<T> apply( T func(T) ) const; */
/* valarray<T> apply( T func(const T&) ) const; */

//NON-MEMBER FUNCTIONS (mostly math functions for array manipulation)
//std::abs(std::valarray)
/* template< class T >
valarray<T> abs( const valarray<T>& va );
*/

//std::exp(std::valarray)
/* template< class T >
valarray<T> exp( const valarray<T>& va );
*/

//std::log(std::valarray)
/* template< class T >
valarray<T> log( const valarray<T>& va );
 */

//std::log10(std::valarray)
/* template< class T >
valarray<T> log10( const valarray<T>& va );
*/

//std::pow(std::valarray)
/* template< class T >
std::valarray<T> pow( const std::valarray<T>& base, const std::valarray<T>& exp );
°/
/* template< class T >
std::valarray<T> pow( const std::valarray<T>& base, const typename std::valarray<T>::value_type& vexp );
*/
/* template< class T >
std::valarray<T> pow( const typename std::valarray<T>::value_type& vbase, const std::valarray<T>& exp );
*/

//std::sqrt(std::valarray)
/* template< class T >
valarray<T> sqrt( const valarray<T>& va );
*/

//std::sin(std::valarray)
/* template< class T >
valarray<T> sin( const valarray<T>& va );
*/

//std::cos(std::valarray)
/* template< class T >
valarray<T> cos( const valarray<T>& va );
*/

//std::tan(std::valarray)
/* template< class T >
valarray<T> tan( const valarray<T>& va );
*/

//std::asin(std::valarray)
/* template< class T >
valarray<T> asin( const valarray<T>& va );
*/

//std::acos(std::valarray)
/* template< class T >
valarray<T> acos( const valarray<T>& va );
*/

//std::atan(std::valarray)
/* template< class T >
valarray<T> atan( const valarray<T>& va );
*/

//std::atan2(std::valarray)
/* template< class T >
std::valarray<T> atan2( const std::valarray<T>& y, const std::valarray<T>& x );
*/
/* template< class T >
std::valarray<T> atan2( const std::valarray<T>& y, const typename std::valarray<T>::value_type& vx );
*/
/*template< class T >
std::valarray<T> atan2( const typename std::valarray<T>::value_type& vy, const std::valarray<T>& x );
 */

//std::sinh(std::valarray)
/* template< class T >
valarray<T> sinh( const valarray<T>& va );
*/

//std::cosh(std::valarray)
/* template< class T >
valarray<T> cosh( const valarray<T>& va );
*/

//std::tanh(std::valarray)
/* template< class T >
valarray<T> tanh( const valarray<T>& va );
*/

TEST_CASE("constructing valarray") {
    valarray<int> v1 = {-6, 7, 9, -3, 2, 8};
    cout << "v: { ";
    copy(begin(v1), end(v1), ostream_iterator<int>(cout, ", "));
    cout << "} " << endl;
    CHECK(v1.size() == 6);

}

TEST_CASE("slicing") {
    valarray<unsigned short> v2 = {6, 6, 6, 6, 6, 6};
    cout << "v2: { ";
    copy(begin(v2), end(v2), ostream_iterator<unsigned short>(cout, ", "));
    cout << "} " << endl;

    unsigned short index = 0;
    transform(begin(v2), end(v2), begin(v2), [&index](unsigned short s){ ++index; if(index % 2 == 0) { return (unsigned short)(index / 2); } return (unsigned short)6; }); // {6, 1, 6, 2, 6, 3}
    cout << "v2: { ";
    copy(begin(v2), end(v2), ostream_iterator<unsigned short>(cout, ", "));
    cout << "} " << endl;
    valarray<int> expected = {6, 1, 6, 2, 6, 3};
    CHECK(equal(begin(v2), end(v2), begin(expected)));

    //slicing
    valarray<unsigned short> sl1 = v2[slice(1, 2, 2)];
    cout << "v2[slice(1, 2, 2)]: { ";
    copy(begin(sl1), end(sl1), ostream_iterator<unsigned short>(cout, ", "));
    cout << "} " << endl;
    vector<unsigned short> temp = {1, 2, 3};
    CHECK(equal(begin(sl1), end(sl1), begin(temp)));

    valarray<unsigned short> sl2 = v2[slice(0, 4, 1)];
    cout << "v2[slice(0, 4, 1)]: { ";
    copy(begin(sl2), end(sl2), ostream_iterator<unsigned short>(cout, ", "));
    cout << "} " << endl;
    temp = {6, 1, 6, 2};
    CHECK(equal(begin(sl2), end(sl2), begin(temp)));

}

TEST_CASE("member functions") {
    valarray<double> v3 = {-1.234, 2.132, 4.621, 0.112};
    valarray<double> v3_copy(v3);
    cout << "v3: { ";
    copy(begin(v3), end(v3), ostream_iterator<double>(cout << setprecision(4), ", "));
    cout << "} " << endl;
    cout << "v3_copy: { ";
    copy(begin(v3_copy), end(v3_copy), ostream_iterator<double>(cout << setprecision(4), ", "));
    cout << "} " << endl;

    //swapping whole container
    valarray<double> v4 = {0.634, -1.444, 2.245, 7.898, 3.144, 6.612};
    cout << "v4: { ";
    copy(begin(v4), end(v4), ostream_iterator<double>(cout << setprecision(4), ", "));
    cout << "} " << endl;
    cout << "swapping v3 and v4... " << endl;
    v4.swap(v3);
    cout << "v4: { ";
    copy(begin(v4), end(v4), ostream_iterator<double>(cout << setprecision(4), ", "));
    cout << "} " << endl;
    CHECK(equal(begin(v4), end(v4), begin(v3_copy)));

    //checking the size and then resizing
    cout << "v4.size(): " << v4.size() << endl;
    CHECK(v4.size() == 4);
    cout << "reducing size by 1... " << endl;
    v4.resize(3);
    cout << "v4.size(): " << v4.size() << endl;
    cout << "v4: { ";
    copy(begin(v4), end(v4), ostream_iterator<double>(cout << fixed << showpoint << setprecision(4), ", "));
    cout << "} " << endl;
    CHECK(v4.size() == 3);

    //summing the elements
    cout << setprecision(3) << "summing elements of v4: " << double(v4.sum()) << endl;
    CHECK(v4.sum() == Approx(5.319).epsilon(0.01));

    //finding the minimum and maximum
    cout << setprecision(3) << "minimum element in v4: " << double(v4.min()) << endl;
    cout << setprecision(3) << "maximum element in v4: " << double(v4.max()) << endl;
    CHECK(v4.min() == Approx(-1.234).epsilon(0.01));
    CHECK(v4.max() == Approx(4.621).epsilon(0.01));


    //shifitng elements
    cout << "v3: { ";
    copy(begin(v3), end(v3), ostream_iterator<double>(cout << fixed << showpoint << setprecision(4), ", "));
    cout << "} " << endl;
    cout << "shift left 2 places... " << endl;
    valarray<double> v3_1 = v3.shift(2);
    cout << "v3 (after shift 2): { ";
    copy(begin(v3_1), end(v3_1), ostream_iterator<double>(cout << fixed << showpoint << setprecision(4), ", "));
    cout << "} " << endl;
    valarray<double> temp = {2.245, 7.898, 3.144, 6.612, 0.0, 0.0};
    CHECK(equal(begin(v3_1), end(v3_1), begin(temp)));

    cout << "shifting v3 circularly to the right 2 places... " << endl;
    valarray<double> v3_2 = v3.cshift(-2);
    cout << "v3 (after cshift -2): { ";
    copy(begin(v3_2), end(v3_2), ostream_iterator<double>(cout << fixed << showpoint << setprecision(4), ", "));
    cout << "} " << endl;
    temp = {3.144, 6.612, 0.634, -1.444, 2.245, 7.898};
    CHECK(equal(begin(v3_2), end(v3_2), begin(temp)));

}

TEST_CASE("apply") {
    valarray<long> v4 = {11, 12, 13, 14, 15, 16};
    cout << "v4: { ";
    copy(begin(v4), end(v4), ostream_iterator<long>(cout, ", "));
    cout << "} " << endl;

    //multiply each element by 10
    valarray<long> v4_1 = v4.apply([](long l) { return l *= 10; });
    cout << "v4 (after apply): { ";
    copy(begin(v4_1), end(v4_1), ostream_iterator<long>(cout, ", "));
    cout << "} " << endl;
    valarray<long> temp = {110, 120, 130, 140, 150, 160};
    CHECK(equal(begin(v4_1), end(v4_1), begin(temp)));

    //square each element
    valarray<long> v4_2 = pow(v4, 2);
    cout << "v4 (after pow): { ";
    copy(begin(v4_2), end(v4_2), ostream_iterator<long>(cout, ", "));
    cout << "} " << endl;
    temp = {121, 144, 169, 196, 225, 256};
    CHECK(equal(begin(v4_2), end(v4_2), begin(temp)));

}



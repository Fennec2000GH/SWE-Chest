
#include <array>
#include <iostream>
#include <iterator>
using namespace std;

//std::array
/* template<class T, std::size_t N> struct array; */

//MEMBER FUNCTIONS
//std::array<T, N>::at
/* constexpr reference at( size_type pos ); */
/* constexpr const_reference at( size_type pos ) const; */

//std::array<T, N>::front
/* constexpr reference front(); */
/* constexpr const_reference front() const; */

//std::array<T, N>::back
/* constexpr reference back(); */

/* constexpr const_reference back() const; */

//std::array<T, N>::data
/* constexpr T* data() noexcept; */
/* constexpr const T* data() const noexcept; */

//std::array<T, N>::empty
/* constexpr bool empty() const noexcept; */

//std::array<T, N>::size
/* constexpr size_type size() const noexcept; */

//std::array<T, N>::max_size
/* constexpr size_type max_size() const noexcept; */

//std::array<T, N>::fill
/* void fill( const T& value ); */

//std::array<T, N>::swap
/* void swap( array& other ) noexcept(//see below ); */

//std::get(std::array)
/* template< std::size_t I, class T, std::size_t N >
 * constexpr T& get( std::array<T,N>& a ) noexcept;
 */

/* template< std::size_t I, class T, std::size_t N >
 * constexpr T&& get( std::array<T,N>&& a ) noexcept;
 */

/* template< std::size_t I, class T, std::size_t N >
 * constexpr const T& get( const std::array<T,N>& a ) noexcept;
 */

/* template< std::size_t I, class T, std::size_t N >
 * constexpr const T&& get( const std::array<T,N>&& a ) noexcept;
 */

int main() {
    //testing insigned integer array
    array<unsigned, 6> arr1 = {0, 4, 8, 2, 5, 2};
    cout << "arr1: { ";
    copy(arr1.cbegin(), arr1.cend(), ostream_iterator<unsigned>(cout, ", "));
    cout << "} " << endl;
    cout << "arr1.size(): " << arr1.size() << endl;
    cout << "-------------------------------------------------------------" << endl;

    //testing double array
    array<double, 4> arr2{{-1.423, -0.352, 6.431, 9.846}};
    cout << "arr2: { ";
    copy(arr2.cbegin(), arr2.cend(), ostream_iterator<double>(cout, ", "));
    cout << "} " << endl;
    cout << "arr2.size(): " << arr2.size() << endl;
    cout << "-------------------------------------------------------------" << endl;

    //testing char array
    array<char, 10> arr3;
    cout << boolalpha << "arr3.empty(): " << arr3.empty() << endl;
    cout << "adding char elements... " << endl;
    for(int i = 0; i < 10; i++) { arr3[i] = char(i + 97); }
    cout << boolalpha << "arr3.empty(): " << arr3.empty() << endl;
    cout << "arr3: { ";
    copy(arr2.cbegin(), arr2.cend(), ostream_iterator<double>(cout, ", "));
    cout << "} " << endl;
    cout << "arr3.front(): " << arr3.front() << endl;
    cout << "arr3.back(): " << arr3.back() << endl;
    cout << "-------------------------------------------------------------" << endl;

    //testing string array
    array<string, 6> arr4;
    arr4.fill(string("word"));
    cout << "arr4: { ";
    copy(arr4.cbegin(), arr4.cend(), ostream_iterator<string>(cout, ", "));
    cout << "} " << endl;
    array<string, 6> temp = {string("front"), string("word"), string("back")};
    arr4.swap(temp);
    cout << "arr4: { ";
    copy(arr4.cbegin(), arr4.cend(), ostream_iterator<string>(cout, ", "));
    cout << "} " << endl;
    cout << "note that the last 3 slots hold default values " << endl;
    cout << "arr4.size(): " << arr4.size() << endl;
    cout << "arr4.at(0): " << arr4.at(0) << endl;
    cout << "get<1>(arr4): " << get<1>(arr4) << endl;
    cout << "arr4[2]: " << arr4[2] << endl;
    cout << "last 3 elements of arr4: { ";
    copy(arr4.cbegin() + 3, arr4.cend(), ostream_iterator<string>(cout, ", "));
    cout << "} " << endl;
    cout << "-------------------------------------------------------------" << endl;

    //testing bool array
    array<bool, 6> arr5 = {true, true, true, true, true, false};
    cout << "arr5: { ";
    copy(arr5.cbegin(), arr5.cend(), ostream_iterator<bool>(cout << boolalpha, ", "));
    cout << "} " << endl;
    cout << "arr5.max_size(): " << arr5.max_size() << endl;
    cout << "converting arr5 to raw bool array... " << endl;
    bool * rawArr5 = arr5.data();
    cout << "rawArr5: { ";
    copy(rawArr5, rawArr5 + sizeof(rawArr5) / sizeof(bool), ostream_iterator<bool>(cout << boolalpha, ", "));
    cout << "} " << endl;
    cout << "size of rawArr5: " << sizeof(rawArr5) / sizeof(bool) << endl;
    cout << "looks like the size for rawArr5 was 2 over the actual size of arr5... " << endl;
    cout << "--------------------------------------------------------------" << endl;

    return 0;
}


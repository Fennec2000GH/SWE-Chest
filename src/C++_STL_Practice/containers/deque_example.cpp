
#define CATCH_CONFIG_MAIN
#include "../../catch.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

//CONSTRUCTORS
//std::deque<T,Allocator>::deque
/* deque(); */
/* explicit deque( const Allocator& alloc ); */
/* explicit deque( size_type count, const T& value = T(), const Allocator& alloc = Allocator()); */
/* deque( size_type count, const T& value, const Allocator& alloc = Allocator()); */
/* explicit deque( size_type count ); */
/* explicit deque( size_type count, const Allocator& alloc = Allocator() ); */
/* template< class InputIt >
deque( InputIt first, InputIt last, const Allocator& alloc = Allocator() );
*/
/* deque( const deque& other ); */
/* deque( const deque& other, const Allocator& alloc ); */
/* deque( deque&& other ); */
/* deque( deque&& other, const Allocator& alloc ); */
/* deque( std::initializer_list<T> init, const Allocator& alloc = Allocator() ); */

//MEMBER FUNCTIONS
//std::deque<T,Allocator>::assign
/* void assign( size_type count, const T& value ); */
/* template< class InputIt >
void assign( InputIt first, InputIt last );
*/
/* void assign( std::initializer_list<T> ilist ); */

//std::deque<T,Allocator>::get_allocator
/* allocator_type get_allocator() const; */

//std::deque<T,Allocator>::at
/* reference at( size_type pos ); */
/* const_reference at( size_type pos ) const; */

//std::deque<T,Allocator>::front
/* reference front(); */
/* const_reference front() const; */

//std::deque<T,Allocator>::back
/* reference back(); */
/* const_reference back() const; */

//std::deque<T,Allocator>::empty
/* bool empty() const; */
/* bool empty() const noexcept; */

//std::deque<T,Allocator>::size
/* size_type size() const; */
/* size_type size() const noexcept; */

//std::deque<T,Allocator>::max_size
/* size_type max_size() const; */
/* size_type max_size() const noexcept; */

//std::deque<T,Allocator>::shrink_to_fit
/* void shrink_to_fit(); */

//std::deque<T,Allocator>::clear
/* void clear(); */
/* void clear() noexcept; */

//std::deque<T,Allocator>::insert
/* iterator insert( iterator pos, const T& value ); */
/* iterator insert( const_iterator pos, const T& value ); */
/* iterator insert( const_iterator pos, T&& value ); */
/* void insert( iterator pos, size_type count, const T& value ); */
/* iterator insert( const_iterator pos, size_type count, const T& value ); */
/* template< class InputIt >
void insert( iterator pos, InputIt first, InputIt last);
*/
/* template< class InputIt >
iterator insert( const_iterator pos, InputIt first, InputIt last );
*/
/* iterator insert( const_iterator pos, std::initializer_list<T> ilist ); */

//std::deque<T,Allocator>::emplace
/* template< class... Args >
iterator emplace( const_iterator pos, Args&&... args );
*/

//std::deque<T,Allocator>::erase
/* iterator erase( iterator pos ); */
/* iterator erase( const_iterator pos ); */
/* iterator erase( iterator first, iterator last ); */
/* iterator erase( const_iterator first, const_iterator last ); */

//std::deque<T,Allocator>::push_back
/* void push_back( const T& value ); */
/* void push_back( T&& value ); */

//std::deque<T,Allocator>::emplace_back
/* template< class... Args >
void emplace_back( Args&&... args );
*/
/* template< class... Args >
reference emplace_back( Args&&... args );
*/

//std::deque<T,Allocator>::pop_back
/* void pop_back(); */

//std::deque<T,Allocator>::push_front
/* void push_front( const T& value ); */
/* void push_front( T&& value ); */

//std::deque<T,Allocator>::emplace_front
/* template< class... Args >
void emplace_front( Args&&... args );
*/
/* template< class... Args >
reference emplace_front( Args&&... args );
*/

//std::deque<T,Allocator>::pop_front
/* void pop_front(); */

//std::deque<T,Allocator>::resize
/* void resize( size_type count, T value = T() ); */
/* void resize( size_type count ); */
/* void resize( size_type count, const value_type& value ); */

//std::deque<T,Allocator>::swap
/* void swap( deque& other ); */
/* void swap( deque& other ) noexcept(//see below ); */

//NON-MEMBER FUNCTIONS
//std::swap(std::deque)
/* template< class T, class Alloc >
void swap( deque<T,Alloc>& lhs, deque<T,Alloc>& rhs );
*/
/* template< class T, class Alloc >
void swap( deque<T,Alloc>& lhs, deque<T,Alloc>& rhs ) noexcept(//see below); */

//C++20
//std::erase, std::erase_if (std::deque)
/* template< class T, class Alloc, class U >
typename std::deque<T,Alloc>::size_type
erase(std::deque<T,Alloc>& c, const U& value);
*/
/* template< class T, class Alloc, class Pred >
typename std::deque<T,Alloc>::size_type
erase_if(std::deque<T,Alloc>& c, Pred pred);
*/

TEST_CASE("construction") {
    //testing empty constructor
    deque<int> d1;
    cout << boolalpha << "d1 empty? " << d1.empty() << endl;
    CHECK(d1.empty());

    //testing initialized constructors
    deque<short> d2({-4, -2, 8, 3, 4, -1});
    cout << "d2: { ";
    copy(d2.cbegin(), d2.cend(), ostream_iterator<short>(cout, ", "));
    cout << "} " << endl;
    CHECK(d2.size() == 6);

    deque<char> d3{'e', 'r', 'y', 't', 'h', 'r', 'o', 'c', 'y', 't', 'e'};
    cout << "d3: { ";
    copy(d3.cbegin(), d3.cend(), ostream_iterator<char>(cout, ", "));
    cout << "} " << endl;
    cout << "d3.size(): " << d3.size() << endl;
    cout << "d3.max_size(): " << d3.max_size() << endl;
    CHECK(d3.size() == 11);
    CHECK(d3.max_size() > d3.size());
    cout << "d3.front(): " << d3.front() << endl;
    cout << "d3.back(): " << d3.back() << endl;
    CHECK(d3.front() == 'e');
    CHECK(d3.front() == d3.back());

    //testing copy constructors
    deque<char> d4(d3.cbegin(), d3.cbegin() + 4);
    cout << "d4: { ";
    copy(d4.cbegin(), d4.cend(), ostream_iterator<char>(cout, ", "));
    cout << "} " << endl;
    cout << "d4.max_size(): " << d4.max_size() << endl;
    cout << "shrinking d4 to fit... " << endl;
    d4.shrink_to_fit();
    cout << "d4.max_size(): " << d4.max_size() << endl;
    CHECK(d4.size() < d4.max_size());

    deque<char> d5(d4);
    cout << "d5: { ";
    copy(d5.cbegin(), d5.cend(), ostream_iterator<char>(cout, ", "));

}

TEST_CASE("member functions") {
    //testing access functions
    deque<unsigned> d1 = {4, 8, 3, 1, 1, 2};
    cout << "d1: { ";
    copy(d1.cbegin(), d1.cend(), ostream_iterator<unsigned>(cout, ", "));
    cout << "} " << endl;
    cout << "d1.at(1): " << d1.at(1) << endl;
    cout << "d1[2]: " << d1[2] << endl;
    cout << "d1.front(): " << d1.front() << endl;
    cout << "d1.back(): " << d1.back() << endl;
    CHECK(d1.at(1) == 8);
    CHECK(d1[2] == 3);
    CHECK(d1.front() == 4);
    CHECK(d1.back());

}

TEST_CASE("mutator functions") {
    //testing mutator functions
    deque<unsigned> d1;
    cout << "inserting new elements into d2... " << endl;
    d1.push_back(10);
    d1.emplace_front(0);
    d1.emplace(d1.cend(), 20);
    d1.emplace_back(30);
    d1.insert(d1.cend(), 40); // {0, 10, 20, 30, 40}
    cout << "d1: { ";
    copy(d1.cbegin(), d1.cend(), ostream_iterator<unsigned>(cout, ", "));
    cout << "} " << endl;
    vector<unsigned> temp = {0, 10, 20, 30, 40};
    CHECK(equal(d1.cbegin(), d1.cend(), temp.cbegin()));
    cout << "inserting more elements into d2... " << endl;
    temp = {50, 60, 70};
    d1.insert(d1.cend(), temp.cbegin(), temp.cend()); //{0, 10, 20, 30, 40, 50, 60, 70}
    d1.insert(d1.cend(), 4, 25); // {0, 10, 20, 30, 40, 50, 60, 70, 25, 25, 25, 25}
    d1.insert(d1.cbegin() + 1, {1, 2, 3, 4, 5, 6, 7, 8, 9}); // {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 40, 50, 60, 70, 25, 25, 25, 25}
    cout << "d2: { ";
    copy(d1.cbegin(), d1.cend(), ostream_iterator<unsigned>(cout, ", "));
    cout << "} " << endl;
    temp = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 40, 50, 60, 70, 25, 25, 25, 25};
    CHECK(equal(d1.cbegin(), d1.cend(), temp.cbegin()));

    //testing erase
    deque<unsigned>::const_iterator it = find(d1.cbegin(), d1.cend(), 40);
    deque<unsigned> d2(it, d1.cend()); // {40, 50, 60, 70, 25, 25, 25, 25}
    cout << "d2: { ";
    copy(d2.cbegin(), d2.cend(), ostream_iterator<unsigned>(cout, ", "));
    cout << "} " << endl;
    temp = {40, 50, 60, 70, 25, 25, 25, 25};
    CHECK(equal(d2.cbegin(), d2.cend(), temp.cbegin()));

    cout << "erasing some elements from d3... " << endl;
    d2.erase(d2.cbegin() + 1); // {40, 60, 70, 25, 25, 25, 25}
    cout << "d2: { ";
    copy(d2.cbegin(), d2.cend(), ostream_iterator<unsigned>(cout, ", "));
    cout << "} " << endl;
    temp = {40, 60, 70, 25, 25, 25, 25};
    CHECK(equal(d2.cbegin(), d2.cend(), temp.cbegin()));

    d2.erase(d2.cbegin() + 3, d2.cend()); // {40, 60, 70}
    cout << "d2: { ";
    copy(d2.cbegin(), d2.cend(), ostream_iterator<unsigned>(cout, ", "));
    cout << "} " << endl;
    temp = {40, 60, 70};
    CHECK(equal(d2.cbegin(), d2.cend(), temp.cbegin()));

    d2.pop_back(); // {40, 60}
    cout << "d2: { ";
    copy(d2.cbegin(), d2.cend(), ostream_iterator<unsigned>(cout, ", "));
    cout << "} " << endl;
    CHECK(d2.front() == 40);
    CHECK(d2.back() == 60);

    d2.pop_front(); // {60}
    cout << "d3: { ";
    copy(d2.cbegin(), d2.cend(), ostream_iterator<unsigned>(cout, ", "));
    cout << "} " << endl;
    CHECK(d2.size() == 1);
    CHECK(d2[0] == 60);

    d2.clear();
    cout << "d2: { ";
    copy(d2.cbegin(), d2.cend(), ostream_iterator<unsigned>(cout, ", "));
    cout << "} " << endl;
    CHECK(d2.empty());

}

TEST_CASE("non-member and other functions"){
    //testing resize
    deque<string> d1 = {"cat", "dog", "chicken", "duck"};
    cout << "d1: { ";
    copy(d1.cbegin(), d1.cend(), ostream_iterator<string>(cout, ", "));
    cout << "} " << endl;
    CHECK(d1.size() == 4);

    d1.resize(3);
    cout << "d1: { ";
    copy(d1.cbegin(), d1.cend(), ostream_iterator<string>(cout, ", "));
    cout << "} " << endl;
    vector<string> temp = {"cat", "dog", "chicken"};
    CHECK(equal(d1.cbegin(), d1.cend(), temp.cbegin()));

    d1.resize(6, "filler");
    cout << "d1: { ";
    copy(d1.cbegin(), d1.cend(), ostream_iterator<string>(cout, ", "));
    cout << "} " << endl;
    temp = {"cat", "dog", "chicken", "filler", "filler", "filler"};
    CHECK(equal(d1.cbegin(), d1.cend(), temp.cbegin()));

    //testing swap
    deque<string> d2({"1", "2.00", "three", "IV"});
    cout << "d2: { ";
    copy(d2.cbegin(), d2.cend(), ostream_iterator<string>(cout, ", "));
    cout << "} " << endl;
    cout << "swapping d1 with d2... " << endl;
    d1.swap(d2);
    cout << "d1: { ";
    copy(d1.cbegin(), d1.cend(), ostream_iterator<string>(cout, ", "));
    cout << "} " << endl;
    temp = {"1", "2.00", "three", "IV"};
    CHECK(equal(d1.cbegin(), d1.cend(), temp.cbegin()));

    cout << "swapping back d1 and d2 to their original contents... " << endl;
    swap(d1, d2);
    cout << "d1: { ";
    copy(d1.cbegin(), d1.cend(), ostream_iterator<string>(cout, ", "));
    cout << "} " << endl;
    cout << "d2: { ";
    copy(d2.cbegin(), d2.cend(), ostream_iterator<string>(cout, ", "));
    cout << "} " << endl;
    CHECK(equal(d2.cbegin(), d2.cend(), temp.cbegin()));
    temp = {"cat", "dog", "chicken", "filler", "filler", "filler"};
    CHECK(equal(d1.cbegin(), d1.cend(), temp.cbegin()));

}


#define CATCH_CONFIG_MAIN
#include "../../catch.hpp"
#include <iostream>
#include <iterator>
#include <unordered_set>
using namespace std;

//CONSTRUCTORS
//std::unordered_multiset<Key,Hash,KeyEqual,Allocator>::unordered_multiset
/* template<class Key, class Hash = std::hash<Key>, class KeyEqual = std::equal_to<Key>, class Allocator = std::allocator<Key>>
 * class unordered_multiset;
*/
/* namespace pmr {
    template <class Key, class Hash = std::hash<Key>, class Pred = std::equal_to<Key>>
    using unordered_multiset = std::unordered_multiset<Key, Hash, Pred,
    std::pmr::polymorphic_allocator<Key>>
}
*/

//MEMBER-FUNCTIONS
//std::unordered_multiset<Key,Hash,KeyEqual,Allocator>::empty
/* bool empty() const noexcept; */

//std::unordered_multiset<Key,Hash,KeyEqual,Allocator>::size
/* size_type size() const noexcept; */

//std::unordered_multiset<Key,Hash,KeyEqual,Allocator>::max_size
/* size_type max_size() const noexcept; */

//std::unordered_multiset<Key,Hash,KeyEqual,Allocator>::clear
/* void clear() noexcept; */

//std::unordered_multiset<Key,Hash,KeyEqual,Allocator>::insert
/* iterator insert( const value_type& value ); */
/* iterator insert( value_type&& value ); */
/* iterator insert( const_iterator hint, const value_type& value ); */
/* iterator insert( const_iterator hint, value_type&& value ); */
/* template< class InputIt >
void insert( InputIt first, InputIt last );
*/
/* void insert( std::initializer_list<value_type> ilist ); */
/* iterator insert(node_type&& nh); */
/* iterator insert(const_iterator hint, node_type&& nh); */

//std::unordered_multiset<Key,Hash,KeyEqual,Allocator>::emplace
/* template< class... Args >
iterator emplace( Args&&... args );
*/

//std::unordered_multiset<Key,Hash,KeyEqual,Allocator>::emplace_hint
/* template <class... Args>
iterator emplace_hint( const_iterator hint, Args&&... args );
*/

//std::unordered_multiset<Key,Hash,KeyEqual,Allocator>::erase
/*iterator erase( const_iterator pos );
iterator erase( const_iterator first, const_iterator last );
size_type erase( const key_type& key );
*/

//std::unordered_multiset<Key,Hash,KeyEqual,Allocator>::swap
/* void swap( unordered_multiset& other );
void swap( unordered_multiset& other ) noexcept(//see below );
*/

//std::unordered_multiset<Key,Hash,KeyEqual,Allocator>::extract
/* node_type extract( const_iterator position ); */
/* node_type extract( const key_type& x ); */

//std::unordered_multiset<Key,Hash,KeyEqual,Allocator>::merge
/* template<class H2, class P2>
void merge(std::unordered_set<Key, H2, P2, Allocator>& source);
*/
/* template<class H2, class P2>
void merge(std::unordered_set<Key, H2, P2, Allocator>&& source);
*/
/* template<class H2, class P2>
void merge(std::unordered_multiset<Key, H2, P2, Allocator>& source);
*/
/* template<class H2, class P2>
void merge(std::unordered_multiset<Key, H2, P2, Allocator>&& source);
*/

//std::unordered_multiset<Key,Hash,KeyEqual,Allocator>::count
/* size_type count( const Key& key ) const; */

//std::unordered_multiset<Key,Hash,KeyEqual,Allocator>::find
/* iterator find( const Key& key ); */
/* const_iterator find( const Key& key ) const; */

//C++20
//std::unordered_multiset<Key,Hash,KeyEqual,Allocator>::contains
/* bool contains( const Key& key ) const; */
/* template< class K > bool contains( const K& x ) const; */

//std::pair<iterator,iterator> equal_range( const Key& key );
/* std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const; */

//std::unordered_multiset<Key,Hash,KeyEqual,Allocator>::bucket_count
/* size_type bucket_count() const; */

//std::unordered_multiset<Key,Hash,KeyEqual,Allocator>::max_bucket_count
/* size_type max_bucket_count() const; */

//std::unordered_multiset<Key,Hash,KeyEqual,Allocator>::bucket_size
/* size_type bucket_size( size_type n ) const; */

//std::unordered_multiset<Key,Hash,KeyEqual,Allocator>::bucket
/* size_type bucket( const Key& key ) const; */

//std::unordered_multiset<Key,Hash,KeyEqual,Allocator>::load_factor
/* float load_factor() const; */

//std::unordered_multiset<Key,Hash,KeyEqual,Allocator>::max_load_factor
/* float max_load_factor() const; */
/* void max_load_factor( float ml ); */

//std::unordered_multiset<Key,Hash,KeyEqual,Allocator>::rehash
/* void rehash( size_type count ); */

//std::unordered_multiset<Key,Hash,KeyEqual,Allocator>::reserve
/* void reserve( size_type count ); */

//NON_MEMBER FUNCTIONS
//std::swap(std::unordered_multiset)
/* template< class Key, class Hash, class KeyEqual, class Alloc >
void swap( unordered_multiset<Key,Hash,KeyEqual,Alloc>& lhs, unordered_multiset<Key,Hash,KeyEqual,Alloc>& rhs );
*/
/* template< class Key, class Hash, class KeyEqual, class Alloc >
void swap( unordered_multiset<Key,Hash,KeyEqual,Alloc>& lhs, unordered_multiset<Key,Hash,KeyEqual,Alloc>& rhs ) noexcept(//see below);
*/

//C++20
//std::erase_if (std::unordered_multiset)
/* template< class Key, class Hash, class KeyEqual, class Alloc, class Pred >
typename std::unordered_multiset<Key,Hash,KeyEqual,Alloc>::size_type
erase_if(std::unordered_multiset<Key,Hash,KeyEqual,Alloc>& c, Pred pred);
*/

TEST_CASE("construction") {
    unordered_multiset<int> m1;
    cout << boolalpha << "m1 empty? " << m1.empty() << endl;
    CHECK(m1.empty());
    unordered_multiset<double> m2({2.234, 4.523, 7.463, 8.192});
    cout << boolalpha << "m2 empty? " << m2.empty() << endl;
    CHECK_FALSE(m2.empty());
    cout << "m2.size(): " << m2.size() << endl;
    CHECK(m2.size() == 4);

}

TEST_CASE("basic functions") {
    unordered_multiset<short> m({-4, 1, 1, 1, 1, 2, 2, 3, 3});
    cout << "m: { ";
    copy(m.cbegin(), m.cend(), ostream_iterator<short>(cout, ", "));
    cout << "} " << endl;

    //testing clear
    cout << "m cleared... " << endl;
    m.clear();
    cout << boolalpha << "m empty? " << m.empty() << endl;
    CHECK(m.empty());

    //testing insertions
    cout << "inserting some new elements into m... " << endl;
    m.insert(-6);
    m.insert(0);
    m.insert({1, 1, 2, 2, 2, 2, 4, 4});
    cout << "m: { ";
    copy(m.cbegin(), m.cend(), ostream_iterator<short>(cout, ", "));
    cout << "} " << endl;
    CHECK(m.count(1) == 2);
    CHECK(m.count(2) == 4);
    CHECK(m.count(4) == 2);

    //testing erase
    m.erase(m.find(0)); //erasing 0
    cout << "erasing key = 2 from m... " << endl;
    m.erase(2); //erasing all 2's
    cout << "m: { ";
    copy(m.cbegin(), m.cend(), ostream_iterator<short>(cout, ", "));
    cout << "} " << endl;
    CHECK(m.count(0) == 0);
    CHECK(m.count(2) == 0);

    //testing emplace
    short initList[4] = {-8, -12, -18, -25};
    for(short &s : initList) { m.emplace(s); }
    cout << "m: { ";
    copy(m.cbegin(), m.cend(), ostream_iterator<short>(cout, ", "));
    cout << "} " << endl;
    CHECK(m.size() == 9);

}

TEST_CASE("algorithm functions") {
    unordered_multiset<char> m1({'a', 'c', 'e', 'e', 'e', 'f'});
    cout << "m1: { ";
    copy(m1.cbegin(), m1.cend(), ostream_iterator<char>(cout, ", "));
    cout << "} " << endl;
//    CHECK(m1.contains('e'));
    pair<unordered_multiset<char>::const_iterator, unordered_multiset<char>::const_iterator> p = m1.equal_range('e');
    CHECK(distance(p.first, p.second) == 3);

    unordered_multiset<char> m2({'x', 'x', 'y', 'z'});
    cout << "m2: { ";
    copy(m2.cbegin(), m2.cend(), ostream_iterator<char>(cout, ", "));
    cout << "} " << endl;

//    testing swap
    cout << "swapping m1 and m2... " << endl;
    m1.swap(m2);
    cout << "m1: { ";
    copy(m1.cbegin(), m1.cend(), ostream_iterator<char>(cout, ", "));
    cout << "} " << endl;

    //extracting and changing keys
    cout << "replacing 'z' with 'w' in  m1... " << endl;
    auto nt = m1.extract('z');
    nt.value() = 'w';
    m1.insert(move(nt));
    cout << "m1: { ";
    copy(m1.cbegin(), m1.cend(), ostream_iterator<char>(cout, ", "));
    cout << "} " << endl;
    CHECK(m1.count('z') == 0);
    CHECK(m1.count('w') == 1);

    //merging m2 into m1
    cout << "merging m2 into m1... " << endl;
    m1.merge(m2);
    cout << "m1: { ";
    copy(m1.cbegin(), m1.cend(), ostream_iterator<char>(cout, ", "));
    cout << "} " << endl;
    cout << "m2: { ";
    copy(m2.cbegin(), m2.cend(), ostream_iterator<char>(cout, ", "));
    cout << "} " << endl;
    CHECK(m1.size() == 10);

}


TEST_CASE("properties") {
    unordered_multiset<unsigned long> m({123, 421, 938, 231, 482, 231587093456});
    cout << "m.bucket_count(): " << m.bucket_count() << endl;
    cout << "m.max_bucket_count(): " << m.max_bucket_count() << endl;
    cout << "number of elements in bucket indexed at 0, or m.bucket_size(0): " << m.bucket_size(0);
    for(int i = 0; i < 10; i++) { m.emplace(120); }
    CHECK(m.count(120) == 10);
    int index = m.bucket(120);
    cout << "index of key = 120 is: " << index << endl;
    cout << "size of bucket holding key = 120: " << m.bucket_size(index) << endl;
    cout << "load factor: " << m.load_factor() << endl;
    cout << "max load factor: " << m.max_load_factor() << endl;
    CHECK(m.load_factor() > 0);
    CHECK(m.max_load_factor() > m.load_factor());

}


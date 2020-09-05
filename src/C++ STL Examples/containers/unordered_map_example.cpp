
#define  CATCH_CONFIG_MAIN
#include "../../catch.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_map>
using namespace std;

//CONSTRUCTORS
//std::unordered_map<Key,T,Hash,KeyEqual,Allocator>::unordered_map
/* unordered_map() : unordered_map( size_type(//implementation-defined) ) {} */
/* explicit unordered_map( size_type bucket_count, const Hash& hash = Hash(), const key_equal& equal = key_equal(), const Allocator& alloc = Allocator() ); */
/* unordered_map( size_type bucket_count, const Allocator& alloc ) : unordered_map(bucket_count, Hash(), key_equal(), alloc) {} */
/* unordered_map( size_type bucket_count, const Hash& hash, const Allocator& alloc ) : unordered_map(bucket_count, hash, key_equal(), alloc) {} */
/* explicit unordered_map( const Allocator& alloc ); */
/* template< class InputIt >
unordered_map( InputIt first, InputIt last, size_type bucket_count = //implementation-defined, const Hash& hash = Hash(), const key_equal& equal = key_equal(), const Allocator& alloc = Allocator() );
*/
/* template< class InputIt >
unordered_map( InputIt first, InputIt last, size_type bucket_count, const Allocator& alloc ) : unordered_map(first, last, bucket_count, Hash(), key_equal(), alloc) {} */
/* template< class InputIt >
unordered_map( InputIt first, InputIt last, size_type bucket_count, const Hash& hash, const Allocator& alloc ) : unordered_map(first, last, bucket_count, hash, key_equal(), alloc) {} */
/* unordered_map( const unordered_map& other ); */
/* unordered_map( const unordered_map& other, const Allocator& alloc ); */
/* unordered_map( unordered_map&& other ); */
/* unordered_map( unordered_map&& other, const Allocator& alloc ); */
/* unordered_map( std::initializer_list<value_type> init, size_type bucket_count = //implementation-defined, const Hash& hash = Hash(), const key_equal& equal = key_equal(), const Allocator& alloc = Allocator() ); */
/* unordered_map( std::initializer_list<value_type> init, size_type bucket_count, const Allocator& alloc ) : unordered_map(init, bucket_count, Hash(), key_equal(), alloc) {} */
/* unordered_map( std::initializer_list<value_type> init, size_type bucket_count, const Hash& hash, const Allocator& alloc ) : unordered_map(init, bucket_count, hash, key_equal(), alloc) {} */

//MEMBER FUNCTIONS
//std::unordered_map<Key,T,Hash,KeyEqual,Allocator>::empty
/* bool empty() const noexcept; */

//std::unordered_map<Key,T,Hash,KeyEqual,Allocator>::size
/* size_type size() const noexcept; */

//std::unordered_map<Key,T,Hash,KeyEqual,Allocator>::max_size
/* size_type max_size() const noexcept; */

//std::unordered_map<Key,T,Hash,KeyEqual,Allocator>::clear
/* void clear() noexcept; */

//std::unordered_map<Key,T,Hash,KeyEqual,Allocator>::insert
/* std::pair<iterator,bool> insert( const value_type& value ); */
/* std::pair<iterator,bool> insert( value_type&& value ); */
/* template< class P >
std::pair<iterator,bool> insert( P&& value );
*/
/* iterator insert( const_iterator hint, const value_type& value ); */
/* iterator insert( const_iterator hint, value_type&& value ); */
/* template< class P >
iterator insert( const_iterator hint, P&& value );
*/
/* template< class InputIt >
void insert( InputIt first, InputIt last );
*/
/* void insert( std::initializer_list<value_type> ilist ); */
/* insert_return_type insert(node_type&& nh); */
/* iterator insert(const_iterator hint, node_type&& nh); */

//std::unordered_map<Key,T,Hash,KeyEqual,Allocator>::insert_or_assign
/* template <class M>
pair<iterator, bool> insert_or_assign(const key_type& k, M&& obj);
*/
/* template <class M>
pair<iterator, bool> insert_or_assign(key_type&& k, M&& obj);
*/
/* template <class M>
iterator insert_or_assign(const_iterator hint, const key_type& k, M&& obj);
*/
/* template <class M>
iterator insert_or_assign(const_iterator hint, key_type&& k, M&& obj);
*/

//std::unordered_map<Key,T,Hash,KeyEqual,Allocator>::emplace
/* template< class... Args >
std::pair<iterator,bool> emplace( Args&&... args );
*/

//std::unordered_map<Key,T,Hash,KeyEqual,Allocator>::emplace_hint
/* template <class... Args>
iterator emplace_hint( const_iterator hint, Args&&... args );
*/

//std::unordered_map<Key,T,Hash,KeyEqual,Allocator>::try_emplace
/* template <class... Args>
pair<iterator, bool> try_emplace(const key_type& k, Args&&... args);
*/
/* template <class... Args>
pair<iterator, bool> try_emplace(key_type&& k, Args&&... args);
*/
/* template <class... Args>
iterator try_emplace(const_iterator hint, const key_type& k, Args&&... args);
*/
/* template <class... Args>
iterator try_emplace(const_iterator hint, key_type&& k, Args&&... args);
*/

//std::unordered_map<Key,T,Hash,KeyEqual,Allocator>::erase
/* iterator erase( const_iterator pos ); */
/* iterator erase( const_iterator first, const_iterator last ); */
/* size_type erase( const key_type& key ); */

//std::unordered_map<Key,T,Hash,KeyEqual,Allocator>::swap
/* void swap( unordered_map& other ); */
/* void swap( unordered_map& other ) noexcept(//see below ); */

//std::unordered_map<Key,T,Hash,KeyEqual,Allocator>::extract
/* node_type extract( const_iterator position ); */
/* node_type extract( const key_type& x ); */

//std::unordered_map<Key,T,Hash,KeyEqual,Allocator>::merge
/* template<class H2, class P2>
void merge(std::unordered_map<Key, T, H2, P2, Allocator>& source);
*/
/* template<class H2, class P2>
void merge(std::unordered_map<Key, T, H2, P2, Allocator>&& source);
*/
/* template<class H2, class P2>
void merge(std::unordered_multimap<Key, T, H2, P2, Allocator>& source);
*/
/* template<class H2, class P2>
void merge(std::unordered_multimap<Key, T, H2, P2, Allocator>&& source);
*/

//std::unordered_map<Key,T,Hash,KeyEqual,Allocator>::at
/* T& at( const Key& key ); */
/* const T& at( const Key& key ) const; */

//std::unordered_map<Key,T,Hash,KeyEqual,Allocator>::count
/* size_type count( const Key& key ) const; */
/* template< class K >
size_type count( const K& x ) const;
*/

//std::unordered_map<Key,T,Hash,KeyEqual,Allocator>::find
/* iterator find( const Key& key ); */
/* const_iterator find( const Key& key ) const; */

//C++20
//std::unordered_map<Key,T,Hash,KeyEqual,Allocator>::contains
/* bool contains( const Key& key ) const; */
/* template< class K > bool contains( const K& x ) const; */

//std::unordered_map<Key,T,Hash,KeyEqual,Allocator>::equal_range
/* std::pair<iterator,iterator> equal_range( const Key& key ); */
/* std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const; */

//std::unordered_map<Key,T,Hash,KeyEqual,Allocator>::bucket_count
/* size_type bucket_count() const; */

//std::unordered_map<Key,T,Hash,KeyEqual,Allocator>::max_bucket_count
/* size_type max_bucket_count() const; */

//std::unordered_map<Key,T,Hash,KeyEqual,Allocator>::bucket_size
/* size_type bucket_size( size_type n ) const; */

//std::unordered_map<Key,T,Hash,KeyEqual,Allocator>::bucket
/* size_type bucket( const Key& key ) const; */

//std::unordered_map<Key,T,Hash,KeyEqual,Allocator>::load_factor
/* float load_factor() const; */

//std::unordered_map<Key,T,Hash,KeyEqual,Allocator>::max_load_factor
/* float max_load_factor() const; */
/* void max_load_factor( float ml ); */

//std::unordered_map<Key,T,Hash,KeyEqual,Allocator>::rehash
/* void rehash( size_type count ); */

//std::unordered_map<Key,T,Hash,KeyEqual,Allocator>::reserve
/* void reserve( size_type count ); */

//NON-MEMBER FUNCTIONS
//std::swap(std::unordered_map)
/* template< class Key, class T, class Hash, class KeyEqual, class Alloc >
void swap( unordered_map<Key,T,Hash,KeyEqual,Alloc>& lhs, unordered_map<Key,T,Hash,KeyEqual,Alloc>& rhs );
*/
/* template< class Key, class T, class Hash, class KeyEqual, class Alloc >
void swap( unordered_map<Key,T,Hash,KeyEqual,Alloc>& lhs, unordered_map<Key,T,Hash,KeyEqual,Alloc>& rhs ) noexcept(//see below );
*/

TEST_CASE("construction") {
    unordered_map<int, string> m1;
    cout << boolalpha << "m1.empty(): " << m1.empty() << endl;
    CHECK(m1.empty());

    unordered_map<char, long> m2({{'c', 42}, {'d', 12}, {'j', 32}, {'s', 88}});
    cout << "m2: { ";
    unordered_map<char, long>::const_iterator it2;
    for(it2 = m2.cbegin() ; it2 != m2.cend(); it2++) { cout << "{" << it2 -> first << ", " << it2 -> second << "}, "; }
    cout << "} " << endl;
    CHECK_FALSE(m2.empty());
    CHECK(m2.size() == 4);

    unordered_map<char, long> m3(m2);
    CHECK(m3.size() == m2.size());
    cout << "m3: { ";
    unordered_map<char, long>::const_iterator it3;
    for(it3 = m3.cbegin(); it3 != m3.cend(); it3++) { cout << "{ " << it3 -> first << ", " << it3 -> second << "}, "; }
    cout << "} " << endl;


}

TEST_CASE("basic member functions") {
    unordered_map<unsigned, double> m({ {3, 4.123}, {6, 5.134}, {9, 3.444}, {4, 6.232} });
    cout << "m: { ";
    unordered_map<unsigned, double>::const_iterator it;
    for(it = m.cbegin(); it != m.cend(); it++) { cout << "{ " << it -> first << ", " << it -> second << "}, "; }
    cout << "} " << endl;

    //testing insert
    cout << "inserting new elements into m... " << endl;
    m.insert({12, 4.112});
    m.insert({16, 6.224});
    cout << "values corresponding to keys 12 and 16 are " << m[12] << " and " << m[16] << ", respectively " << endl;
    cout << "m: { ";
    for(it = m.cbegin(); it != m.cend(); it++) { cout << "{ " << it -> first << ", " << it -> second << "}, "; }
    cout << "} " << endl;
    CHECK(m.size() == 6);
    CHECK(m.at(12) == Approx(4.112).epsilon(0.01));
    CHECK(m[16] == Approx(6.224).epsilon(0.01));

    //testing insert_or_assign
    cout << "possibly replacing value of key 16 with new value of 3.333 " << endl;
    m.insert_or_assign(16, 3.333);
    cout << "m: { ";
    for(it = m.cbegin(); it != m.cend(); it++) { cout << "{ " << it -> first << ", " << it -> second << "}, "; }
    cout << "} " << endl;
    CHECK(m[16] == Approx(3.333).epsilon(0.01));

    //testing erase
    cout << "erasing elements from m... " << endl;
    m.erase(12);
    m.erase(m.find(16));
    cout << "m: { ";
    for(it = m.cbegin(); it != m.cend(); it++) { cout << "{ " << it -> first << ", " << it -> second << "}, "; }
    cout << "} " << endl;
    CHECK(m.count(12) == 0);
    CHECK(m.count(16) == 0);
    CHECK(m.size() == 4);

    //tesing emplace
    cout << "emplacing some new elements into m... " << endl;
    m.emplace(make_pair<unsigned, double>(25, 2.567));
    m.emplace_hint(m.find(16), make_pair<unsigned, double>(17, 1.222));
    m.try_emplace(20, 4.234);
    m.try_emplace(9, 4.466); //fails since 9 is already inserted
    cout << "m: { ";
    for(it = m.cbegin(); it != m.cend(); it++) { cout << "{ " << it -> first << ", " << it -> second << "}, "; }
    cout << "} " << endl;
    CHECK(m[25] == Approx(2.567).epsilon(0.01));
    CHECK(m[20] == Approx(4.234).epsilon(0.01));
    CHECK_FALSE(m[9] == Approx(4.466).epsilon(0.01));

}

TEST_CASE("non-member functions") {
    unordered_map<long, char> m;
    for(int k = 0; k < 10; k++) { m.emplace(k, char(97 + k)); }
    cout << "m: { ";
    unordered_map<long, char>::const_iterator it;
    for(it = m.cbegin(); it != m.cend(); it++) { cout << "{ " << it -> first << ", " << it -> second << "}, "; }
    cout << "} " << endl;
    //C++20
//    erase_if(m, [](long l, char c){ return l % 2 == 1; }); //erase all odd keys
//    cout << "m: { ";
//    for(it = m.cbegin(); it != m.cend(); it++) { cout << "{ " << it -> first << ", " << it -> second << "}, "; }
//    cout << "} " << endl;
//    CHECK(m.size() == 4);

    unordered_map<long, char> n({ {25, 'd'} });
    cout << "n: { ";
    unordered_map<long, char>::const_iterator itn;
    for(itn = n.cbegin(); itn != n.cend(); itn++) { cout << "{ " << itn -> first << ", " << itn -> second << "}, "; }
    cout << "} " << endl;
    cout << "swapping m and n... " << endl;
    swap(m, n);
    cout << "m: { ";
    for(it = m.cbegin(); it != m.cend(); it++) { cout << "{ " << it -> first << ", " << it -> second << "}, "; }
    cout << "} " << endl;
    CHECK(m.size() == 1);
    CHECK(n.size() == 10);

}

TEST_CASE("properties") {
    unordered_map<char, char> m({ {'a', 'b'}, {'c', 'd'}, {'e', 'f'}, {'y', 'z'} });
    cout << "m.bucket_count(): " << m.bucket_count() << endl;
    cout << "m.max_bucket_count(): " << m.max_bucket_count() << endl;
    cout << "m.bucket_size(0): " << m.bucket_size(0) << endl;
    int index = m.bucket('y'); //index of bucket holding the key 'y'
    cout << "m.bucket_size(index): " << m.bucket_size(index) << endl;
    cout << "m.load_factor(): " << m.load_factor() << endl;
    cout << "m.max_load_factor(): " << m.max_load_factor() << endl;
    CHECK(m.bucket_count() > 0);
    CHECK(m.max_bucket_count() > m.bucket_count());
    CHECK(m.load_factor() > 0);
    CHECK(m.max_load_factor() > m.load_factor());

}


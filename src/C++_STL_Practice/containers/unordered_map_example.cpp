
#define  CATCH_CONFIG_MAIN
#include "../../catch.hpp"
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







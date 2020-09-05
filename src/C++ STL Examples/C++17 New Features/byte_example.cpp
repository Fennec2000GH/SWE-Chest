
#define CATCH_CONFIG_MAIN

#include "../../catch.hpp"
#include <cstddef>
#include <iostream>
using namespace std;

//std::byte
//This type is not a char type nor an arithmetic type.This is a basic byte of data, a collection of bits. The only
//operators allowed are the bitwise operators. No member functions exist.

//NON-MEMBER FUNCTIONS
//std::to_integer
/* template <class IntegerType>
 * constexpr IntegerType to_integer(std::byte b) noexcept;
*/

TEST_CASE("shifting bits") {
    byte b{144}; //10010000
    cout << "b: " << int(b) << endl;
    CHECK(int(b) == 144);
    b >>= 2; //00100100
    cout << "b >>= 2: " << int(b) << endl;
    CHECK(int(b) == 36);
    b <<= 1; //01001000
    cout << "b <= 1: " << int(b) << endl;
    b <<= 2; //00100000
    cout << "b <<= 2" << int(b) << endl;
    CHECK(int(b) == 32);

}

TEST_CASE("logic operators") {
    byte b1{18}; //00010010
    byte b2{25}; //00011001
    cout << "b1: " << int(b1) << ", b2: " << int(b2) << endl;
    cout << "b1 & b2: " << int(b1 & b2) << endl; //00010000
    CHECK(int(b1 & b2) == 16);
    cout << "b1 | b2: " << int(b1 | b2) << endl; //00011011
    CHECK(int(b1 | b2) == 27);
    cout << "b1 ^ b2: " << int(b1 ^ b2) << endl; //00001011
    CHECK(int(b1 ^ b2) == 11);

}


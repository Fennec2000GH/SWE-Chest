
#include <algorithm>
#include <unordered_map>
using namespace std;

/* https://leetcode.com/problems/isomorphic-strings/ */
//Problem:
//Given two strings s and t, determine if they are isomorphic.
//Two strings are isomorphic if the characters in s can be replaced to get t.
//All occurrences of a character must be replaced with another character while preserving the order of characters. No
//two characters may map to the same character but a character may map to itself.

//Level: Easy

//Results:
/*
Definition unclear for isomorphic string. Below is implementation for bidirectionally binded string, meaning each
character has one and only one dual regardless of perspective from either string.
*/

bool isIsomorphic(string s, string t) {
    //edge case: empty string
    if(s.empty() || t.empty()) { return true; }

    //edge case: single char long
    if(s.size() * t.size() == 1) { return true; }

    unordered_map<char, char> m;
    for(int i = 0; i < s.size(); i++) {
        //check for char pairs not encountered before
        if(m.count(s[i]) == 0 && m.count(t[i]) == 0) {
            m[s[i]] = t[i];
            if(s[i] != t[i]) { m[t[i]] = s[i]; }
        }
        //if the 2 characters are not assigned to each other bidirectionally
        if(m.count(s[i]) == 1 && m.count(t[i]) == 0) { return false; }
        if(m.count(t[i]) == 1 && m.count(s[i]) == 0) { return false; }
        if(s[i] != m[m[s[i]]] || t[i] != m[m[t[i]]]) { return false; }
    }

    return true;
}


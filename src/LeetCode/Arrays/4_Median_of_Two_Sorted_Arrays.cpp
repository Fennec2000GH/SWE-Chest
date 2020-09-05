
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

// https://leetcode.com/problems/median-of-two-sorted-arrays/

// Problem:
/* Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
Follow up: The overall run time complexity should be O(log (m+n)). */

// Level: Hard

// Results: Not tested yet

// solution
// returns index of matching value, or -1 if not found
int binarySearch(const vector<int>& v, int val) {
    // edge cases
    if(v.empty()) { return -1; }
    if(v.size() == 1) { return v.front() == val ? 0 : -1; }
    if(v.front() == val) { return 0; }
    if(v.back() == val) { return v.size() - 1; }

    int left = 0, right = v.size() - 1, mid = 1;
    while(mid != left && mid != right) {
        mid = (left + right) / 2;
        if(val < v[mid]) { right = mid - 1; }
        else if(val > v[mid]) { left = mid + 1; }
        else { return mid; }
    }

    return -1;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int>::iterator it1 = nums1.begin();
    vector<int>::iterator it2 = nums2.begin();
    double val;
    for (unsigned counter = 0; counter < unsigned(round((nums1.size() + nums2.size()) / 2.0)); counter++) {
        if(*it1 <= *it2) {
            val = double(*it1);
            advance(it1, 1);
        } else {
            val = double(*it2);
            advance(it2, 1);
        }
    }
    if((nums1.size() + nums2.size()) % 2 == 0) { val = (val + min(*it1, *it2)) / 2.0; }
    return val;
}

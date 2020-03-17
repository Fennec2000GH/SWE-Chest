
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

//Problem:
//Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

/*
Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
*/

//Level: Easy

//Results:
/*
Runtime: 4 ms, faster than 84.60% of C++ online submissions for Merge Sorted Array.
Memory Usage: 8.1 MB, less than 100.00% of C++ online submissions for Merge Sorted Array.
*/

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //edge case: empty nums1
    if (nums1.empty()) {
        copy(nums2.begin(), nums2.end(), nums1.begin());
        return;
    }

    //edge case: empty nums2
    if (nums2.empty()) { return; }

    copy(nums1.begin(), nums1.begin() + m, nums1.begin() + n);

    cout << "nums1 (shifted): { ";
    copy(nums1.cbegin(), nums1.cend(), ostream_iterator<int>(cout, ", "));
    cout << "} " << endl;


    //indices of each vector and where to insert next sorted element in nums1
    int nums1_index = n;
    int nums2_index = 0;
    int insert_index = 0;
    while ((nums1_index < m + n) && (nums2_index < n)) {
        if (nums1[nums1_index] <= nums2[nums2_index]) {
            nums1[insert_index] = nums1[nums1_index];
            ++nums1_index;
        } else {
            nums1[insert_index] = nums2[nums2_index];
            ++nums2_index;
        }
        ++insert_index;
    }

    //only elements left to insert are in nums1
    if (nums1_index < m + n) { copy(nums1.begin() + nums1_index, nums1.end(), nums1.begin() + insert_index); }
    else if (nums2_index < n) { copy(nums2.begin() + nums2_index, nums2.end(), nums1.begin() + insert_index); }

}

int main() {
    vector<int> nums1 = {1,2,4,5,6,0};
    vector<int> nums2 = {3};

    cout << "nums1: { ";
    copy(nums1.cbegin(), nums1.cend(), ostream_iterator<int>(cout, ", "));
    cout << "} " << endl;
    cout << "nums2: { ";
    copy(nums2.cbegin(), nums2.cend(), ostream_iterator<int>(cout, ", "));
    cout << "} " << endl;

    merge(nums1, 5, nums2, 1);

    cout << "nums1 (merged): { ";
    copy(nums1.cbegin(), nums1.cend(), ostream_iterator<int>(cout, ", "));
    cout << "} " << endl;

}



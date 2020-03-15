
#include <vector>
using namespace std;

/* https://leetcode.com/problems/palindrome-linked-list/ */
//Problem:
//Given a singly linked list, determine if it is a palindrome.

//Level: Easy

//Results
/*
Runtime: 20 ms, faster than 93.57% of C++ online submissions for Palindrome Linked List.
Memory Usage: 12.9 MB, less than 39.66% of C++ online submissions for Palindrome Linked List.
*/
/*
    Heavy memory usage was due to making a vector copy of the linked list. This, however, allowed for extreme time
    efficiency in determining whether a linked list is a palindrome or not.
 */

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode* head) {
    //edge case: empty linked list
    if(head == nullptr) { return true; }

    //edge case: singleton linked list
    if(head -> next == nullptr) { return true; }

    vector<int> v;
    ListNode * it = head;
    while(it != nullptr) {
        v.push_back(it -> val);
        it = it -> next;
    }

    for(int i = 0; i < v.size() / 2; i++) { if(v[i] != v[v.size() - 1 - i]) { return false; } }
    return true;

}

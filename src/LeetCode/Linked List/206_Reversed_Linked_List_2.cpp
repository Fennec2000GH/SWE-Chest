
#include <vector>
using namespace std;

/* https://leetcode.com/problems/reverse-linked-list/ */
//Problem:
//Reverse a singly linked list.

//Level: Easy

//Results
/*
Runtime: 8 ms, faster than 94.78% of C++ online submissions for Reverse Linked List.
Memory Usage: 9.1 MB, less than 98.47% of C++ online submissions for Reverse Linked List.
*/
/* This is an improvement over the first trial in memory efficiency. The vector used directly holds the value of each
 * node, storing int rather than pointers to each ListNode. Additionally, there is no need to redirect the "next"
 * pointer for any ListNode as simply changing the val variable in each ListNode to its mirror val across the axis of
 * symmetry of the linked list already reverses the linked list. The first trial had to physically reverse the
 * direction of the "next" pointer in each ListNode.
 */

//Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//reverses the val in linked list without
ListNode* reverseList(ListNode* head) {
    //edge case: empty linked list
    if(head == nullptr) { return nullptr; }

    //edge case: singleton linked list
    if(head -> next == nullptr) { return head; }

    //vector version of linked list
    vector<int> values = {head -> val};

    //pointer to tail
    ListNode * tail = head;
    while(tail -> next != nullptr) { tail = tail -> next; values.push_back(tail -> val); }

    reverse(values.begin(), values.end());
    tail = head;
    for(int i : values) { tail -> val = i; tail = tail -> next; }

    return head;
}




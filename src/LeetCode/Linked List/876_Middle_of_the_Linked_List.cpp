

#include <vector>
using namespace std;

/* https://leetcode.com/problems/middle-of-the-linked-list/ */
//Problem:
//Given a non-empty, singly linked list with head node head, return a middle node of linked list.
//If there are two middle nodes, return the second middle node.

//Level: Easy

//Results
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Middle of the Linked List.
Memory Usage: 7.9 MB, less than 100.00% of C++ online submissions for Middle of the Linked List.
*/
/*
    Simply finding how long the linked list is takes O(n) by iterating through it. Then traverse half the size from the
    head to get to the middle ListNode.
 */

 //Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* middleNode(ListNode* head) {
    //edge case: empty linked list:
    if(head == nullptr) { return nullptr; }

    //edge case: singleton linked list:
    if(head -> next == nullptr) { return head; }

    int list_size = 0;
    ListNode * it = head;
    while(it != nullptr) {
        ++list_size;
        it = it -> next;
    }

    it = head;
    for(int i = 1; i <= list_size / 2; i++) { it = it -> next; }
    return it;

}



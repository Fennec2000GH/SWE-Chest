

#include <vector>
using namespace std;

/* https://leetcode.com/problems/remove-linked-list-elements/ */
//Problem:
//Remove all elements from a linked list of integers that have value val.

//Level: Easy

// Results
/*
Runtime: 32 ms, faster than 79.94% of C++ online submissions for Remove Linked List Elements.
Memory Usage: 12.9 MB, less than 5.66% of C++ online submissions for Remove Linked List Elements.
*/
/*
 This version captures all values in order that do not match val using a vector. Then, the first N ListNodes are filled
 with the values in the vector, where N is the number of ListNodes without a matching val. No improvement from first
 version most likely due to too many edge cases.
 */

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeElements(ListNode* head, int val) {
    //edge case: empty linked list
    if(head == nullptr) { return nullptr; }

    vector<int> not_removed;
    ListNode * it = head;
    int list_size = 0;
    while(it != nullptr) {
        if(it -> val != val) { not_removed.push_back(it -> val); }
        it = it -> next;
        ++list_size;
    }

    //edge case: no matching val was found
    if(not_removed.size() == list_size) { return head; }

    //edge case: all ListNodes match val
    if(not_removed.empty()) { return nullptr; }

    it = head;
    for(int i : not_removed) {
        it -> val = i;
        it = it -> next;
    }

    //setting the tail
    ListNode * tail = head;
    for(int i = 0; i < not_removed.size() - 1; i++) { tail = tail -> next; }
    tail -> next = nullptr;

    ListNode * curr = it -> next;
    while(curr != nullptr) {
        it -> next = nullptr;
        delete it;
        it = curr;
        curr = curr -> next;
    }
    delete it;

    return head;
}










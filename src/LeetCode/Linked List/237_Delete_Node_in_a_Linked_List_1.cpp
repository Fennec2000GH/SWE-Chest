
#include <vector>
using namespace std;

/* https://leetcode.com/problems/delete-node-in-a-linked-list/ */
//Problem:
//Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

//Level: Easy

//Results
/*
Runtime: 16 ms, faster than 64.30% of C++ online submissions for Delete Node in a Linked List.
Memory Usage: 9.6 MB, less than 11.54% of C++ online submissions for Delete Node in a Linked List.
*/
/*
 Too much pointer re-assignments.
 */

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node) {
    //edge case: empty linked list
    if(node == nullptr) { return; }

    ListNode * new_tail = node;
    int node_val = node -> val; //original value at given node pointer
    int next_val;
    while(node -> next != nullptr) {
        next_val = node -> next -> val;
        node -> next -> val = node_val;
        node -> val = next_val;
        node = node -> next;
    }

    while(new_tail -> next != node) { new_tail = new_tail -> next; }
    delete new_tail -> next;
    new_tail -> next = nullptr;

}


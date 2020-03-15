
#include <vector>
using namespace std;

/* https://leetcode.com/problems/reverse-linked-list/ */
//Problem:
//Reverse a singly linked list.

//Level: Easy

//Results
/*
Runtime: 8 ms, faster than 94.78% of C++ online submissions for Reverse Linked List.
Memory Usage: 9.2 MB, less than 82.44% of C++ online submissions for Reverse Linked List.
 */

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//reverses the val in linked list without
ListNode* reverseList(ListNode* head) {
    //edge case: no list
    if(head == nullptr) return nullptr;

    //edge case: singleton
    if(head -> next == nullptr) return head;

    vector<ListNode*> v;
    ListNode* it = head;
    while(it != nullptr) {
        v.push_back(new ListNode(it -> val));
        it = it -> next;
    }

    for(int i = v.size() - 1; i >= 1; i--)
        v[i] -> next = v[i - 1];
    v[0] = nullptr;

    ListNode* output = v[v.size() - 1];
    return output;

}



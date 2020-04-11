
#include <iostream>
#include <vector>
using namespace std;

/* https://leetcode.com/problems/reverse-linked-list-ii/ */
//Problem:
/* Reverse a linked list from position m to n. Do it in one-pass. */

//Level: Medium

//Results:
/*
 Runtime: 4 ms, faster than 61.10% of C++ online submissions for Reverse Linked List II.
 Memory Usage: 6.7 MB, less than 100.00% of C++ online submissions for Reverse Linked List II.
 */

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//solution
ListNode* reverseBetween(ListNode* head, int m, int n) {
    //edge case: null head
    if(head == nullptr) { return nullptr; }

    //edge case: m is equal to n
    if(m == n) { return head; }

    vector<int> values;
    int pos = 1;
    ListNode *m_ptr = head;
    ListNode *n_ptr = nullptr;

    for(int i = 0; i < m - 1; i++) { m_ptr = m_ptr -> next; }
    n_ptr = m_ptr;
    for(int i = 0; i <= n - m; i++) {
        values.insert(v.begin(), n_ptr -> val);
        n_ptr = n_ptr -> next;
    }

    for(int &value : values) {
        m_ptr -> val = value;
        m_ptr = m_ptr -> next;
    }

    return head;
}



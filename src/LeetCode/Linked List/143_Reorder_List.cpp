
#include <iostream>
#include <vector>
using namespace std;

/* https://leetcode.com/problems/reorder-list/ */
//Problem:
/*
 Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.
 */

//Level: Medium

//Results:
/* Testcases all work, but submission has runtime error. */

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


void reorderList(ListNode* head) {
    //edge case: null head
    if(head == nullptr) { return; }

    //edge case: singleton linked list
    if(head -> next == nullptr) { return; }

    //edge case: only two (2) ListNodes
    if(head -> next -> next == nullptr) { return; }

    vector<ListNode*> v;
    ListNode *ptr = head;
    while(ptr != nullptr) {
        v.push_back(ptr);
        ptr = ptr -> next;
    }

    int v_size = v.size();
    for(int i = 0; i < v_size / 2; i++) {
        v[i] -> next = v[v_size - 1 - i];
        if(i + 1 < (double)v_size / 2) { v[v_size - 1 - i] -> next = v[i + 1]; }
        else { v[v_size - 1 - i] -> next = nullptr; }
    }
}

//testing
int main() {
    ListNode *head = new ListNode(10);
    ListNode *ptr = head;
    for(int i = 20; i <= 60; i += 10) {
        ptr -> next = new ListNode(i);
        ptr = ptr -> next;
    }
    ptr = head;
    cout << "Linked List: ";
    while(ptr != nullptr) {
        cout << ptr -> val << "\t";
        ptr = ptr -> next;
    }
    cout << endl;
    //linked list is now 10, 20, 30, ..., 60

    reorderList(head);
    cout << "After Reorder: ";
    ptr = head;
    cout << "Linked List: ";
    while(ptr != nullptr) {
        cout << ptr -> val << "\t";
        ptr = ptr -> next;
    }

    return 0;
}

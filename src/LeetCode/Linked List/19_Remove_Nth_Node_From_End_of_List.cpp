
#include <iostream>
using namespace std;

/* https://leetcode.com/problems/remove-nth-node-from-end-of-list/ */
//Problem:
//Given a linked list, remove the n-th node from the end of list and return its head.
//Note: Given n will always be valid.

//Level: Medium

//Results
/*
Runtime: 4 ms, faster than 94.15% of C++ online submissions for Remove Nth Node From End of List.
Memory Usage: 8 MB, less than 100.00% of C++ online submissions for Remove Nth Node From End of List.
*/
/*
 The code uses at most 2 pointers and no extra space, speeding up the process and giving a very high time efficiency.
 */

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    //edge case: linked list is empty
    if(head == nullptr) { return nullptr; }

    //edge case: singleton linked list
    if(head -> next == nullptr) {
        delete head;
        return nullptr;
    }

    int list_size = 0;
    ListNode * it = head;
    while(it != nullptr) {
        ++list_size;
        it = it -> next;
    }

    it = head;

    //in case head is to be deleted
    if(n == list_size) {
        head = head -> next;
        it -> next = nullptr;
        delete it;
        return head;
    }

    for(int i = 0; i < list_size - n - 1; i++) { it = it -> next; }

    //in case tail is to be deleted
    if(n == 1) {
        delete it -> next;
        it -> next = nullptr;
        return head;
    }

    ListNode * it2 = it -> next;
    it -> next = it2 -> next;
    it2 -> next = nullptr;
    delete it2;

    return head;
}

int main() {
    ListNode * head = new ListNode(1);
    ListNode * it = head;
    for(int i = 2; i <= 6; i++) {
        it -> next = new ListNode(i);
        it = it -> next;
    }

    cout << "initial linked list: ";
    it = head;
    while(it != nullptr) {
        cout << it -> val << ", ";
        it = it -> next;
    }
    cout << endl;

    removeNthFromEnd(head, 2);

    cout << "linked list after removing 2nd from last element: ";
    it = head;
    while(it != nullptr) {
        cout << it -> val << ", ";
        it = it -> next;
    }
    cout << endl;

    return 0;
}



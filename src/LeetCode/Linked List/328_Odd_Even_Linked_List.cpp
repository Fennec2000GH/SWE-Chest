#include <iostream>
using namespace std;

/* https://leetcode.com/problems/odd-even-linked-list/ */
//Problem:
/* Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking
 about the node number and not the value in the nodes. You should try to do it in place. The program should run in O(1)
 space complexity and O(nodes) time complexity.
 */


//Level: Medium

//Results:
/*
 Runtime: 16 ms, faster than 95.03% of C++ online submissions for Odd Even Linked List.
Memory Usage: 8.7 MB, less than 100.00% of C++ online submissions for Odd Even Linked List.
 */
/*
 The extreme efficiency in both time and space is due to a neat trick that does not use any extra memory and performs
 in linear time O(n). The best wat to describe it is like unzipping a zipper. There are two (2) head pointers, one for
 the first odd node and one for the first tail node. Similarly, there is a separate tail pointer for odd nodes and even
 nodes. The first odd (actual head) changes "next" to point to the next odd node by skipping the current node it is
 pointing to. Similarly, the first even node changes "next" to the next even node by skipping the current node it is
 pointing to. Each time, the tail pointer also moves forward once as long as the new "next" is not nullptr. This 2-step
 process repeats in succession until one of the tails points to the end of the whole list (nullptr). The tail of the
 odd sublist has its "next" point to the head of the even sublist. Finally, the odd head is returned.
 */

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//solution
ListNode* oddEvenList(ListNode* head) {
    //edge case: null head
    if(head == nullptr) { return nullptr; }

    //edge case: singletone linked list
    if(head -> next == nullptr) { return head; }

    ListNode *odd_head = head;
    ListNode *odd_tail = odd_head;
    ListNode *even_head = head -> next;
    ListNode *even_tail = even_head;
    while(true) {
        odd_tail -> next = odd_tail -> next -> next;
        if(odd_tail -> next != nullptr) { odd_tail = odd_tail -> next; }
        else { break; }
        even_tail -> next = even_tail -> next -> next;
        if(even_tail -> next != nullptr) { even_tail = even_tail -> next; }
        else { break; }
    }

    odd_tail -> next = even_head;
    return odd_head;
}
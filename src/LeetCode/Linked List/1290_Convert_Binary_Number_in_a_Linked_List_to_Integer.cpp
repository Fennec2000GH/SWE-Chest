
#include <vector>
using namespace std;

/* https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/ */
//Problem:
//Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0
// or 1. The linked list holds the binary representation of a number.
//Return the decimal value of the number in the linked list.

//Level: Easy

//Results
/*
 Runtime: 0 ms, faster than 100.00% of C++ online submissions for Convert Binary Number in a Linked List to Integer.
Memory Usage: 7.8 MB, less than 100.00% of C++ online submissions for Convert Binary Number in a Linked List to Integer.
 */
/*
 Extreme time and space efficiency was primarily due to not using any extra containers e.g. vectors and using O(n)
 to traverse and accumulate the output from binary to decimal. Linear time was possible due to reversing the direction
 each "next" pointer in each ListNode.
 */

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int getDecimalValue(ListNode* head) {
    //edge case: empty linked list
    if(head == nullptr) { return 0; }

    //edge case: singleton linked list
    if(head -> next == nullptr) { return head -> val; }

    //reversing directionality of linked list by reversing "next" pointers
    ListNode * a = head;
    ListNode * b = a -> next;
    ListNode * c = b -> next;
    a -> next = nullptr;
    while(b != nullptr) {
        b -> next = a;
        a = b;
        b = c;
        if(c != nullptr) { c = c -> next; }
    }

    int power = 0;
    int output = 0;
    while(a != nullptr) {
        if(a -> val == 1) { output += pow(2, power); }
        ++power;
        a = a -> next;
    }

    return output;
}





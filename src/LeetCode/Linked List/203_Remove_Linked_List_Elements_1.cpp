
using namespace std;

/* https://leetcode.com/problems/remove-linked-list-elements/ */
//Problem:
//Remove all elements from a linked list of integers that have value val.

//Level Easy

//Results
/*
Runtime: 32 ms, faster than 80.10% of C++ online submissions for Remove Linked List Elements.
Memory Usage: 12.2 MB, less than 5.66% of C++ online submissions for Remove Linked List Elements.
 */
/*
The time complexity is O(n), and actual time consumed is quite decent. However, memory efficiency is horribly low
because of managing so many pointers during deletion of a ListNode while inside a while loop. 
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

    //preliminary case: val occurs at the front once or more in sequence
    ListNode * prev = head;
    while(head -> val == val) {
        head = head -> next;
        prev -> next = nullptr;
        delete prev;
        prev = head;
    }

    //in case linked list is all used up since each element has mathcing val
    if(head == nullptr) { return nullptr; }

    //in case only 1 ListNode is left standing
    if(head -> next == nullptr) { return head; }

    ListNode * curr = head -> next;
    while(curr != nullptr) {
        if(curr -> val == val) {
            prev -> next = curr -> next;
            curr -> next = nullptr;
            delete curr;
            curr = prev -> next;
        } else {
            prev = curr;
            curr = curr -> next;
        }
    }

    return head;

}





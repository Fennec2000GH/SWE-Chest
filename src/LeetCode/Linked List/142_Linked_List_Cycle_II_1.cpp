
#include <algorithm>
#include <vector>
using namespace std;

/* https://leetcode.com/problems/linked-list-cycle-ii/ */
//Problem
//Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
//To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the
// linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.
//Note: Do not modify the linked list.

//Level: Medium

//Results
/*
Runtime: 120 ms, faster than 5.11% of C++ online submissions for Linked List Cycle II.
Memory Usage: 9.6 MB, less than 100.00% of C++ online submissions for Linked List Cycle II.
*/
/*
 O(n^2) time drags down time efficiency. On the bright side, memory efficiency is maximal by not using extra containers.
 */

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
    //edge case: empty linked list
    if(head == nullptr) { return nullptr; }

    //edge case: singleton linked list
    if(head -> next == nullptr) { return nullptr; }

    vector<ListNode*> v;
    ListNode * it = head;
    while(it != nullptr && none_of(v.cbegin(), v.cend(), [&it](ListNode * ptr){ return ptr == it; })) {
        v.push_back(it);
        it = it -> next;
    }

    return it;
}


#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/swap-nodes-in-pairs/

// Problem:
/* Given a linked list, swap every two adjacent nodes and return its head.
You may not modify the values in the list's nodes, only nodes itself may be changed. */

// Level: Medium

// Results:
/* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Swap Nodes in Pairs.
Memory Usage: 7.9 MB, less than 5.19% of C++ online submissions for Swap Nodes in Pairs. */
/* Use of vector became very speedy to handle swaps between adjacent pairs of nodes */

// node definition
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// solution
ListNode* swapPairs(ListNode* head) {
    // edge case
    if(head == nullptr) { return nullptr; }
    if(head -> next == nullptr) { return head; }

    vector<ListNode*> v;
    ListNode* it = head;
    while(it != nullptr) {
        v.push_back(it);
        it = it -> next;
    }

    for(unsigned index = 0; index < v.size() / 2; index++) {
        it = v[2 * index];
        v[2 * index] = v[2 * index + 1];
        v[2 * index + 1] = it;
    }

    for(unsigned index = 0; index < v.size() - 1; index++) { v[index] -> next = v[index + 1]; }
    v.back() -> next = nullptr;
    return v.front();
}

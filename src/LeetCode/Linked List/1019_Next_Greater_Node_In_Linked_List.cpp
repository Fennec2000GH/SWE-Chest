
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <unordered_map>
using namespace std;

/* https://leetcode.com/problems/next-greater-node-in-linked-list/ */

//Problem:
/*
We are given a linked list with head as the first node.  Let's number the nodes in the list: node_1, node_2, node_3,
 ... etc. Each node may have a next larger value: for node_i, next_larger(node_i) is the node_j.val such that j > i,
 node_j.val > node_i.val, and j is the smallest possible choice.  If such a j does not exist, the next larger value is
 0. Return an array of integers answer, where answer[i] = next_larger(node_{i+1}).
 */

//Level: Medium

//Results:
/* Time Limit Exceeded. (Because of O(n^2) time complexity) */

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

vector<int> nextLargerNodes(ListNode* head) {
    //edge case: null head
    if(head == nullptr) { return {}; }

    //edge case: singleton linked list
    if(head -> next == nullptr) { return {0}; }

    vector<int> answers;
    unordered_map<unsigned, int> unsolved; // (index, value)
    unsigned index = 0;

    //O(n^2) naive method of checking for greater nodes
    while(head != nullptr) {
        unordered_map<unsigned, int>::iterator it = unsolved.begin();
        while(it != unsolved.end()) {
            if(head -> val > it -> second) {
                answers[it -> first] = head -> val;
                it = unsolved.erase(it);
            }
        }
        unsolved.insert(pair<unsigned, int>(index, head -> val));
        head = head -> next;
    }

    //for the nodes such that greater node does not exist...
    for(pair<const unsigned, int> &p : unsolved) { answers[p.first] = 0; }

    return answers;
}






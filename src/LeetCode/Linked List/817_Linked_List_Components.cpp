
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/* https://leetcode.com/problems/linked-list-components/ */
//Problem:
/* We are given head, the head node of a linked list containing unique integer values. We are also given the list G, a
subset of the values in the linked list. Return the number of connected components in G, where two values are connected
if they appear consecutively in the linked list.
*/

//Level: Medium

//Results:
/* Runtime: 44 ms, faster than 69.68% of C++ online submissions for Linked List Components.
Memory Usage: 12.3 MB, less than 100.00% of C++ online submissions for Linked List Components.
*/
/*
 An unordered_set version of the components vector G is used to speed up lookup to O(1) time complexity. Iterating
 through the linked list, each ListNode val is checked to see if it is in the set. If it is in the set and the previous
 val was not, then a new component group has started, and a counter is incremented.
 */


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int numComponents(ListNode* head, vector<int>& G) {
    //edge case: null head
    if(head == nullptr) { return 0; }

    //edge case: G contains no elements
    if(G.empty()) { return 0; }

    unordered_set<int> G_set(G.cbegin(), G.cend());
    bool g = false; //true if current val is in vector G
    int components = 0;

    while (head != nullptr) {
        if(g == false && G_set.find(head -> val) != G_set.end()) {
            g = true;
            ++components;
        } else if (g == true && G_set.find(head -> val) == G_set.end()) {
            g = false;
        }
        head = head -> next;
    }

    return components;

}

//testing
int main() {
    ListNode *head = new ListNode(10);
    ListNode *ptr = head;
    for(int i = 20; i <= 120; i += 10) {
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

    //linked list is now 10, 20, 30, ..., 120
    vector<int> v = {10, 30, 40, 60, 100, 110, 120};
    int answer = numComponents(head, v);
    cout << answer << endl;
    return 0;
}






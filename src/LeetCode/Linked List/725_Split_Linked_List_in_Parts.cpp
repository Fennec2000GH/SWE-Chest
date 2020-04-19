
/* https://leetcode.com/problems/split-linked-list-in-parts/ */
//Problem:
/*
Given a (singly) linked list with head node root, write a function to split the linked list into k consecutive linked
list "parts". The length of each part should be as equal as possible: no two parts should have a size differing by more
than 1. This may lead to some parts being null. The parts should be in order of occurrence in the input list, and parts
occurring earlier should always have a size greater than or equal parts occurring later. Return a List of ListNode's
representing the linked list parts that are formed.
*/



//Level: Medium

//Results:
/* Untested - return type given is problem is bull*/


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//solution
int size(ListNode* root) {
    int output = 0;
    ListNode* root_copy = root;
    while(rootcopy != nullptr) {
        ++output;
        root_copy = root_copy -> next;
    }
    return output;
}

vector<vector<ListNode*>> splitListToParts(ListNode* root, int k) {
    vector<vector<ListNode*>> v;
    int size = size(root);
    int counter = 0;

    //edge case: empty vector
    if(size == 0) { return v; }

    ListNode* root_copy = root;
    //edge case: k >= size
    if(k >= size) {
        while(root_copy != nullptr) {
            v.push_back({root_copy});
            root_copy = root_copy -> next;
            ++counter;
        }
        while(counter < k) {
            v.push_back(nullptr);
            root_copy = root_copy -> next;
            ++counter;
        }
        return v;
    }

    //rem is remainder of size / k
    //part_size is the minimal size of any part
    int rem = size % k, part_size = size / k;
    for(int i = 0; i < k; i++) {
        vector<ListNode*> part;
        for(int j = 0; j < part_size + (i < rem ? 1 : 0); j++) {
            part.push_back(root_copy);
            root_copy = root_copy -> next;
        }
        v.push_back(part);
    }

    return v;
}






/* https://leetcode.com/problems/linked-list-in-binary-tree/ */
//Modified version of original problem 1367 where binary tree is specifically a binary search tree.
//Problem:
/*
Given a binary tree root and a linked list with head as the first node. Return True if all the elements in the linked
list starting from the head correspond to some downward path connected in the binary tree otherwise return False. In
this context downward path means a path that starts at some node and goes downwards.
*/

//Level:

//Results:

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//searches for node with val in binary search tree
TreeNode* search(TreeNode* root, int value) {
    while(root -> val != value && root != nullptr) {
        if(value < root -> val) { root = root -> left; }
        else { root = root -> right; }
    }

    if(root == nullptr) { return nullptr; }
    return root;
}

//solution
bool isSubPath(ListNode* head, TreeNode* root) {
    //edge case: nullptr linked list
    if(head == nullptr) { return true; }

    //edge case: non-null linked list but empty tree
    if(root == nullptr) { return false; }

    TreeNode* start = search(root, head -> val);
    while(head -> next != nullptr) {
        if(start == nullptr) { return false; }
        if(head -> val != start -> val) { return false; }
        if(head -> next -> val < head -> val) { start = start -> left; }
        else { start = start -> right; }
        head = head -> next;
    }

    if(start == nullptr) { return false; }
    if(head -> val != start -> val) { return false; }
    return true;
}

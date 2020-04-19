

/* https://leetcode.com/problems/linked-list-in-binary-tree/ */
//Problem:
/*
Given a binary tree root and a linked list with head as the first node. Return True if all the elements in the linked
list starting from the head correspond to some downward path connected in the binary tree otherwise return False. In
this context downward path means a path that starts at some node and goes downwards.
*/

//Level: Medium

//Results:
/*
Runtime: 44 ms, faster than 28.24% of C++ online submissions for Linked List in Binary Tree.
Memory Usage: 22.2 MB, less than 100.00% of C++ online submissions for Linked List in Binary Tree.
*/
/*
Time complexity is O(m*2^n) = O(2^n), where m is the size of linked list, and n is the size of binary tree. While traversing binary
tree, a helper function is called if the TreeNode and head of linked list points to the same value val. The helper
function trickles down both the binary tree and linked list to confirm any matching downward paths. At each split in
binary tree, the helper function must be recursively called on both children, if exists, since the tree is not a BST, so
a path going down through either child may contain a matching path. Space complexity O(1) is optimal as no containers
need to be instantiated anywhere in the program.
*/

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

//whether linked list stating at head is also rooted in binary tree at root
bool rootedSubPath(ListNode* head, TreeNode* root) {
    //edge case: nullptr linked list
    if(head == nullptr) { return true; }

    //edge case: non-null linked list but empty tree
    if(root == nullptr) { return false; }

    if(head -> val != root -> val) { return false; }

    return rootedSubPath(head -> next, root -> left) || rootedSubPath(head -> next, root -> right);
}

//helper function traverses a binary tree rooted at root while checking for sub-path
//does not traverse tree if linked list is nullptr
bool traversal(ListNode* head, TreeNode* root) {
    //edge case: empty tree
    if(root == nullptr) { return false; }

    //check for containment of sub-path
    if(head -> val == root -> val) { if(rootedSubPath(head, root)) { return true; } }

    //traversing
    return traversal(head, root -> left) || traversal(head, root -> right);
    return false;
}

//solution
bool isSubPath(ListNode* head, TreeNode* root) {
    //edge case: nullptr linked list
    if(head == nullptr) { return true; }

    //edge case: non-null linked list but empty tree
    if(root == nullptr) { return false; }

    return traversal(head, root);
}

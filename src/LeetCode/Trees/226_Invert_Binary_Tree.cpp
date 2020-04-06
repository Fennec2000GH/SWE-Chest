
/* https://leetcode.com/problems/invert-binary-tree/ */

//Problem:
/* Invert a binary tree. */

//Level: Easy

//Results:
/*
Runtime: 8 ms, faster than 51.24% of C++ online submissions for Invert Binary Tree.
Memory Usage: 8 MB, less than 100.00% of C++ online submissions for Invert Binary Tree.
*/
/*
Time efficiency is about average. The time complexity is O(n), but using pointers in function recursion burned up some
 time. On the other hand, memory usage is extremely efficient as no extra space, whether containers or new TreeNodes,
 need to be created during program execution.
*/


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//helper functions
//swaps two (2) existing nodes
void swap(TreeNode *&t1, TreeNode *&t2) {
    //edge case: one or both nodes are null
    if(t1 == nullptr || t2 == nullptr) { return; }
    int temp = t1 -> val;
    t1 -> val = t2 -> val;
    t2 -> val = temp;
}

//does the inverting
void invert(TreeNode *&t1, TreeNode *&t2) {
    //edge case: both are null
    if(t1 == nullptr && t2 == nullptr) { return; }

    if(t1 == nullptr) {
        t1 = t2;
        t2 = nullptr;
        invert(t1 -> left, t1 -> right);
    } else if(t2 == nullptr) {
        t2 = t1;
        t1 = nullptr;
        invert(t2 -> left, t2 -> right);
    } else {
        swap(t1, t2);
        invert(t1 -> left, t2 -> right);
        invert(t1 -> right, t2 -> left);
    }

}


//solution
TreeNode* invertTree(TreeNode* root) {
    //edge case: null root
    if(root == nullptr) { return nullptr; }

    //edge case: singleton binary tree
    if(root -> left == nullptr && root -> right == nullptr) { return root; }

    if(root -> left == nullptr) {
        root -> left = root -> right;
        root -> right = nullptr;
        invertTree(root -> left);
    } else if(root -> right == nullptr) {
        root -> right = root -> left;
        root -> left = nullptr;
        invertTree(root -> right);
    } else { invert(root -> left, root -> right); }
    return root;
}


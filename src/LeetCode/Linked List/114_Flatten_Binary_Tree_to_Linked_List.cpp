
#include <iostream>
#include <stack>
using namespace std;

/* https://leetcode.com/problems/flatten-binary-tree-to-linked-list/ */
//Problem:
/* Given a binary tree, flatten it to a linked list in-place. */


//Level: Medium


//Results:
/*
limited test cases passed due to compiler error
 */

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//convert a O(n) time binary tree such that each left child is nullptr and each right child (except for leaf) is not
void righten(TreeNode* root) {
    //edge case: empty tree
    if(root == nullptr) { return; }

    while(root != nullptr) {
        if (root->left != nullptr) {
            root -> right = root -> left;
            root -> left = nullptr;
        }
        root = root -> right;
    }
}

void flatten(TreeNode* root) {
    //edge case: empty tree
    if(root == nullptr) { return; }
    TreeNode* ptr = root;

    //marks splits in binary tree
    stack<TreeNode*> st;
    if(ptr -> left != nullptr && ptr -> right != nullptr) {
        st.push(ptr);
        ptr = ptr -> left;
    } else {
        while(ptr -> left == nullptr || ptr -> right == nullptr) {
            if(ptr -> left != nullptr) { ptr = ptr -> left; }
            else { ptr = ptr -> right; } //might point to nullptr
        }

        //both children exist
        if(ptr != nullptr) {
            st.push(ptr);
            ptr = ptr->left;
        } else {
            righten(root);
            return;
        }
    }

    //flattening
    while(!st.empty() || ptr -> left != nullptr || ptr -> right != nullptr) {
        if(ptr -> left != nullptr && ptr -> right != nullptr) { st.push(ptr); }
        if(ptr -> left != nullptr) {
            ptr = ptr -> left;
            continue;
        } else if (ptr -> right != nullptr) {
            ptr = ptr -> right;
            continue;
        }
        TreeNode * top = st.top();
        st.pop();
        ptr->right = top->right;
        ptr = ptr -> right;
        top->right = nullptr;
    }

    righten(root);
}

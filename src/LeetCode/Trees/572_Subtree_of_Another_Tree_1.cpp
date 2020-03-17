
#include <iostream>
using namespace std;

/* https://leetcode.com/problems/subtree-of-another-tree/ */
//Problem:
/*
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a
subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could
also be considered as a subtree of itself.
*/

//Level: Easy

//Results:
/*
 Time Limit Exceeded
 */

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//helper function
bool sameTree(TreeNode* root1, TreeNode* root2) {
    //edge cases: nullptr
    if(root1 == nullptr && root2 == nullptr) { return true; }
    if(root1 == nullptr && root2 != nullptr) { return false; }
    if(root1 != nullptr && root2 == nullptr) { return false; }

    if(root1 -> val != root2 -> val) { return false; }

    return sameTree(root1 -> left, root2 -> left) && sameTree(root1 -> right, root2 -> right);

}

bool isSubtree(TreeNode* s, TreeNode* t) {
    TreeNode* t_ptr = s;
    while(t -> val != s -> val && t_ptr != nullptr) {
        if(t -> val < s -> val) { t_ptr = s -> left; }
        else { t_ptr = s -> right; }
    }

    //in case root of t is not even found in s
    if(t_ptr == nullptr) { return false; }

    return sameTree(t_ptr, t);

}

int main() {




    return 0;
}
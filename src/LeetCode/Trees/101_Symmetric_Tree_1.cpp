
#include <iostream>
using namespace std;

/* https://leetcode.com/problems/symmetric-tree/ */
//Problem:
//Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

//Level: Easy

//Results:
/*
Runtime: 4 ms, faster than 83.76% of C++ online submissions for Symmetric Tree.
Memory Usage: 14.2 MB, less than 100.00% of C++ online submissions for Symmetric Tree.
*/
/*
 Uses recursive method of comparing the opposite child of each pair of mirrored TreeNodes. The For any two (2)
 TreeNodes mirror opposite each other across the line of symmetry, a helper function that tests val equality is
 passed on the left child of the first node and the right child of the second node. The helper function is also
 called on the right child of the first node and the left child of the second node.
 */


//Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


//helper function
bool isSymmetricNode(TreeNode* node1, TreeNode* node2) {
    //edge case: nullptr
    if(node1 == nullptr && node2 == nullptr) { return true; }

    //comparing immediate values
    if(node1 -> val != node2 -> val) { return false; }

    if(node1 -> left == nullptr && node2 -> right != nullptr) { return false; }
    if(node1 -> left != nullptr && node2 -> right == nullptr) { return false; }
    if(node1 -> right == nullptr && node2 -> left != nullptr) { return false; }
    if(node1 -> right != nullptr && node2 -> left == nullptr) { return false; }

    return isSymmetricNode(node1 -> left, node2 -> right) && isSymmetricNode(node1 -> right, node2 -> left);
}

//solution
bool isSymmetric(TreeNode* root) { return isSymmetricNode(root, root); }


int main () {
    TreeNode * p1 = nullptr;
    TreeNode * p2 = nullptr;
    cout << boolalpha << (p1 == p2) << endl;

    return 0;
}

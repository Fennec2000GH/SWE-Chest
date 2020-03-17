
#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>
using namespace std;

/* https://leetcode.com/problems/binary-tree-tilt/ */
//Problem:
/*
Given a binary tree, return the tilt of the whole tree.
The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the
sum of all right subtree node values. Null node has tilt 0. The tilt of the whole tree is defined as the sum of all
nodes' tilt
*/

//Level: Easy

//Results:
/*
 FAILED.
 */


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// O(n)
void inorder(TreeNode* node, vector<int> &v) {
    //edge case: nullptr
    if(node == nullptr) { return; }

    if(node -> left != nullptr) { inorder(node -> left, v); }
    v.push_back(node -> val);
    if(node -> right != nullptr) { inorder(node -> right, v); }

}

//find tilt at specific root of subtree only
// O(n + log n)
int findTiltNode(TreeNode* node, vector<int> &inorder) {
    //edge case: nullptr
    if(node == nullptr) { return 0; }

    //edge case: singleton node
    if(node -> left == nullptr && node -> right == nullptr) { return 0; }

    int node_val = node -> val;
    vector<int>::const_iterator node_it = find(inorder.cbegin(), inorder.cend(), node_val); // O(n)
    int left_sum = accumulate(inorder.cbegin(), node_it, 0); // O(n)
    TreeNode* rightmost_leaf = node;
    while(rightmost_leaf -> right != nullptr) { rightmost_leaf = rightmost_leaf -> right; } // O(log n)
    int right_sum = accumulate(next(node_it), next(find(inorder.cbegin(), inorder.cend(), rightmost_leaf -> val)), 0); // O(n)
    return abs(right_sum - left_sum); // O(1)

}

//O(n^2 + n log n)
int findTilt(TreeNode* root) {
    vector<int> inorder_traversal;
    inorder(root, inorder_traversal); // O(n)

    vector<int> tilts;
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* top;
    while(!q.empty()) {
        top = q.front();
        q.pop();
        tilts.push_back(findTiltNode(top, inorder_traversal));
        if(top -> left != nullptr) { q.push(top -> left); }
        if(top -> right != nullptr) { q.push(top -> right); }
    }

    return accumulate(tilts.cbegin(), tilts.cend(), 0);
}


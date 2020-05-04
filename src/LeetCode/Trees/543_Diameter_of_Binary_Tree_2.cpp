
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

/* https://leetcode.com/problems/diameter-of-binary-tree/ */

//Problem:
/*
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the
length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
*/

//Level: Easy

//Results:
/*
 Runtime: 20 ms, faster than 28.52% of C++ online submissions for Diameter of Binary Tree.
Memory Usage: 21.1 MB, less than 11.11% of C++ online submissions for Diameter of Binary Tree.
 */
/*
 Poor time and space complexity most likely due to the use of pair objects in a recursive function, therefore consuming
 noticeable amounts of time and memory during execution.
 */

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//auxiliary function sums heights or left and right sub-trees and the height as a pair
//output is the output of diameterOfBinaryTree function i.e. largest pseudodiameter across all TreeNodes
pair<unsigned, unsigned> getPseudoDiameter(TreeNode* root, int &output) {
    //edge case: empty tree
    if(root == nullptr) { return pair<unsigned, unsigned>(0, 0); }

    auto leftPair = getPseudoDiameter(root -> left, output);
    auto rightPair = getPseudoDiameter(root -> right, output);
    unsigned pseudodiameter = (root -> left == nullptr ? 0 : 1 + leftPair.second) + (root -> right == nullptr ? 0 : 1 + rightPair.second);
    unsigned height = (root -> left != nullptr || root -> right != nullptr ? 1 + max(leftPair.second, rightPair.second) : 0);
    if(pseudodiameter > output) { output = pseudodiameter; }
    return pair<unsigned, unsigned>(pseudodiameter, height);
}

int diameterOfBinaryTree(TreeNode* root) {
    int output = 0;
    getPseudoDiameter(root, output);
    return output;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> left -> left = new TreeNode(4);
    root -> left -> right = new TreeNode(5);
    root -> right = new TreeNode(3);

    int output = 0;
    getPseudoDiameter(root, output);
    cout << output << endl;
    output = 0;
    getPseudoDiameter(root -> left, output);
    cout << output << endl;
    output = 0;
    getPseudoDiameter(root -> left -> left, output);
    cout << output << endl;
    output = 0;
    getPseudoDiameter(root -> left -> right, output);
    cout << output << endl;
    output = 0;
    getPseudoDiameter(root -> right, output);
    cout << output << endl;

    return 0;
}


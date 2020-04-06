
#include <iostream>
using namespace std;

/* https://leetcode.com/problems/merge-two-binary-trees/ */
//Problem:
/*
Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are
overlapped while the others are not. You need to merge them into a new binary tree. The merge rule is that if two nodes
overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the
node of new tree.
*/

//Level: Easy

//Results:
/*
Runtime: 128 ms, faster than 6.71% of C++ online submissions for Merge Two Binary Trees.
Memory Usage: 23.8 MB, less than 8.33% of C++ online submissions for Merge Two Binary Trees.
*/

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//builds the merged binary tree
void mergeTreesHelper(TreeNode* t1, TreeNode* t2, TreeNode* &merged) {
    //edge case: both nodes are null
    if(t1 == nullptr && t2 == nullptr) { merged = nullptr; return; }

    merged = new TreeNode((t1 == nullptr ? 0 : t1 -> val) + (t2 == nullptr ? 0 : t2 -> val));

    mergeTreesHelper(t1 == nullptr ? nullptr : t1 -> left, t2 == nullptr ? nullptr : t2 -> left, merged -> left);
    mergeTreesHelper(t1 == nullptr ? nullptr : t1 -> right, t2 == nullptr ? nullptr : t2 -> right, merged -> right);
}

//solution
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    TreeNode* output;
    mergedTreesHelper(t1, t2, output);
    return output;
}

int main() {
    TreeNode* t1 = new TreeNode(2);
    t1 -> left = new TreeNode(1);
    t1 -> right = new TreeNode(3);

    TreeNode* t2 = new TreeNode(20);
    t2 -> left = new TreeNode(10);
    t2 -> right = new TreeNode(30);

    TreeNode* output;
    mergeTrees(t1, t2, output);

    return 0;
}

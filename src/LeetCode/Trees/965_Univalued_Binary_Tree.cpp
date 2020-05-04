
#include <iostream>
#include <queue>
using namespace std;

/* https://leetcode.com/problems/univalued-binary-tree/ */
//Problem:
/*
A binary tree is univalued if every node in the tree has the same value. Return true if and only if the given tree
is univalued.
*/

//Level: Easy

//Results:
/*
 Runtime: 4 ms, faster than 43.09% of C++ online submissions for Univalued Binary Tree.
Memory Usage: 10.3 MB, less than 100.00% of C++ online submissions for Univalued Binary Tree.
 */
/*
 Breadth-First Search O(n)is used to compare each TreeNode's val to the initial value from root node. Any difference
 would return false. Space complexity is optimized by avoiding recursion with a queue.
 */

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isUnivalTree(TreeNode* root) {
    //edge case: empty tree
    if(root == nullptr) { return true; }

    //BFS on binary tree
    queue<TreeNode*> q;
    q.push(root);

    //expected universal value for all TreeNode instances
    int unival = root -> val;
    TreeNode* top;
    while(!q.empty()) {
        top = q.front();
        q.pop();

        //checking for value consistency
        if(top -> val != unival) { return false; }

        if(top -> left != nullptr) { q.push(top -> left); }
        if(top -> right != nullptr) { q.push(top -> right); }
    }

    return true;
}

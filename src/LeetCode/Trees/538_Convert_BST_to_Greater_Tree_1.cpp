
#include <iostream>
#include <iterator>
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;

/* https://leetcode.com/problems/convert-bst-to-greater-tree/ */
//Problem:
//Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to
//the original key plus sum of all keys greater than the original key in BST.

//Level: Easy

//Results:
/*
Runtime: 84 ms, faster than 8.23% of C++ online submissions for Convert BST to Greater Tree.
Memory Usage: 33.9 MB, less than 14.29% of C++ online submissions for Convert BST to Greater Tree.
*/
/*
Inorder traversal of the BST, creating the conversion map, and building the new greater tree each took O(n)
 time complexity. However, the overall time used is slow due to building an entirely new tree, which is not
 necessary. Changing the values in the BST by traversing right-to-left as cumulativ sums to the rightmost leaf
 does not waste memory.
 */

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder(TreeNode * node, vector<int> &v) {
    //edge case: empty node
    if(node == nullptr) { return; }

    if(node -> left != nullptr) { inorder(node -> left, v); }
    v.push_back(node -> val);
    if(node -> right != nullptr) { inorder(node -> right, v); }

}

//helper function
void createGreaterNode(TreeNode* bstNode, TreeNode* greaterNode, unordered_map<int, int> &m) {
    //error: map does not contain val in bstNode
    if(m.count(bstNode -> val) == 0) { throw out_of_range("BST val not found!"); }

    greaterNode -> val = m[bstNode -> val];
    if(bstNode -> left != nullptr) {
        greaterNode -> left = new TreeNode(0);
        createGreaterNode(bstNode -> left, greaterNode -> left, m);
    }
    if(bstNode -> right != nullptr) {
        greaterNode -> right = new TreeNode(0);
        createGreaterNode(bstNode -> right, greaterNode -> right, m);
    }

}

TreeNode* convertBST(TreeNode* root) {
    //edge case: empty bst
    if(root == nullptr) { return nullptr; }

    //edge case: singleton root
    if(root -> left == nullptr && root -> right == nullptr) { return root; }

    vector<int> inorder_traversal;
    inorder(root, inorder_traversal);

    cout << "inorder_traversal: { ";
    copy(inorder_traversal.cbegin(), inorder_traversal.cend(), ostream_iterator<int>(cout, ", "));
    cout << "} " << endl;

    //creating unsorted map that contains conversions from bst val to greater tree val
    reverse(inorder_traversal.begin(), inorder_traversal.end());
    int total_sum = 0;
    unordered_map<int, int> m;
    for(int bst_val : inorder_traversal) {
        total_sum += bst_val;
        m.insert_or_assign(bst_val, total_sum);
    }

    cout << "m: { ";
    for(pair<const int, int> &kv : m){ cout << "(" << kv.first << ", " << kv.second << "), "; }
    cout << "} " << endl;

    TreeNode* output = new TreeNode(0);
    createGreaterNode(root, output, m);

    return output;

}

int main() {
    //creating BST
    vector<int> bst = {4, 2, 6, 1, 3, 5, 7};

    cout << "bst: { ";
    copy(bst.cbegin(), bst.cend(), ostream_iterator<int>(cout, ", "));
    cout << "} " << endl;

    TreeNode* root = new TreeNode(bst.front());
    root -> left = new TreeNode(bst[1]);
    root -> left -> left = new TreeNode(bst[3]);
    root -> left -> right = new TreeNode(bst[4]);
    root -> right = new TreeNode(bst[2]);
    root -> right -> left = new TreeNode(bst[5]);
    root -> right -> right = new TreeNode(bst[6]);

    TreeNode* output = convertBST(root);

    return 0;
}

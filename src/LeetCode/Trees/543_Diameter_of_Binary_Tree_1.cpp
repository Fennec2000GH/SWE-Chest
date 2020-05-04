
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
 Runtime error
 */

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//auxilary function for binary tree height
int getHeight(TreeNode* root) {
    //edge case: empty tree or sub-tree
    if(root == nullptr) { return 0; }

    //edge case: singleton root
    if(root -> left == nullptr && root -> right == nullptr) { return 0; }

    return 1 + max(getHeight(root -> left), getHeight(root -> right));
}

//auxiliary function sums heights or left and right sub-trees
int getPseudoDiameter(TreeNode* root) {
    //edge case: empty tree
    if(root == nullptr) { return 0; }

    unsigned leftHeight = getHeight(root -> left);
    unsigned rightHeight = getHeight(root -> right);
    unsigned sum = (root -> left == nullptr ? 0 : 1 + leftHeight) + (root -> right == nullptr ? 0 : 1 + rightHeight);
    return (int) sum;
}

//auxiliary function for inorder traversal
void inorder_traverse(TreeNode* root, vector<TreeNode*> &v) {
    //edge case: empty tree
    if(root == nullptr) { return; }

    inorder_traverse(root -> left, v);
    v.push_back(root);
    inorder_traverse(root -> right, v);
}

int diameterOfBinaryTree(TreeNode* root) {
    vector<TreeNode*> v; //vector of all TreeNode (pointers)
    inorder_traverse(root, v);

    //delete
    cout << "v: {";
    for_each(v.cbegin(), v.cend(), [&] (TreeNode *tn) { cout << tn -> val << ", "; } );
    cout << "}" << endl;

    vector<int> diameters; //diameter of each sub-tree
    for_each(v.cbegin(), v.cend(), [&] (TreeNode *tn) { diameters.push_back(getPseudoDiameter(tn)); } );

    //delete
    cout << "diameters: {";
    copy(diameters.cbegin(), diameters.cend(), ostream_iterator<int>(cout, ", "));
    cout << "}" << endl;

    return *max_element(diameters.cbegin(), diameters.cend());
}

int main() {
    TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> left -> left = new TreeNode(4);
    root -> left -> right = new TreeNode(5);
    root -> right = new TreeNode(3);

    cout << getPseudoDiameter(root) << endl;
    cout << getPseudoDiameter(root -> left) << endl;
    cout << getPseudoDiameter(root -> left -> left) << endl;
    cout << getPseudoDiameter(root -> left -> right) << endl;
    cout << getPseudoDiameter(root -> right) << endl;

    cout << "Diameter: " << diameterOfBinaryTree(root) << endl;

    return 0;
}

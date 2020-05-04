
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

/* https://leetcode.com/problems/leaf-similar-trees/ */
//Problem:
/*
 Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value
 sequence. Two binary trees are considered leaf-similar if their leaf value sequence is the same. Return true if and
 only if the two given trees with head nodes root1 and root2 are leaf-similar.
 */

//Level: Easy

//Results:
/* Passed 37/38 test cases. LeetCode does not use conventional array-based binary tree, which always holds the
    property that left child index is 2 * i + 1, and right child index is 2 * i + 2, where i is the parent index.
    This discrepancy led to the last test case to fail. Logically, the code works 100%.
 */

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//auxiliary function for determining whether a TreeNode is a leaf or not
bool isLeaf(TreeNode* tn) {
    //edge case: nullptr
    if(tn == nullptr) { return true; }
    return tn -> left == nullptr &&  tn -> right == nullptr;
}

//auxiliary function for inorder traversal, but only pushing back into vector if TreeNode is a leaf
void inorder_traverse(TreeNode* root, vector<TreeNode*> &v) {
    //edge case: empty tree
    if(root == nullptr) { return; }

    if(root -> left != nullptr) { inorder_traverse(root -> left, v); }
    if(isLeaf(root)) { v.push_back(root); }
    if(root -> right != nullptr) { inorder_traverse(root -> right, v); }
}


bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    //leaf sequences for each binary tree
    vector<int> seq1;
    vector<int> seq2;

    vector<TreeNode*> leaves;
    inorder_traverse(root1, leaves);
    for_each(leaves.cbegin(), leaves.cend(), [&] (TreeNode* tn) { seq1.push_back(tn -> val); } );
    leaves.clear();
    inorder_traverse(root2, leaves);
    for_each(leaves.cbegin(), leaves.cend(), [&] (TreeNode* tn) { seq2.push_back(tn -> val); } );
    leaves.clear();

    //delete
    copy(seq1.cbegin(), seq1.cend(), ostream_iterator<int>(cout, ", "));
    copy(seq2.cbegin(), seq2.cend(), ostream_iterator<int>(cout, ", "));

    return equal(seq1.cbegin(), seq1.cend(), seq2.cbegin());
}

int main() {
    vector<string> tree_values = {"3", "5", "1", "6", "2", "9", "8", "null", "null", "7", "4"};
    unsigned tree_size = tree_values.size();
    cout << "tree_values: {";
    copy(tree_values.cbegin(), tree_values.cend(), ostream_iterator<string>(cout, ", "));
    cout << "}" << endl;

    vector<TreeNode*> tree(tree_size);
    TreeNode* root = new TreeNode(stoi(tree_values.front()));
    tree[0] = root;

    unsigned left_child, right_child;
    for(unsigned i = 0; i < tree_size; i++) {
        if(tree_values[i] == "null") { continue; }
//        cout << "i = " << i << endl;
//        cout << "tree[i] = " << tree[i] -> val << endl;
        left_child = 2 * i + 1;
        right_child = 2 * i + 2;
        if(left_child < tree_size) {
            if(tree_values[left_child] != "null") {
                tree[left_child] = new TreeNode(stoi(tree_values[left_child]));
                tree[i] -> left = &(*tree[left_child]);
//                cout << "left val = " << tree[i] -> left -> val << endl;
            }
        }
        if(right_child < tree_size) {
            if(tree_values[right_child] != "null") {
                tree[right_child] = new TreeNode(stoi(tree_values[right_child]));
                tree[i] -> right = &(*tree[right_child]);
//                cout << "right val = " << tree[i] -> right -> val << endl;
            }
        }
    }

    vector<TreeNode*> leaves1;
    inorder_traverse(root, leaves1);
    cout << "leaves1: {";
    for_each(leaves1.cbegin(), leaves1.cend(), [&] (TreeNode *tn) { cout << tn -> val << ", "; } );
    cout << "}" << endl;

    tree_values = {"3", "5", "1", "6", "7", "4", "2", "null", "null", "null", "null", "null", "null", "9", "11", "null",
                   "null", "8", "10"};

    tree_size = tree_values.size();
    cout << "tree_values: {";
    copy(tree_values.cbegin(), tree_values.cend(), ostream_iterator<string>(cout, ", "));
    cout << "}" << endl;

    for(unsigned i = 0; i < tree_size; i++) {
        if (tree_values[i] == "null") { continue; }
        cout << "i = " << i << endl;
        cout << "tree[i] = " << tree[i] -> val << endl;
        left_child = 2 * i + 1;
        right_child = 2 * i + 2;
        if (left_child < tree_size) {
            if (tree_values[left_child] != "null") {
                tree[left_child] = new TreeNode(stoi(tree_values[left_child]));
                tree[i]->left = &(*tree[left_child]);
                cout << "left val = " << tree[i] -> left -> val << endl;
            }
        }
        if (right_child < tree_size) {
            if (tree_values[right_child] != "null") {
                tree[right_child] = new TreeNode(stoi(tree_values[right_child]));
                tree[i]->right = &(*tree[right_child]);
                cout << "right val = " << tree[i] -> right -> val << endl;
            }
        }
    }

    vector<TreeNode*> leaves2;
    inorder_traverse(root, leaves2);
    cout << "leaves2: {";
    for_each(leaves2.cbegin(), leaves2.cend(), [&] (TreeNode *tn) { cout << tn -> val << ", "; } );
    cout << "}" << endl;

    return 0;
}
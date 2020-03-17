
#include <algorithm>
#include <limits>
#include <queue>
#include <vector>
using namespace std;

/* https://leetcode.com/problems/symmetric-tree/ */
//Problem:
//Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

//Level: Easy

//Results:
/*
 All custom test cases and edge cases passed individually, but total runtime exceeded Time Limit.
 */

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSymmetric(TreeNode* root) {
    //edge case: empty tree
    if(root == nullptr) { return true; }

    //edge case: singleton TreeNode
    if(root -> left == nullptr && root -> right == nullptr) { return true; }

    //vectors holds all values for each level in tree; nullptr is numeric_limits<int>::min()
    //v1 holds first half of level, v2 holds second half of level
    vector<int> v1;
    vector<int> v2;
    int level_size = 2; //number of nodes that can fit in current level (root is level 1)
    int fill_counter = 0; //number of nodes pushed back in any vector for the current level

    queue<TreeNode*> q;
    q.push(root -> left);
    q.push(root -> right);
    q.push(new TreeNode(numeric_limits<int>::min());
    TreeNode * top;
    while(!q.empty()) {
        top = q.front();
        q.pop();
        if(top == nullptr || top -> val != numeric_limits<int>::min()) {
            q.push(top == nullptr ? nullptr : top -> left);
            q.push(top == nullptr ? nullptr : top -> right);
            if(fill_counter < level_size / 2) { v1.push_back(top == nullptr ? numeric_limits<int>::min() : top -> val); }
            else { v2.push_back(top == nullptr ? numeric_limits<int>::min() : top -> val); }
            ++fill_counter;
            continue;
        }

        //checking if entire level is all nullptr (0)
        if(all_of(v1.cbegin(), v1.cend(), [](int i){ return i == 0; })
            && all_of(v2.cbegin(), v2.cend(), [](int i){ return i == 0; })
        ) { break; }

        //checking for symmetry in current level of TreeNodes
        reverse(v2.begin(), v2.end());
        if(!equal(v1.cbegin(), v1.cend(), v2.cbegin())) { return false; }

        //cleanup for next level of TreeNodes
        v1.clear();
        v2.clear();
        level_size *= 2;
        fill_counter = 0;
        q.push(new TreeNode(numeric_limits<int>::min()));

    }

    return true;

}


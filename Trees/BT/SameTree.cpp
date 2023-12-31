/*
    Given the roots of two binary trees p and q, write a function to check if they are the same or not.
    Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

    Example 1:
    Input: p = [1,2,3], q = [1,2,3]
    Output: true
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
    bool checkNode(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)
            return true;
        
        if( (p==NULL && q!=NULL) || (p!=NULL && q==NULL) )
            return false;

        bool leftTree = checkNode(p->left, q->left);
        bool rightTree = checkNode(p->right, q->right);

        bool val = p->val == q->val;

        if(leftTree && rightTree && val)
            return true;
        else 
            return false;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return checkNode(p,q);
    }
};
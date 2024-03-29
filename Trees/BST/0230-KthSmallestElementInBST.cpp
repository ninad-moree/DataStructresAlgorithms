/*
    Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the 
    values of the nodes in the tree.

    Input: root = [5,3,6,2,4,null,null,1], k = 3
    Output: 3
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

class Solution{
    public:
    void inorder(TreeNode* root, vector<int>& arr) {
        if(!root)
            return;
        
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

    int solve(TreeNode* root, int k, int& i) {
        if(root == NULL)
            return -1;
        
        int left = solve(root->left, k, i);

        if(left != -1)
            return left;
        i++;
        if(i==k)
            return root->val;
        
        solve(root->right, k, i);
    }

    int kThSmallest(TreeNode* root, int k) {
        int i= 0;
        return solve(root, k, i);

        // vector<int> ino;
        // inorder(root, ino);

        // return ino[k-1];
    }
};
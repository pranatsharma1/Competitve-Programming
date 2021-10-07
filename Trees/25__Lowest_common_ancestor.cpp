// Date: 28/09/2021

// Problem Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// Youtube Link: https://www.youtube.com/watch?v=_-QHfMDde90&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=28
// Submission Link: https://leetcode.com/submissions/detail/499142185/

// Time Complexity: O(N)
// Space Complexity: O(N)

//-----------------------------------Main Code Starts-------------------------------------------//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        
        if(root == NULL)
           return NULL;
        
        if(root == p or root == q)
            return root;
        
        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);
        
        if(left and right)
           return root;
        
        if(left != NULL)
           return left;
        else
           return right;
    }
};
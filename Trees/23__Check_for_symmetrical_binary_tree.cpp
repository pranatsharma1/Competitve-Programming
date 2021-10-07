// Date: 28/09/2021

// Problem Link: https://leetcode.com/problems/symmetric-tree/
// Youtube Link: https://www.youtube.com/watch?v=nKggNAiEpBE&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=26
// Submission Link: https://leetcode.com/submissions/detail/562220579/

// Time Complexity: O(N)
// Space Complexity: O(N)

//-----------------------------------Main Code Starts-------------------------------------------//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) 
    {
        if(root == NULL)
            return true;
        
        return isMirror(root -> left, root -> right);
    }
    
    bool isMirror(TreeNode* A, TreeNode* B)
    {
        if(A == NULL and B == NULL)
            return true;
        if(A == NULL or B == NULL)
            return false;
        
        return (A -> val == B -> val and isMirror(A -> left, B -> right) and isMirror(A -> right, B -> left));
        
    }
};
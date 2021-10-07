// Date: 10/09/2021

// Problem Link: https://leetcode.com/problems/diameter-of-binary-tree/
// Youtube Link: https://www.youtube.com/watch?v=Rezetez59Nk&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=17
// Submission Link: https://leetcode.com/submissions/detail/552266840/

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
    
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int diameter = 0;
        height(root, diameter);
        
        return diameter;
    }
    
private:
    
    int height(TreeNode* root, int& diameter)
    {
        if(root == NULL)
            return 0;
        
        int lh = height(root -> left, diameter);
        int rh = height(root -> right, diameter);
        
        diameter = max(diameter, lh + rh);
        
        return 1 + max(lh, rh);
        
    }
    
};
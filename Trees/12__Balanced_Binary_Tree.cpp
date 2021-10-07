// Date: 10/09/2021

// Problem Link: https://leetcode.com/problems/balanced-binary-tree/
// Youtube Link: https://www.youtube.com/watch?v=Yt50Jfbd8Po&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=16
// Submission Link: https://leetcode.com/submissions/detail/552262154/

// Time Complexity: O(N)
// Space Complexity: O(N) in worst case(skew tree)

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
    
    int height(TreeNode *root)
    {
        if(root == NULL)
            return 0;
        
        int lHeight = height(root -> left);
        int rHeight = height(root -> right);
        
        if(lHeight == -1 or rHeight == -1)
            return -1;
        
        if(abs(lHeight - rHeight) > 1)
            return -1;
        
        return max({lHeight, rHeight}) + 1;
        
    }
    
    bool isBalanced(TreeNode* root) 
    {
        return height(root) != -1;
    }
};
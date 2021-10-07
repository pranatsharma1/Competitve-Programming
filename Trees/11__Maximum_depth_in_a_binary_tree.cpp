// Date: 10/09/2021

// Problem Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Youtube Link: https://www.youtube.com/watch?v=eD3tmO66aBA&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=15
// Submission Link: https://leetcode.com/submissions/detail/552258061/

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
    int maxDepth(TreeNode* root) 
    {
        
        if(root == NULL)
            return 0;
        
        int lh = maxDepth(root -> left);
        int rh = maxDepth(root -> right);
        
        return 1 + max(lh, rh);
        
    }
};
// Date: 26/09/2021

// Problem Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Youtube Link: https://www.youtube.com/watch?v=WszrfSwMz58&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=18
// Submission Link: https://leetcode.com/submissions/detail/561138196/

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
    
    int max_path(TreeNode* node, int& ans)
    {
        if(node == NULL)
            return 0;
        
        int leftSum = max(0,max_path(node -> left, ans));
        int rightSum = max(0,max_path(node -> right, ans));
        
        ans = max(ans, node -> val + leftSum + rightSum);
        
        // for this node, either we have to take the left path or the right path, therefore we take the maximum of leftSum and rightSum;
        return node -> val + max(leftSum, rightSum);
        
    }
    
    int maxPathSum(TreeNode* root) 
    {
        int ans = INT_MIN;
        
        max_path(root, ans);
        
        return ans;
    }
};
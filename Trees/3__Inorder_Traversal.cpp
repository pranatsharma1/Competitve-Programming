// Date: 19/05/2021

// Problem Link: https://leetcode.com/problems/binary-tree-inorder-traversal/
// Editorial : https://leetcode.com/problems/binary-tree-inorder-traversal/discuss/31231/C%2B%2B-Iterative-Recursive-and-Morris 
// Submission Link: https://leetcode.com/submissions/detail/495051863/

// Time Complexity: O(N)
// Space Complexity: O(N) for function call stack
 
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
            
    void inorder(TreeNode* root, vector<int>&ans)
    {
        if(root)
        {
            inorder(root -> left, ans);
            ans.push_back(root -> val);
            inorder(root -> right, ans);
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int>ans;
        inorder(root, ans);
        return ans;
    }
    
};
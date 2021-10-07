// Date: 23/08/2021

// Problem Link: https://leetcode.com/problems/binary-tree-preorder-traversal/
// Youtube Link: https://www.youtube.com/watch?v=RlUu72JrOCQ&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=7
// Submission Link: https://leetcode.com/submissions/detail/542858811/

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
    
    void preorder(TreeNode* root, vector<int>& ans)
    {
        if(root == NULL)
            return;
        
        ans.push_back(root -> val);
        preorder(root -> left, ans);
        preorder(root -> right, ans);
        
    }
    
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        preorder(root, ans);
        
        return ans;
    }
};
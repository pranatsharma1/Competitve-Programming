// Date: 19/05/2021

// Problem Link: https://leetcode.com/problems/binary-tree-postorder-traversal/
// Editorial: https://leetcode.com/problems/binary-tree-postorder-traversal/discuss/45550/C%2B%2B-Iterative-Recursive-and-Morris-Traversal  
// Submission Link: https://leetcode.com/submissions/detail/495054475/

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
    
    void postorder(TreeNode* root, vector<int>&ans)
    {
        if(root)
        {
            postorder(root -> left, ans);
            postorder(root -> right, ans);
            ans.push_back(root -> val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int>ans;
        postorder(root, ans);
        
        return ans;
    }
};
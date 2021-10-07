// Date: 09/09/2021

// Problem Link: https://leetcode.com/problems/binary-tree-preorder-traversal/
// Youtube Link: https://www.youtube.com/watch?v=Bfqd8BsPVuw&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=11&t=188s
// Submission Link: https://leetcode.com/submissions/detail/551978977/

// Time Complexity: O(N)
// Space Complexity: O(N) or O(height of binary tree)

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
    
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        
        if(root == NULL)
            return ans;

        stack<TreeNode*> s;
        s.push(root);
        
        while(!s.empty())
        {
            TreeNode* node = s.top();
            s.pop();
            
            ans.push_back(node -> val);
            
            if(node -> right != NULL)
                s.push(node -> right);

            if(node -> left != NULL)
                s.push(node -> left);
            
        }
        
        return ans;
    }
};
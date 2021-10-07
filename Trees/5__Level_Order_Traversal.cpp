// Date: 23/08/2021

// Problem Link: https://leetcode.com/problems/binary-tree-level-order-traversal/
// Youtube Link: https://www.youtube.com/watch?v=EoAsWbO7sqg&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=9
// Submission Link: https://leetcode.com/submissions/detail/542864160/

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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>>ans;
        
        if(root == NULL)
            return ans;
        
        queue<TreeNode *>q;
        q.push(root);
        
        while(!q.empty())
        {
            vector<int>level;
            
            int n = (int)q.size();
            for(int i = 0; i < n; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                
                if(node -> left != NULL)
                    q.push(node -> left);
                if(node -> right != NULL)
                    q.push(node -> right);
            }
            
            ans.push_back(level);
            
        }
                
        return ans;
        
    }
};
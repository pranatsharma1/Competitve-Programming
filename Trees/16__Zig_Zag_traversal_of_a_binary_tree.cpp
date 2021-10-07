// Date: 26/09/2021

// Problem Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// Youtube Link: https://www.youtube.com/watch?v=3OXWEdlIGl4&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=20
// Submission Link: https://leetcode.com/submissions/detail/561168318/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
            
        vector<vector<int>> ans;
        
        if(root == NULL)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int level = 0;
        while(!q.empty())
        {
            
            int n = (int)q.size();
            
            vector<int> tmp(n);
            for(int i = 0; i < n; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                
                int index = i;
                
                if(level&1)
                    index = n - 1 - i;
                
                tmp[index] = node -> val;
                
                if(node -> left)
                    q.push(node -> left);
                if(node -> right)
                    q.push(node -> right);
                 
            }
            
            level++;
            
            ans.push_back(tmp);
            
        }
        
        return ans;
        
    }
};
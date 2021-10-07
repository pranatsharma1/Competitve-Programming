// Date: 27/09/2021

// Problem Link: https://leetcode.com/problems/binary-tree-right-side-view/
// Youtube Link: https://www.youtube.com/watch?v=KV4mRzTjlAk&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=25
// Submission Link: https://leetcode.com/submissions/detail/561801034/

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
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> ans;
        
        if(root == NULL)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int n = (int)q.size();
            for(int i = 0; i < n; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                
                if(i == n - 1)
                    ans.push_back(node -> val);
                
                if(node -> left)
                    q.push(node -> left);
                if(node -> right)
                    q.push(node -> right);
            }
        }
        
        return ans;
        
    }
};
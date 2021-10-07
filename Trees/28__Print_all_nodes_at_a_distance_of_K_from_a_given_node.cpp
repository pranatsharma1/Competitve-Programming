// Date: 01/10/2021

// Problem Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
// Youtube Link: https://www.youtube.com/watch?v=i9ORlEy6EsI&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=31&t=190s
// Submission Link: https://leetcode.com/submissions/detail/563657436/

// Time Complexity: O(N) + O(N)
// Space Complexity: O(N) + O(N) + O(N)

//-----------------------------------Main Code Starts-------------------------------------------//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void mark_parents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent)
    {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int size = (int)q.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode* cur = q.front();
                q.pop();
                
                if(cur -> left)
                {
                    q.push(cur -> left);
                    parent[cur -> left] = cur;
                }
                if(cur -> right)
                {
                    q.push(cur -> right);
                    parent[cur -> right] = cur;
                }
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        
        vector<int> ans;
        
        unordered_map<TreeNode*, TreeNode*> parent;
        mark_parents(root, parent);
        
        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;
        
        int level = 0;
        while(!q.empty())
        {
            if(level++ == k)
                break;
            
            int size = (int)q.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode* cur = q.front();
                q.pop();
                
                if(cur -> left and !vis[cur -> left])
                    q.push(cur -> left), vis[cur -> left] = true;
                if(cur -> right and !vis[cur -> right])
                    q.push(cur -> right), vis[cur -> right] = true;
                if(parent[cur] and !vis[parent[cur]])
                    q.push(parent[cur]), vis[parent[cur]] = true;
            }
        }
        
        while(!q.empty())
        {
            ans.push_back(q.front() -> val);
            q.pop();
        }
        
        return ans;
        
    }
};
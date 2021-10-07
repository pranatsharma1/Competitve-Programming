// Date: 27/09/2021

// Problem Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree
// Youtube Link: https://www.youtube.com/watch?v=q_a6lpbKJdw&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=23
// Submission Link: https://leetcode.com/submissions/detail/561776332/

// Time Complexity: O(N) or O(N * logN) if using multiset because it takes logN time for insertion
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
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        vector<vector<int>> ans;
        
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0, 0}});
        
        map<int, map<int,multiset<int>>> nodes;
        
        while(!q.empty())
        {
            int n = (int)q.size();
                
            for(int i = 0; i < n; i++)
            {
                TreeNode* node = q.front().first;
                int x = q.front().second.first;
                int y = q.front().second.second;
                
                nodes[x][y].insert(node -> val);
                
                q.pop();
                
                if(node -> left)
                    q.push({node -> left, {x - 1, y + 1}});
                if(node -> right)
                    q.push({node -> right, {x + 1, y + 1}});
                
            }
            
        }
        
        for(auto i : nodes)
        {
            vector<int> tmp;
            for(auto j : i.second)
                for(auto k : j.second)
                    tmp.push_back(k);
            ans.push_back(tmp);
        }
        
        return ans;
        
    }
};
// Date: 30/09/2021

// Problem Link: https://leetcode.com/problems/maximum-width-of-binary-tree/
// Youtube Link: https://www.youtube.com/watch?v=ZbybYvcVLks&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=29
// Submission Link: https://leetcode.com/submissions/detail/563220644/

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
    int widthOfBinaryTree(TreeNode* root) 
    {
        int ans = 0;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while(!q.empty())
        {
            int size = (int)q.size();
            int mn = q.front().second;
            
            int first = 1, last = 1; 
            for(int i = 0; i < size; i++)
            {
                TreeNode* node = q.front().first;
                int ind = q.front().second - mn;
                q.pop();
                
                if(i == 0)
                    first = ind;
                if(i == size - 1)
                    last = ind;
                
                if(node -> left)
                    q.push({node -> left, ind * 2 + 1});
                if(node -> right)
                    q.push({node -> right, ind * 2 + 2});
            }
            
            ans = max(ans, last - first + 1);
        }
        
        return ans;
    }
};
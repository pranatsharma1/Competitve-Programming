// Date: 09/09/2021

// Problem Link: https://leetcode.com/problems/binary-tree-inorder-traversal/
// Youtube Link: https://www.youtube.com/watch?v=lxTGsVXjwvM&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=11
// Submission Link: https://leetcode.com/submissions/detail/551985256/

// Time Complexity: O(N)
// Space Complexity: O(N) -> worst case when tree is skew tree

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
    
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int>ans;
        
        if(root == NULL)
            return ans;
        
        stack<TreeNode*> s;
        
        TreeNode* node = root;
        
        while(true)
        {
            if(node != NULL)
            {
                s.push(node);
                node = node -> left;
            }
            else
            {
                if(s.empty()) 
                    break;
                
                node = s.top();
                s.pop();
                
                ans.push_back(node -> val);
                node = node -> right;
            }
            
        }
        
        return ans;
    }
    
};
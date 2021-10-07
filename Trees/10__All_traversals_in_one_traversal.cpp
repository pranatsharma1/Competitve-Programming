// Date: 10/09/2021

// Problem Link: https://leetcode.com/problems/binary-tree-preorder-traversal/
// Youtube Link: https://www.youtube.com/watch?v=ySp2epYvgTE&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=14&t=321s
// Submission Link: https://leetcode.com/submissions/detail/552244386/

// Time Complexity: O(3 * N)
// Space Complexity: O(3 * N)

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
        vector<int> preorder, inorder, postorder;
        
        if(root == NULL)
            return postorder;
        
        stack<pair<TreeNode*, int>> s;
        s.push({root, 1});
        
        while(!s.empty())
        {
            auto it = s.top();
            s.pop();
            
            if(it.second == 1)
            {
                preorder.push_back(it.first -> val);
                s.push({it.first, 2});
                
                if(it.first -> left != NULL)
                    s.push({it.first -> left, 1});
            }
            else if(it.second == 2)
            {
                inorder.push_back(it.first -> val);
                s.push({it.first, 3});
                
                if(it.first -> right != NULL)
                    s.push({it.first -> right, 1});
            }
            else
            {
                postorder.push_back(it.first -> val);
            }
        }
        
        
        return preorder;
    }
};
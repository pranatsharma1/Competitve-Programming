// Date: 09/09/2021

// Problem Link: https://leetcode.com/problems/binary-tree-postorder-traversal/
// Youtube Link: https://www.youtube.com/watch?v=2YBhNLodD8Q&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=12
// Submission Link: https://leetcode.com/submissions/detail/551988993/

// Time Complexity: O(N)
// Space Complexity: O(N) + O(N)

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
    
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int>ans;
        
        if(root == NULL)
            return ans;
        
        stack<TreeNode *> s1, s2;
        s1.push(root);
        
        while(!s1.empty())
        {
            TreeNode* node = s1.top();
            s1.pop();
            
            s2.push(node);
            if(node -> left)
                s1.push(node -> left);
            if(node -> right)
                s1.push(node -> right);
        }
        
        while(!s2.empty())
        {
            ans.push_back(s2.top() -> val);
            s2.pop();
        }
        
        return ans;
    }
};
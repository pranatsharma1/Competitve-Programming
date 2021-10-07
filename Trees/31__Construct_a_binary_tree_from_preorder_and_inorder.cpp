// Date: 03/10/2021

// Problem Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Youtube Link: https://www.youtube.com/watch?v=aZNaLrVebKQ&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=35
// Submission Link: https://leetcode.com/submissions/detail/564645692/

// Time Complexity: O(N) or O(N*logN) depending on the hashmap you use 
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        map<int,int> m;
        for(int i = 0; i < (int)inorder.size(); i++)
            m[inorder[i]] = i;
        
        TreeNode* root = buildTree(preorder, 0, (int)preorder.size() - 1, inorder, 0, (int)inorder.size() - 1, m);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int>& m)
    {
        if(preStart > preEnd or inStart > inEnd)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        int inRoot = m[root -> val];
        int numsLeft = inRoot - inStart;
        
        root -> left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, m);
        
        root -> right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, m);
        
        return root;
        
    }
    
};
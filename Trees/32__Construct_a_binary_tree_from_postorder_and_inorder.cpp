// Date: 03/10/2021

// Problem Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// Youtube Link: https://www.youtube.com/watch?v=LgLRTaEMRVc&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=36&t=121s
// Submission Link: https://leetcode.com/submissions/detail/564871992/

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        map<int, int> m;
        for(int i = 0; i < inorder.size(); i++)
            m[inorder[i]] = i;
        
        TreeNode* root = buildTree(inorder, 0, inorder.size() - 1,
                                  postorder, 0, postorder.size() - 1, m); 
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, map<int, int>& m)
    {
        if(postStart > postEnd or inStart > inEnd)
            return NULL;
        
        TreeNode* root = new TreeNode(postorder[postEnd]);
        
        int inRoot = m[postorder[postEnd]];
        int numsLeft = inRoot - inStart;
        
        root -> left = buildTree(inorder, inStart, inRoot - 1, postorder, postStart, postStart + numsLeft - 1, m);
        
        root -> right = buildTree(inorder, inRoot + 1, inEnd, postorder, postStart + numsLeft, postEnd - 1, m);
        
        return root;
    }
    
};
// Date: 26/09/2021

// Problem Link: https://leetcode.com/problems/same-tree/
// Youtube Link: https://www.youtube.com/watch?v=BhuvF_-PWS0&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=19
// Submission Link: https://leetcode.com/submissions/detail/561151923/

// Time Complexity: O(N) for any tree traversal
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
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(p == NULL or q == NULL)
            return p == q;
        
        return (p -> val == q -> val and isSameTree(p -> left, q -> left) and isSameTree(p -> right, q -> right));    
        
    }
};
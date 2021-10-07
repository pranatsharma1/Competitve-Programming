// Date:

// Problem Link: https://leetcode.com/problems/count-complete-tree-nodes
// Youtube Link: https://leetcode.com/submissions/detail/564079591/
// Submission Link: https://leetcode.com/submissions/detail/564079591/
// Editorial: https://leetcode.com/problems/count-complete-tree-nodes/discuss/61953/Easy-short-c%2B%2B-recursive-solution

// Time Complexity: O(logN) * O(logN)
// Space Complexity: O(logN)

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
    int countNodes(TreeNode* root) 
    {
        if(root == NULL)
            return 0;
        
        int lh = leftHeight(root);
        int rh = rightHeight(root);
        
        // if this subtree is a complete binary tree
        if(lh == rh)
            return (1 << lh) - 1;
        else
            return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
    
    int leftHeight(TreeNode* node)
    {
        int h = 0;
        
        while(node)
        {
            h++;
            node = node -> left;
        }
        return h;
    }
    
    int rightHeight(TreeNode* node)
    {
        int h = 0;
        
        while(node)
        {
            h++;
            node = node -> right;
        }
        return h;
    }
};
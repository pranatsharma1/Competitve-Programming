// Date: 04/10/2021

// Problem Link: https://leetcode.com/problems/insert-into-a-binary-search-tree/ 
// Youtube Link: https://www.youtube.com/watch?v=FiFiNvM29ps&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=44&t=342s

// Time Complexity: O(logN)
// Space Complexity: O(1)

//-----------------------------------Main Code Starts-------------------------------------------//

/*
We will always insert the node as a leaf node in our BST.
*/

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
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        if(root == NULL)
        {
            root = new TreeNode(val);
            return root;
        }
        
        TreeNode* cur = root;
        while(true)
        {            
            if(cur -> val <= val)
            {
                if(cur -> right != NULL)
                    cur = cur -> right;
                else
                {
                    cur -> right = new TreeNode(val);
                    break;
                }
            }
            else
            {
                if(cur -> left != NULL)
                    cur = cur -> left;
                else
                {
                    cur -> left = new TreeNode(val);
                    break;
                }
            }
        }
        
        return root;
    }
};
// Date: 09/09/2021

// Problem Link: https://leetcode.com/problems/binary-tree-postorder-traversal/
// Youtube Link: https://www.youtube.com/watch?v=NzIGLLwZBS8&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=13
// Submission Link: https://leetcode.com/submissions/detail/551994384/

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
    
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int>ans;
        
        if(root == NULL)
            return ans;
        
        stack<TreeNode*> s;
        TreeNode* current = root;
        
        while(current != NULL or !s.empty())
        {
            // pehle left jaate jao
            if(current != NULL)
            {
                s.push(current);
                current = current -> left;
            }
            else
            {
                // ab left nahi mila to right dekho

                TreeNode* tmp = s.top() -> right;
                
                if(tmp == NULL)
                {
                    // right nahi mila to isko ans me push back krdo aur fir upar jao
                    tmp = s.top();
                    s.pop();
                    ans.push_back(tmp -> val);
                    
                    while(!s.empty() and tmp == s.top() -> right)
                    {
                        tmp = s.top();
                        s.pop();
                        ans.push_back(tmp -> val);
                    }
                }
                else
                {
                    // right mil gaya hai to ab iske left me jaate jao
                    current = tmp;
                }
            }
        }
        
        return ans;
    }
};
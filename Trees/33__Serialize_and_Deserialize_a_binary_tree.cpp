// Date: 03/10/2021

// Problem Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// Youtube Link: https://www.youtube.com/watch?v=-YbXySKJsX8&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=37
// Submission Link: https://leetcode.com/submissions/detail/564990314/
 
// Time Complexity: O(N) for level order traversal
// Space Complexity: O(N)

//-----------------------------------Main Code Starts-------------------------------------------//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
            
        string s = "";
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            
            for(int i = 0; i < n; i++)
            {
                TreeNode* cur = q.front();
                q.pop();
                
                if(cur == NULL)
                    s.push_back('#');
                else
                {
                    s += to_string(cur -> val);
                    q.push(cur -> left);
                    q.push(cur -> right);
                }
                
                s.push_back(',');
            }
        }
                
        cout << s << endl;
        return s ;
        
        
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        
        if(data.size() == 0)
            return NULL;
        
        stringstream s(data);
        
        string str;
        getline(s, str, ',');
        
        if(str == "#")
            return NULL;
        
        TreeNode* root = new TreeNode(stoi(str));
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* cur = q.front();
            q.pop();
            
            getline(s, str, ',');            
            if(str == "#")
                cur -> left = NULL;
            else
            {
                TreeNode* leftNode = new TreeNode(stoi(str));
                cur -> left = leftNode;
                q.push(leftNode);
            }
            
            getline(s, str, ',');
            if(str == "#")
                cur -> right = NULL;
            else
            {
                TreeNode* rightNode = new TreeNode(stoi(str));
                cur -> right = rightNode;
                q.push(rightNode);
            }
        }
        
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
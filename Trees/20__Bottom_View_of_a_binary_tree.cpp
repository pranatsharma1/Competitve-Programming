// Date: 27/09/2021

// Problem Link: https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
// Youtube Link: https://www.youtube.com/watch?v=0FtVY6I4pB8&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=24

// Time Complexity: O(N)
// Space Complexity: O(N)

//-----------------------------------Main Code Starts-------------------------------------------//

class Solution {
  public:
    vector <int> bottomView(Node *root) 
    {
        // Your Code Here
        vector<int> ans;
        if(root == NULL)
            return ans;
            
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        map<int,int> m;
        
        while(!q.empty())
        {
            int n = (int)q.size();
            for(int i = 0; i < n; i++)
            {
                Node* node = q.front().first;
                int x = q.front().second;
                
                m[x] = node -> data;
                
                q.pop();
                
                if(node -> left)
                    q.push({node -> left, x - 1});
                if(node -> right)
                    q.push({node -> right, x + 1});
                
            }
        }
        
        for(auto i : m)
            ans.push_back(i.second);
            
        return ans;
        
    }
};
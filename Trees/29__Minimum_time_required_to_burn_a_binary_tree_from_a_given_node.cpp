// Date: 01/10/2021
  
// Problem Link: https://www.codingninjas.com/codestudio/problems/time-to-burn-tree_630563?source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos&leftPanelTab=0
// Youtube Link: https://www.youtube.com/watch?v=u-yWemKGWO0&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=33

// Time Complexity: O(N)
// Space Complexity: O(N)

//-----------------------------------Main Code Starts-------------------------------------------//

/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<map>
void find_parents(BinaryTreeNode<int>* root, map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& parent)
{
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty())
    {
        int size = (int)q.size();
        
        for(int i = 0; i < size; i++)
        {
            auto node = q.front();
            q.pop();
            
            if(node -> left)
                q.push(node -> left), parent[node -> left] = node;
            if(node -> right)
                q.push(node -> right), parent[node -> right] = node;
        }
    }
}

void find_node(BinaryTreeNode<int>* root, int start, BinaryTreeNode<int>* &source)
{
    if(root == NULL)
        return;
    
    if(root -> data == start)
        source = root;
    
    find_node(root -> left, start, source);
    find_node(root -> right, start, source);
    
}

int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    // Write your code here

    // Approach : 1. Mark parents for each node first
    // 2. If not given the address of node, find the address of it using any traversal technique
    // 3. Then apply level order traversal from that node.

    map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> parent;
    find_parents(root, parent);
    
    BinaryTreeNode<int>* source;
    find_node(root, start, source);
    
    int time = 0;
    queue<BinaryTreeNode<int>*> q;
    q.push(source);
    
    map<BinaryTreeNode<int>*, bool> burnt;
    burnt[source] = true;
    
    while(!q.empty())
    {
        int size = (int)q.size();
        
        int f = 0;
        for(int i = 0; i < size; i++)
        {
            auto cur = q.front();
            q.pop();
            
            if(cur -> left and !burnt[cur -> left])
                f = 1, q.push(cur -> left), burnt[cur -> left] = true;
            if(cur -> right and !burnt[cur -> right])
                f = 1, q.push(cur -> right), burnt[cur -> right] = true;
            if(parent[cur] and !burnt[parent[cur]])
                f = 1, q.push(parent[cur]), burnt[parent[cur]] = true;
        }
        if(f)
            time++;
    }
    
    return time;
    
    
}

// Date: 04/10/2021

// Problem Link: https://www.codingninjas.com/codestudio/problems/floor-from-bst_920457?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=1
// Youtube Link: https://www.youtube.com/watch?v=xm_W1ub-K-w&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=43

// Time Complexity: O(logN)
// Space Complexity: O(1)

//-----------------------------------Main Code Starts-------------------------------------------//

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    int ans = -1;
    
    while(root != NULL)
    {
        if(root -> val == X)
            return root -> val;
        else if(root -> val < X)
        {
            ans = root -> val;
            root = root -> right;
        }
        else
            root = root -> left;
    }
    
    return ans;
}
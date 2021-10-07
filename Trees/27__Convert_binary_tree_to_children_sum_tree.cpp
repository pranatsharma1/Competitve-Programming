// Date: 30/09/2021

// Youtube Link: https://www.youtube.com/watch?v=fnmisPM6cVo&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=30

// Time Complexity: O(N)
// Space Complexity: O(H) or O(N) in case of skew tree

//-----------------------------------Main Code Starts-------------------------------------------//

void reorder(TreeNode* root)
{
    if(root == NULL)
        return ;

    int child = 0;
    if(root -> left)
        child += root -> left -> data;
    if(root -> right)
        child += root -> right -> data;

    if(child < root -> data)
    {
        if(root -> left)
            root -> left -> data = root -> data;
        if(root -> right)
            root -> right -> data = root -> data;
    }
    else
        root -> data = child;

    reorder(root -> left);
    reorder(root -> right);

    int total = 0;

    if(root -> left)
        total += root -> left -> data;
    if(root -> right)
        total += root -> right -> data;
    if(root -> left or root -> right)
        root -> data = total;
}

void changeTree(TreeNode* root)
{
    reorder(root);
}
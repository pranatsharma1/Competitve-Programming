// Date: 28/09/2021

// Problem Link: https://www.geeksforgeeks.org/print-path-root-given-node-binary-tree/
// Youtube Link: https://www.youtube.com/watch?v=fmflMqVOC7k&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=27

// Time Complexity:
// Space Complexity:

//-----------------------------------Main Code Starts-------------------------------------------//

bool getPath(TreeNode *root, vector<int> &arr, int x) {
    // if root is NULL
    // there is no path
    if (!root)
        return false;
     
    // push the node's value in 'arr'
    arr.push_back(root->val);   
     
    // if it is the required node
    // return true
    if (root->val == x)   
        return true;
     
    // else check whether the required node lies
    // in the left subtree or right subtree of
    // the current node
    if (getPath(root->left, arr, x) ||
        getPath(root->right, arr, x))
        return true;
     
    // required node does not lie either in the
    // left or right subtree of the current node
    // Thus, remove current node's value from
    // 'arr'and then return false   
    arr.pop_back();
    return false;  
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> arr; 
    if(A == NULL) {
        return arr; 
    }
    getPath(A, arr, B);
    return arr; 
}
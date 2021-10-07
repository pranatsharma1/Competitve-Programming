// Date: 04/10/2021

// Problem Link: https://www.codingninjas.com/codestudio/problems/ceil-from-bst_920464?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=0
// Youtube Link: youtube.com/watch?v=KSsk8AhdOZA&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=42

// Time Complexity: O(logN)
// Space Complexity: O(1)

//-----------------------------------Main Code Starts-------------------------------------------//

 int findCeil(BinaryTreeNode<int> *node, int x)
 {
  // Write your code here
    int ans = -1;
     
     while(node != NULL)
     {
         if(x <= node -> data)
         {
             ans = node -> data;
             node = node -> left;
         }
         else
             node = node -> right;
     }
     
     return ans;
     
}
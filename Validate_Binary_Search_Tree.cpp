/* Given a binary tree, determine if it is a valid binary search tree (BST).
 * Assume a BST is defined as follows:
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
 * Thought: inorder traversal of a search binary tree output an ordered array. 
 * If the output array is not orderred, the tree isn't a search binary tree. 
 * We cannot just use recursive method for judge becasue even if the left tree and right tree 
 * are all search binary tree, and the root < left && root>right, 
 * we still cannot say the tree is search binary tree. Take [10, 5, 15, #,#,6,26] for consideration.
*/

class Solution {  
 public:  
   void it(TreeNode *root, vector<TreeNode *> &array) {  
     if (!root->left && !root->right) {  
       array.push_back(root);  
       return;  
     }  
     if (root->left) it(root->left, array);  
     array.push_back(root);  
     if (root->right) it(root->right, array);  
   }  
   bool isValidBST(TreeNode *root) {  
     if (root == NULL) return true;  
     if (root->left == NULL & root->right == NULL) return true;  
     vector<TreeNode *> array;  
     it(root, array);  
     int max = array[0]->val;  
     for (int i = 1; i < array.size(); i ++) {  
       if (array[i]->val <= max) return false;  
       max = array[i]->val;  
     }  
     return true;  
   }  
 };  

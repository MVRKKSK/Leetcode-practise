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
    bool checkSubTree(TreeNode * root1 , TreeNode * root2){
        if(!root1 && !root2) return true;
        if(!root1 || !root2) return false;
        return (root1->val == root2->val) && checkSubTree(root1->left , root2->left) && checkSubTree(root1->right , root2->right);    
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(root->val == subRoot->val){
            if(checkSubTree(root , subRoot)){
                return true;
            }
        }
        return isSubtree(root->left , subRoot) || isSubtree(root->right , subRoot);
    }
};
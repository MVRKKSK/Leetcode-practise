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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode *> kyu;
        int i=0;
        kyu.push(root);
        while(!kyu.empty()){
            i++;
            int n = kyu.size();
            for(int j=0;j<n;j++){
                TreeNode * node = kyu.front();
                kyu.pop();
                if(node->left){
                    kyu.push(node->left);
                }
                if(node->right){
                    kyu.push(node->right);
                }
                if(!node->left && !node->right){
                    return i;
                }
            }    
        }
        return i;
    }
};
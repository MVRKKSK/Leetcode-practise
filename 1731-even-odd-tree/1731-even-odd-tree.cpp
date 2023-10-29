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
    bool isEvenOddTree(TreeNode* root) {
        if(!root) return false;
        queue<TreeNode *> kyu;
        kyu.push(root);
        bool isEven = true;
        while(!kyu.empty()){
            int prev = isEven ? INT_MIN : INT_MAX;
            int siz = kyu.size();
            for(int i=0;i<siz;i++){
                TreeNode*n = kyu.front();
                kyu.pop();
                if (isEven) {
                    if (n->val % 2 == 0 || n->val <= prev) {
                        return false;
                    }
                } else {
                    if (n->val % 2 != 0 || n->val >= prev) {
                        return false;
                    }
                }
                if(n->left){
                    kyu.push(n->left);
                }
                if(n->right){
                    kyu.push(n->right);
                }
                prev = n->val;
            }
            isEven = !isEven;
        }
        return true;
    }
};
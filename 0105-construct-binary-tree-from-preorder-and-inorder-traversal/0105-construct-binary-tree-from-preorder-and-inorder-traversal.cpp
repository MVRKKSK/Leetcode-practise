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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        int istart = 0;
        int pstart = 0;
        int iend = inorder.size() - 1; // Corrected index calculation
        int pend = preorder.size() - 1; // Corrected index calculation

        for (int i = 0; i <= iend; i++) { // Use <= to include the last element
            mp[inorder[i]] = i;
        }

        return solve(preorder, inorder, mp, istart, iend, pstart, pend);
    }

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& mp, int istart, int iend, int pstart, int pend) {
        if (istart > iend || pstart > pend) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[pstart]);
        int inroot = mp[root->val];
        int numval = inroot - istart;

        root->left = solve(preorder, inorder, mp, istart, inroot - 1, pstart + 1, pstart + numval);
        root->right = solve(preorder, inorder, mp, inroot + 1, iend, pstart + numval + 1, pend);

        return root;
    }

};
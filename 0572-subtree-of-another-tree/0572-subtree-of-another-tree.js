/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} subRoot
 * @return {boolean}
 */
var checkSubtree = function(root1, root2) {
    if (!root1 && !root2) {
        return true;
    }
    if (!root1 || !root2) {
        return false;
    }
    return root1.val === root2.val && checkSubtree(root1.left, root2.left) && checkSubtree(root1.right, root2.right);
}

var isSubtree = function(root, subRoot) {
    if (!root) {
        return false;
    }
    if (checkSubtree(root, subRoot)) {
        return true;
    }
    return isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot);
};

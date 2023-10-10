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
 * @return {number[]}
 */
var rightSideView = function(root) {
    if(!root) return [];
    let kyu = [];
    kyu.push(root);
    let ans = [];
    while(kyu.length>0){
        let n = kyu.length;
        for(let i=0;i<n;i++){
            let nroot = kyu.shift();
            if(i===n-1){
                ans.push(nroot.val);
            }
            if(nroot.left){
                kyu.push(nroot.left);
            }
            if(nroot.right){
                kyu.push(nroot.right);
            }
        }
    }
    return ans;
};
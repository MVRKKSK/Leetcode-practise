/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function(head) {
    let curr  = head;
    let prev = null;
    while(curr!=null){
        const n = curr.next;
        curr.next = prev;
        prev = curr;
        curr = n;
    }
    return prev;
};
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var detectCycle = function(head) {
    let slow = head;
    let fast = head;
    let hasCycle = false;
    while(fast && fast.next){
        slow = slow.next;
        fast = fast.next.next;
        if(slow===fast){
            hasCycle = true;
            break;
        }
    }
    if(!hasCycle){
        return null;
    }
    else{
        slow = head;
        while(slow!=fast){
            slow = slow.next;
            fast = fast.next;
        }
    }
    return slow;
};
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
var mergeTwoLists = function(list1, list2) {
       let ans = new ListNode(0);
       let start = ans;
       while(list1!=null && list2!=null){
           if(list1.val>=list2.val){
               start.next = list2;
               start = start.next;
               list2=list2.next;
           }
           else{
               start.next = list1;
               start = start.next;
               list1=list1.next;
           }
  
       }
                if(list1==null){
               start.next = list2;
           }
           if(list2==null){
               start.next = list1;
           }
       return ans.next;
};
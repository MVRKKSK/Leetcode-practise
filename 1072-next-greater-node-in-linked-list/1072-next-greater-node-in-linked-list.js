/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {number[]}
 */
var nextLargerNodes = function(head) {
    let nums = [];
    while(head){
        nums.push(head.val);
        head = head.next;
    }
    let revNums =  new Array(nums.length).fill(0);
    let currMax = nums[nums.length-1];
    console.log(currMax);
    for(let i=nums.length-2;i>=0;i--){
        if(nums[i]>currMax){
            currMax = nums[i];
            revNums[i] = 0;
        }
        else{
            let j = i+1;
            while(j<nums.length && nums[j]<=nums[i]){
                j++;
            }
            if(j<nums.length){
                revNums[i] = nums[j];
            }
            else{
                revNums[i] = 0;
            }
        }
    }
    return revNums;
};


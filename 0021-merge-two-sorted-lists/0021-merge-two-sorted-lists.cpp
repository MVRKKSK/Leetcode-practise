/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode temp(0);
        ListNode *ans = &temp, *start = &temp;
        while(list1!=NULL&&list2!=NULL)
        {
        if(list1->val<=list2->val)
        {
        start->next=list1;
        start=start->next;
        list1=list1->next;
        }
        else
        {
        start->next=list2;
        start=start->next;
        list2=list2->next;
        }
        }
        if(list1==NULL){
        start->next=list2;
        }
        else{
        start->next=list1;
        }
        return ans->next;
    }
};
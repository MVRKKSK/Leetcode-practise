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
    int getLength(ListNode * head){
        ListNode * temp = head;
        int count = 0;
        while(temp){
            count++;
            temp = temp->next;
        }
        return count;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) {
            return head;
        }

        int len = getLength(head);
        k = k % len;  // Reduce k to the equivalent rotation within the list length.

        if (k == 0) {
            return head; // No need to rotate if k is zero.
        }

        int rem = len - k;
        ListNode * p1 = head;
        ListNode * p2 = head;
        ListNode * p3 = head;
        ListNode * temp = head;
        int count = 0;

        while(temp){
            if(count == rem - 1){
                p2 = temp;
            }
            if(temp->next==nullptr){
                p3  = temp;
            }
            temp = temp->next;
            count++;
        }

        p3->next = head;
        head = p2->next;
        p2->next = nullptr;

        return head;
    }
};
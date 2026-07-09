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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)
          return head;

        int size=0;
        ListNode* ptr=head;
        while(ptr!=NULL) {
            size++;
            ptr=ptr->next;
        }

        if(size==n)
          return head->next;

        int step=size-n-1;
        ListNode* tail=head;
        while(step>0) {
            tail=tail->next;
            step--;
        }

        tail->next=tail->next->next;

        return head;

        
    }
};
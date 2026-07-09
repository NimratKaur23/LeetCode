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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)
          return head;
        
        //ListNode dummy(0,head);
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev=dummy, *curr=head;

        while(curr && curr->next) {
            ListNode* temp=curr->next->next;
            ListNode* second=curr->next;

            second->next=curr;
            curr->next=temp;
            prev->next=second;

            prev=curr;
            curr=temp;
        }

        // return dummy.next;
        return dummy->next;
        

    }
};
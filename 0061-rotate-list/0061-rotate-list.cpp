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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) 
            return head;

        // while(k) {
        //     ListNode* prev=head;
        //     ListNode* temp=head->next;

        //     while(temp->next!=NULL) {
        //         temp=temp->next;
        //         prev=prev->next;
        //     }

        //     temp->next=head;
        //     prev->next=NULL;
        //     head=temp;
        //     k--;
        // }

        // return head;


        int len=1;
        ListNode* count=head;

        while(count->next!=NULL) {
            len++;
            count=count->next;
        }

        k=k%len;

        ListNode* temp=head;
        for(int i=0;i<(len-k-1);i++) {
            temp=temp->next;
        }

        count->next=head;
        head=temp->next;
        temp->next=NULL;


        return head;

    }
};
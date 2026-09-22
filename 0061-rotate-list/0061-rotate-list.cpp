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
        if(head==NULL)
          return head;
        
        int n=1;
        ListNode* last=head;
        while(last->next!=NULL) {
            n++;
            last=last->next;
        }

        k=k%n;

        if(k==0)
          return head;
        
        int count=1;
        ListNode* temp=head;

        //trvaerse till (n-k)
        while(temp!=NULL){
            if(count==(n-k))
              break;
            count++;
            temp=temp->next;
        }

        //new head at (n-k+1)
        ListNode* res=temp->next;

        //3 steps
        last->next=head;
        temp->next=NULL;
        return res;
    }
};
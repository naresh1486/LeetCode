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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        if(head==NULL || k==1) {
            return head;
        }
        for(int i=0;i<k;i++) {
            if(temp==NULL) {
                return head;
            }
            temp=temp->next;
        }
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* forw=curr->next;
        for(int i=0;i<k;i++) {
            curr->next=prev;
            prev=curr;
            curr=forw;
            if(curr==NULL) {
                return prev;
            }
            forw=forw->next;
        }
        head->next=reverseKGroup(curr,k);
        return prev;
    }
};
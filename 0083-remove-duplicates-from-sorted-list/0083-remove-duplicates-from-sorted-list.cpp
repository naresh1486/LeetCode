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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr=head;
        ListNode* prev=head;
        if(head==NULL) {
            return NULL;
        }
        ListNode* forw=head->next;

        while(forw!=NULL) {
            if(curr->val==forw->val) {
                forw=forw->next;
                prev=prev->next;
            } else {
                curr->next=forw;
                if(prev!=curr) {
                    prev->next=NULL;
                }
                
                prev=forw;
                forw=forw->next;
                curr=curr->next;
            }
        }
        curr->next=NULL;
        return head;
    }
};
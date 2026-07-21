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
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL) {
            return true;
        }
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL) {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* prev=NULL;
        ListNode* forw=slow->next;
        while(slow!=NULL) {
            slow->next=prev;
            prev=slow;
            slow=forw;
            if(forw==NULL) {
                break;
            }
            forw=forw->next;
        }

        while(prev!=NULL) {
            if(head->val==prev->val) {
                head=head->next;
                prev=prev->next;
            } else {
                return false;
            }
        }
        return true;
    }
};
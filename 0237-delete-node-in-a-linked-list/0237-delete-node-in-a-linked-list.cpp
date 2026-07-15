/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* NextNode=node->next;
        node->val=NextNode->val;
        node->next=NextNode->next;
        NextNode->next=NULL;
    }
};
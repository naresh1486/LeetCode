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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        int carry=0;
        int count1=0;
        int count2=0;
        int ans=0;
        ListNode* connect=NULL;
        while(temp1!=NULL) {
            count1++;
            temp1=temp1->next;
        }
        while(temp2!=NULL) {
            count2++;
            temp2=temp2->next;
        }
        temp1=l1;
        temp2=l2;
        while(temp1!=NULL && temp2!=NULL) {
            ans=temp1->val+temp2->val+carry;
            if(true) {
                carry=ans/10;
                ans=ans%10;
            }
            if(count1>=count2) {
                temp1->val=ans;
            } else {
                temp2->val=ans;
            }
            if(temp1->next==NULL && temp2->next==NULL) {
                connect=temp1;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(count2>count1 && temp2!=NULL && carry==1) {
            ans=0;

            ans=temp2->val+carry;
            if(true) {
                carry=ans/10;
                ans=ans%10;
            }
            temp2->val=ans;
            if(temp2->next==NULL && carry==1) {
                ListNode* newNode=new ListNode(0);
                temp2->next=newNode;
            }
            temp2=temp2->next;
        }
        while(count1>count2 && temp1!=NULL && carry==1) {
            ans=0;
            ans=temp1->val+carry;
            if(true) {
                carry=ans/10;
                ans=ans%10;
            }
            temp1->val=ans;
            if(temp1->next==NULL && carry==1) {
                ListNode* newNode=new ListNode(0);
                temp1->next=newNode;
            }
            temp1=temp1->next;
        }
        if(carry==1 && temp1==NULL && temp2==NULL) {
            ListNode* newNode=new ListNode(carry);
            connect->next=newNode;
        }
        if(count1>=count2) {
            return l1;
        } else {
            return l2;
        }
    }
};
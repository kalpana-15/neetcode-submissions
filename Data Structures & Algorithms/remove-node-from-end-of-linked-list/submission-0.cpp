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
        if(head==nullptr) return head;
        if(head->next==nullptr && n==1) return nullptr;
        ListNode* temp=head;
        int size=0;
        while(temp){
            temp=temp->next;
            size++;
        }
        int num=size-n;
        if(num==0) {
            head=head->next;
            return head;
        }
        temp=head;
        ListNode* prev=head;
        while(num>0){
            prev=temp;
            temp=temp->next;
            num--;
        }
        prev->next=temp->next;
        return head;

    }
};

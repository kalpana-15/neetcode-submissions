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
        ListNode* a=l1;
        ListNode* b=l2;
        int ac=0,bc=0;
        while(a){
            if(a!=nullptr) ac++;
           
            a=a->next;
            
        }
        while(b){
             if(b!=nullptr) bc++;
             b=b->next;
        }
         a=l1;
        b=l2;
        ListNode* res=nullptr;
        if(ac>=bc) {
            res=a;
        }
        else{
            res=b;
        }
       
        int carry=0;
        ListNode* prev=a;
        while(a && b){
            prev=res;
            int v=a->val + b->val+carry;
            int nodeval= v%10;
            carry=v/10;
            res->val=nodeval;
            res=res->next;
            a=a->next;
            b=b->next;
        }
        while(a!=nullptr){
            prev=res;
            int v=a->val +carry;
            int nodeval= v%10;
            carry=v/10; 
            res->val=nodeval;
            res=res->next;
            a=a->next;
        }
        while(b!=nullptr){
            prev=res;
            int v=b->val +carry;
            int nodeval= v%10;
            carry=v/10;
            res->val=nodeval;
            res=res->next;
            b=b->next;
        }
        if(carry!=0){
            ListNode* mm=new ListNode(carry);
            prev->next=mm;
        }
        if(ac>=bc) return l1;
        return l2;
    }
};

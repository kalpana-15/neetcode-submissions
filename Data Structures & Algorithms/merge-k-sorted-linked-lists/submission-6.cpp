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
    ListNode*  merge2lists(ListNode* a,ListNode* b){
        if(a==nullptr) return b;
        if(b==nullptr) return a;
        ListNode* head=new ListNode(-1);
        ListNode* temp=head;
        while(a && b){
            if(a->val <=b->val){
                temp->next=a;
                a=a->next;
            }
            else if(a->val > b->val){
                temp->next=b;
                b=b->next;
            }
            temp=temp->next;
        }
        if(a!=nullptr){
            temp->next=a;
        }
        if(b!=nullptr){
            temp->next=b;
        }
        return head->next;

    }
    ListNode* merge(vector<ListNode*>& lists,int l,int r){
        if(l<0 || r>lists.size()) return nullptr;
        if(l==r) return lists[l];
        int mid=l+(r-l)/2;
        ListNode* left=merge(lists,l,mid);
        ListNode* right=merge(lists,mid+1,r);
        return merge2lists(left,right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0) return nullptr;
        return merge(lists,0,n-1);
    }
};

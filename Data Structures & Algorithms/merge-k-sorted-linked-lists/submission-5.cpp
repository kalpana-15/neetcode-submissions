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

    ListNode* merge2Lists(ListNode* a, ListNode* b) {

        if(a == nullptr) return b;
        if(b == nullptr) return a;

        ListNode* head = new ListNode(-1);
        ListNode* temp = head;

        while(a != nullptr && b != nullptr) {

            if(a->val <= b->val) {
                temp->next = a;
                a = a->next;
            }
            else {
                temp->next = b;
                b = b->next;
            }

            temp = temp->next;
        }

        if(a != nullptr)
            temp->next = a;

        if(b != nullptr)
            temp->next = b;

        return head->next;
    }

    ListNode* mergeRange(vector<ListNode*>& lists, int l, int r) {

        if(l == r)
            return lists[l];

        int mid = l + (r - l) / 2;

        ListNode* left = mergeRange(lists, l, mid);
        ListNode* right = mergeRange(lists, mid + 1, r);

        return merge2Lists(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.empty())
            return nullptr;

        return mergeRange(lists, 0, lists.size() - 1);
    }
};

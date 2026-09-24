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
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode* pres=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        while (pres!=NULL){
            next=pres->next;
            pres->next=prev;
            prev=pres;
            pres=next;
        }
        head=prev;
        return head;
    }
};
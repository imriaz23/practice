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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* newHead=new ListNode(0);
        newHead->next=head;
        ListNode* prev=newHead;
        for(int i=0;i<m-1;i++){
            prev=prev->next;
        }
        ListNode* start=prev->next;
        ListNode* then=start->next;
        for(int i=0;i<n-m;i++){
            start->next=then->next;
            then->next=prev->next;
            prev->next=then;
            then=start->next;
        }
        return newHead->next;
    }
};
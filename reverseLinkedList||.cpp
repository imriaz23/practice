/*
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
*/
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
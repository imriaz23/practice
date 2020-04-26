/*
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?
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
    ListNode* reverseList(ListNode* head) {
        if(!head){
            return NULL;
        }
        ListNode* newHead=new ListNode(0);
        newHead->next=head;
        ListNode* prev=newHead;
        ListNode* start=newHead->next;
        ListNode* then=start->next;
        while(then){
            start->next=then->next;
            then->next=prev->next;
            prev->next=then;
            then=start->next;
        }
        return newHead->next;
    }
};
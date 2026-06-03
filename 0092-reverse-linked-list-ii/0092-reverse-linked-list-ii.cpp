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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || left == right)
            return head;
        int pos = 1 ; 
        ListNode* t = head;
        ListNode* before = NULL;
        while(pos<left){
            before = t ; 
            t = t->next ;
            pos++;
        }
        //t points to node from which reversal starts 
        ListNode* curr = t ; 
        ListNode* prev = NULL;
        int times = right - left + 1;
        while(times--){
            ListNode* nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        if(before)
        before->next = prev;
        else
        head = prev;
        t->next = curr;
        return head;
    }
};
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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;
        // find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* midNode = slow;
        ListNode* curr = midNode;
        ListNode*prev = NULL;
        while(curr!=NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr= next;
        }
        //prev contains address of last node 
        ListNode* newStart = head;
        while( prev!=NULL){
            if(newStart->val==prev->val){
                newStart = newStart->next;
                prev = prev->next;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
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
        if(!head || left == right){
            return head;
        }
        int times = right-left+1;
        ListNode* temp = head;
        ListNode* before = NULL;
        int pos = 1;
        while(pos<left){
            before = temp; 
            temp = temp->next;
            pos++;
        }
        //pos = left 
        //before = 1
        //temp = node at left 
        ListNode* prev = NULL;
        ListNode* curr = temp;
        while(times--){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        temp->next = curr;
        if (before != nullptr) {
            before->next = prev;
            return head;
        }
        return prev;
    }
};
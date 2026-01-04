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
    ListNode* removeNthFromEnd(ListNode* head, int n) {\
        ListNode* temp = head;
        ListNode* slow = temp;
        ListNode* fast = temp;
        for(int i =0;i<n;i++){
            fast = fast->next;
        }
        if(fast==NULL){
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        while(fast->next!=NULL){
            slow = slow->next;
            fast = fast->next;
        }
        //slow will now be at one position prior to what you want to delete
        ListNode* deleteNode = slow->next;
        slow->next = deleteNode->next;
        delete deleteNode;
        return head;
    }
};
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
    ListNode* reverse(ListNode* head, int t) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (t--) {
            ListNode* nextN = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextN;
        }

        head->next = curr; 
        return prev;       
    }
    ListNode* swapPairs(ListNode* head) {
        ListNode* left = head;
        ListNode* prevLeft = NULL;
        ListNode* res = NULL;

        while (left && left->next) {
            ListNode* newHead = reverse(left, 2);

            if (!res)
                res = newHead;
            if (prevLeft)
                prevLeft->next = newHead;

            prevLeft = left;   
            left = left->next; 
        }

        return res ? res : head;
    }
};
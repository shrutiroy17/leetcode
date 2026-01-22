class Solution {
public:
    void reverse(ListNode* head, int t) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(t--) {
            ListNode* nextN = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextN;
        }
        
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        ListNode* left = head;
        ListNode* right;
        ListNode* res = NULL;
        ListNode* prevLeft = NULL;

        while(left) {
            right = left;
            for(int i = 0; i < (k - 1); i++) {
                right = right->next;
                if(right == NULL) break; 
            }
            
            if(right) {
                ListNode* nextGroupHead = right->next; 
                reverse(left, k);
                if(prevLeft) {
                    prevLeft->next = right;
                }
                if(res == NULL) {
                    res = right;
                }
                left->next = nextGroupHead;
                prevLeft = left;
                left = nextGroupHead;
            }
            else {
                if(prevLeft) {
                    prevLeft->next = left;
                }
                if(res == NULL) res = head;
                break;
            }
        }
        return res;
    }
};
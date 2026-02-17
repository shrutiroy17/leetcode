class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for (auto l : lists) {
            if (l) {
                pq.push(l);
            }
        }
        ListNode dummy(0);
        ListNode* temp = &dummy;

        while (!pq.empty()) {
            ListNode* n = pq.top();
            pq.pop();
            temp->next = n;
            temp = temp->next;

            if (n->next) {
                pq.push(n->next);
            }
        }
        return dummy.next;
    }
};

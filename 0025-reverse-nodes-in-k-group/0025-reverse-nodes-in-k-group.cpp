class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode *prevGroup = &dummy, *curr = head;

        int count = 0;
        while (curr) {
            count++;
            curr = curr->next;
        }

        while (count >= k) {
            curr = prevGroup->next;
            ListNode* nextNode = curr->next;

            for (int i = 1; i < k; i++) {
                curr->next = nextNode->next;
                nextNode->next = prevGroup->next;
                prevGroup->next = nextNode;
                nextNode = curr->next;
            }

            prevGroup = curr;
            count -= k;
        }

        return dummy.next;
    }
};
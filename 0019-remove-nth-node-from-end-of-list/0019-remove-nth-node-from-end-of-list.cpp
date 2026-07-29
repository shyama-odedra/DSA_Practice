class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        for(int i=0; i<n; i++){
            fast = fast->next;
        }

        if(fast == nullptr){
            ListNode* del = head;
            head= head->next;
            delete del;
            return head;
        }

        while(fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* del = slow->next;
        slow->next = slow->next->next;
        delete del;

        return head;
    }
};
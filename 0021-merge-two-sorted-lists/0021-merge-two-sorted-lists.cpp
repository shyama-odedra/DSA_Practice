class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> values;
        while (list1) {
            values.push_back(list1->val);
            list1 = list1->next;
        }
        while (list2) {
            values.push_back(list2->val);
            list2 = list2->next;
        }
        
        if (values.empty()) return nullptr;
        sort(values.begin(), values.end());
        
        ListNode* head = new ListNode(values[0]);
        ListNode* current = head;
        for (int i = 1; i < values.size(); i++) {
            current->next = new ListNode(values[i]);
            current = current->next;
        }
        
        return head;
    }
};
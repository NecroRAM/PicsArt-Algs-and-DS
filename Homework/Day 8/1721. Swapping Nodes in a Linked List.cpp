class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* tmp, *first = head, *second = head;

        for (int i = 1; i < k; ++i)
            first = first->next;
        tmp = first;
        while (tmp->next)
        {
            tmp = tmp->next;
            second = second->next;
        }
        std::swap(first->val, second->val);
        return head;
    }
};
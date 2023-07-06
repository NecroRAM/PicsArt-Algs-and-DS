ListNode* deleteDuplicates(ListNode* head) {
    ListNode ans(0, head), * start = &ans;

    while (head and head->next)
    {
        if (head->next->val == head->val)
        {
            while (head->next and head->next->val == head->val)
                head = head->next;
            head = start->next = head->next;
        }
        else
        {
            start = head;
            head = head->next;
        }
    }
    return ans.next;
}
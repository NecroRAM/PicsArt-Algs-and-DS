#include <iostream>

// Definition for singly-linked list
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
void printSLL(ListNode* head)
{
    while (head)
    {
        std::cout << head->val;
        head = head->next;
    }
}

ListNode* reverseListWrapper(ListNode* prev, ListNode* cur, ListNode* next)
{
    if (!cur)
        return prev;

    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;

    return reverseListWrapper(prev, cur, next);
}

// recursive
ListNode* reverseList(ListNode* head)
{
    ListNode* cur = head;
    ListNode* prev = nullptr;
    ListNode* next = nullptr;

    head = reverseListWrapper(prev, cur, next);
    return head;
}

// iterative
ListNode* reverseList(ListNode* head) 
{
    ListNode* cur = head;
    ListNode* prev = nullptr;
    ListNode* next = nullptr;

    while (cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
    return head;
}

int main()
{
    ListNode n6(6, nullptr);
    ListNode n5(5, &n6);
    ListNode n4(4, &n5);
    ListNode n3(3, &n4);
    ListNode n2(2, &n3);
    ListNode n1(1, &n2);
    ListNode* head = &n1;

    printSLL(head);
    std::cout << '\n';
    printSLL(reverseList(head));
}

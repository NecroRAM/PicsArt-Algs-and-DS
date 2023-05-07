#include <iostream>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
}; 

void printSLL(ListNode* head)
{
    while (head)
    {
        std::cout << head->val;
        head = head->next;
    }
}

ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2)
{
    ListNode dummy(0, list1);
    ListNode* start1 = &dummy, *end2 = list2;

    for (int i = 0; i < a and start1->next; ++i)
        start1 = start1->next;

    ListNode* end1 = start1;

    for (int i = a; i < b and end1->next; ++i)
        end1 = end1->next;

    while (end2->next)
        end2 = end2->next;

    start1->next = list2;
    end2->next = end1->next;
    end1->next = nullptr;
    return list1;
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

    ListNode l3(1003, nullptr);
    ListNode l2(1002, &l3);
    ListNode l1(1001, &l2);
    ListNode* head2 = &l1;

    printSLL(head);
    std::cout << '\n';
    printSLL(mergeInBetween(head, 2, 5, head2));
}
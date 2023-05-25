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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    ListNode dummy(0, list1), * n1 = list1, * n2 = list2, * prev = &dummy, * tmp = nullptr;
    
    if (!list1)
        return list2;
    if (!list2)
        return list1;

    while (n1 and n2)
    {
        if (n2->val > n1->val)
        {
            if (!n1->next)
            {
                n1->next = n2;
                break;
            }
            prev = n1;
            n1 = n1->next;
        }
        else
        {
            tmp = n2->next;
            prev->next = n2;
            n2->next = n1;
            prev = n2;
            n2 = tmp;
        }
        return dummy.next;
    }

}

int main()
{
    ListNode n3(4, nullptr);
    ListNode n2(2, &n3);
    ListNode n1(1, &n2);
    ListNode* head = &n1;

    ListNode l3(4, nullptr);
    ListNode l2(3, &l3);
    ListNode l1(1, &l2);
    ListNode* head2 = &l1;

    printSLL(head);
    std::cout << '\n';
    printSLL(mergeTwoLists(head, head2));
}
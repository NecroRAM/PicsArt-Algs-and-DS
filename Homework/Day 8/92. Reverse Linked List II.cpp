#include <iostream>
#include "D:\Downloads\Courses\Algs and Data Structs\PicsArt Academy\PicsArt-Algs-and-DS\Homework\ListNode.cpp"

ListNode* reverseBetween(ListNode* head, int left, int right)
{
    int ind = 1;
    ListNode dummy(0, head);
    ListNode* tmp1 = &dummy, * tmp2 = &dummy, * prev = &dummy, * cur = &dummy, * next = &dummy;
    bool first = true;

    while (ind < left)
    {
        tmp1 = tmp1->next;   
        ++ind;
    }

    cur = prev = tmp2 = next = tmp1;
    cur = cur->next;

    while (ind <= right)
    {
        tmp2 = tmp2->next;
        ++ind;
    }

    prev->next = tmp2;
    tmp1 = tmp2->next;
    
    while (cur != tmp1)
    {
        next = cur->next;
        if (first)
        {   
            cur->next = tmp2->next;
            first = false;
        }
        else
        {
            cur->next = prev;
        }
        prev = cur;
        cur = next;
    }
    return dummy.next;
} 

int main()
{
    ListNode n5(6, nullptr);
    ListNode n4(5, &n5);
    ListNode n3(4, &n4);
    ListNode n2(3, &n3);
    ListNode n1(2, &n2);
    ListNode n0(1, &n1);
    ListNode* head = &n0;

    printList(head);
    std::cout << '\n';
    printList(reverseBetween(head, 2, 5));
}

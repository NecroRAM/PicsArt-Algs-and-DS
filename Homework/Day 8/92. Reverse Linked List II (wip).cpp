#include <iostream>
#include "D:\Downloads\Courses\Algs and Data Structs\PicsArt Academy\PicsArt-Algs-and-DS\Homework\ListNode.cpp"

ListNode* reverseBetween(ListNode* head, int left, int right)
{
    int ind = 1;
    ListNode dummy(0, head);
    ListNode* start = &dummy, * end = &dummy, * tempE = &dummy, * prev = &dummy, * cur = &dummy, * next = &dummy;
    bool first = true;

    while (ind <  left) // dummy-> 1 s2 3 4 e5 6
    {
        start = start->next;   
        ++ind;
    }

    prev = end = tempE = start;
    start = start->next;

    while (ind <= right)
    {
        end = end->next;
        ++ind;
    }

    prev->next = end;

    while (start != tempE->next)
    {
        next = start->next;
        if (first)
        {
            start->next = end->next;
            first = false;
        }
        else
        {
            start->next = prev;
        }
        prev = start;
        start = next;
    }
    return head;
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

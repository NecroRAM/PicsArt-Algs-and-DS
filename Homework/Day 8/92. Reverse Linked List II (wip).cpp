#include <iostream>
#include "D:\Downloads\Courses\Algs and Data Structs\PicsArt Academy\PicsArt-Algs-and-DS\Homework\ListNode.cpp"

//// Definition for singly-linked list.
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode *next) : val(x), next(next) {}
//};

ListNode* reverseBetween(ListNode* head, int left, int right)
{
    int ind = 1;
    ListNode dummy(0, head);
    ListNode* start = head, *tmp = head, *prev = head, *end = head;

    while (++ind < left)
        prev = prev->next;

    end = prev->next;

    while (++ind < right and end->next)
        end = end->next;

    tmp = prev->next;
    prev->next = end->next;
    end = end->next;
    prev = tmp;
    start = tmp->next;
    tmp->next = end->next;
    //std::cout << end->next->val << '\n';
    end = end->next;

    while (start != end)
    {
        tmp = start->next; // 1 2 3 4 5 6
        start->next = prev;
        prev = start;
        start = tmp;
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
    ListNode* head = &n4;

    printList(head);
    std::cout << '\n';
    printList(reverseBetween(head, 1, 2));
}

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

ListNode* partition(ListNode* head, int x)
{
    ListNode less;
    ListNode greater;

    ListNode* lessptr = &less;
    ListNode* greaterptr = &greater;


	while (head)
	{
		if (head->val < x)
		{
			lessptr->next = head;
			lessptr = lessptr->next;
		}
		else
		{
			greaterptr->next = head;
			greaterptr = greaterptr->next;
		}
		head = head->next;
    }
	greaterptr->next = nullptr;
	lessptr->next = greater.next;
	return less.next;
}

int main()
{
	ListNode n6(2, nullptr);
	ListNode n5(5, &n6);
	ListNode n4(2, &n5);
	ListNode n3(3, &n4);
	ListNode n2(4, &n3);
	ListNode n1(1, &n2);
	ListNode* head = &n1;

	printSLL(partition(head, 3));
}

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
	ListNode* less = head;
	ListNode* greater = head;
	ListNode* lessHead = head;
	ListNode* greatHead = head;
	ListNode* cur = head;
	ListNode* curTmp = head;

	bool firstLargerFound = false;

	while (cur && cur->next)
	{
		if (cur->next->val < x)
		{
			less->next = cur->next;
			less = cur->next;
		}
		else
		{
			if (!firstLargerFound)
			{
				greatHead = cur;
				firstLargerFound = true;
			}
			greater->next = cur->next;
			greater = cur->next;
		}
		curTmp = cur;
		cur = head->next;
	}
	less->next = greatHead;
	curTmp->next = nullptr;

	return lessHead;
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

	//std::cout << head->next;

	//printSLL(head);

	printSLL(partition(head, 3));
}

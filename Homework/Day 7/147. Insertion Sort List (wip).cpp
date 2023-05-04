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

ListNode* insertionSortList(ListNode* head)
{
	ListNode* cur, *prev, *tmp, *start;

	ListNode dummy(0, head);
	start = &dummy; // {}
	cur = head; // []
	prev = nullptr; 
	tmp = nullptr; // ()

	while (cur && cur->next)
	{
		while (start->next->val < cur->val)
			start = start->next;			
		// 1 2 3 4 5 6 7 6
		// dummy-> 1 4 3 2 5 2
		tmp = cur->next; // stores cur->next
		cur->next = tmp->next; // severs the cur out of its position
		prev = start->next; // stores start->next
		start->next = tmp; // places tmp in its sorted position
		tmp->next = prev; // restores the link

		if (prev == head) // restores head in case the sorted element is smaller than head
			head = tmp;

		cur = cur->next; // iteration step
		start = &dummy; // resets start
		printSLL(head);
		std::cout << '\n';
	}
	return head;
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

	printSLL(head);
	std::cout << '\n';
	printSLL(insertionSortList(head));
}
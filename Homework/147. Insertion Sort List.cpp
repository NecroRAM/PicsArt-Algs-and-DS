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
	ListNode* cur, *prev, *tmp;
	ListNode dummy(0, head);
	cur = head;
	prev = &dummy;
	tmp = nullptr;
		
	 // implementation at class
	 while (cur)
	 {
		 if (cur->next and cur->next->val < cur->val) // 4 5 6 3
		 {
			 while (prev->next and prev->next->val < cur->next->val)
				 prev = prev->next;

			 tmp = prev->next;
			 if (prev->next == head)
				 head = cur->next;
			 prev->next = cur->next;
			 cur->next = cur->next->next;
			 prev->next->next = tmp;
			 prev = &dummy;
		 }
		 else
			 cur = cur->next;
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
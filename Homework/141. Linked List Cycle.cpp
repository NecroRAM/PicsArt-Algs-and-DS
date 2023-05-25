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

bool hasCycle(ListNode* head) {
	if (!head)
		return false;

	ListNode* slow = head;
	ListNode* fast = head->next;

	while (fast != slow)
	{
		if (!fast or !fast->next)
			return false;
		slow = slow->next;
		fast = fast->next->next;
	}
	return true;
}

int main()
{
	ListNode n6(2, nullptr);
	ListNode n5(5, &n6);
	ListNode n4(2, &n5);
	ListNode n3(3, &n4);
	ListNode n2(4, &n3);
	ListNode n1(1, &n2);
	n6.next = &n3;
	ListNode* head = &n1;

	std::cout << hasCycle(head);
}

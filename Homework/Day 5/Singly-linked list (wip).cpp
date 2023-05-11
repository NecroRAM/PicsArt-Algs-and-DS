#include <iostream>
#include <memory>

template <typename T, typename... Us>
class SLL
{
private:
	struct ListNode
	{
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};

public:
	ListNode* reverse(ListNode* head) 
	{
		ListNode* cur = head;
		ListNode* prev = nullptr;
		ListNode* next = nullptr;

		while (cur)
		{
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		
		head = prev;
	
		return head;
	}
	
	ListNode* push_front(int val)
	{
		ListNode newHead(val, next);
		
		return &newHead;
	}
};
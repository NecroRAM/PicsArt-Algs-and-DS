#include <iostream>
#include <utility>
#include <stack>

// return 2 independent heads
class Node
{
public:
	int val;
	Node* next;
};

std::pair<Node*, Node*> foo(Node* head)
{
	Node* slow = head->next;
	Node* fast = head->next;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return std::make_pair(slow, fast);
}

int main()
{
	Node* n10 = new Node{ 10, nullptr };
	Node* n9 = new Node{ 9, n10 };
	Node* n8 = new Node{ 8, n9 };
	Node* n7 = new Node{ 7, n8 };
	Node* n6 = new Node{ 6, n7 };
	Node* n5 = new Node{ 5, n6 };
	Node* n4 = new Node{ 4, n5 };
	Node* n3 = new Node{ 3, n4 };
	Node* n2 = new Node{ 2, n3 };
	Node* n1 = new Node{ 1, n2 };
	Node* head = new Node{ 0, n1 };

	std::pair<Node*, Node*> res = foo(head);

	std::cout << res.first->val << ' ' << res.second->val;
}


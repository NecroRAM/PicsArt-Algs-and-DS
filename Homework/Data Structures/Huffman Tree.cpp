#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <functional>

class Node
{
public:
	char val;
	int fr;
	Node* left, * right;
	Node(const char c, const int _fr, Node* _left = nullptr, Node* _right = nullptr)
		: val(c)
		, fr(_fr)
		, left(_left)
		, right(_right)
	{}
};

class HuffmanTree
{
private:
	std::unordered_map<char, std::string> huffman;
	Node* root;

	std::function<bool(const Node*, const Node*)> comparator = [](const Node* left, const Node* right) -> bool
	{
		return left->val > right->val;
	};

	void buildHuffmanTree(const std::string& text)
	{
		std::unordered_map<char, int> freq;

		for (char c : text)
			++freq[c];

		std::priority_queue<Node*, std::vector<Node*>, decltype(comparator)> pq;

		for (auto [c, fr] : freq)
			pq.push(new Node(c, fr));

		while (pq.size() != 1)
		{
			Node* left = pq.top();
			pq.pop();
			Node* right = pq.top();
			pq.pop();

			pq.push(new Node('$', left->fr + right->fr, left, right));
		}

		root = pq.top();
		encode(root, "");
	}

	void encode(Node* node, std::string&& s)
	{
		if (!node)
			return;
		if (!node->left and !node->right)
			huffman[node->val] = s;
		encode(node->left, s + '0');
		encode(node->right, s + '1');
	}

	void decodeHelper(const Node* node, const int index, std::string& decoded)
	{
		if (!node)
			return;
		if (!node->left and !node->right)
		{
			decoded.push_back(node->val);
			return;
		}
		if (decoded[index] == '0')
			decodeHelper(node->left, index + 1, decoded);
		else
			decodeHelper(node->right, index + 1, decoded);
	}

public:
	HuffmanTree(const std::string& text)
	{
		buildHuffmanTree(text);
	}	

	std::string decode()
	{
		std::string res = "";
		decodeHelper(root, 0, res);
		return res;
	}

	void print()
	{
		for (auto& [c, s] : huffman)
			std::cout << c << ": " << s << '\n';
	}
};

int main()
{
	std::string text = "abacdaaccbdef";
	HuffmanTree ht(text);
	ht.print();
	std::cout << ht.decode();
}
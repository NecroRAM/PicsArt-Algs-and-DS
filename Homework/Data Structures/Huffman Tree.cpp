#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

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
	bool comp(const Node* left, const Node* right)
	{
		return left->val > right->val;
	}

	std::unordered_map<char, std::string> huffman;
public:
	HuffmanTree(const std::string& text)
	{
		buildHuffmanTree(text);
	}

	void encode(Node* node, std::string& s, std::unordered_map<char, std::string>& huffman)
	{
		if (!node)
			return;
		if (!node->left and !node->right)
			huffman[node->val] = s;
		encode(node->left, s + '0', huffman);
		encode(node->right, s + '1', huffman);
	}

	void decode(Node* node, const int index, std::string& decoded)
	{
		if (!node)
			return;
		if (!node->left and !node->right)
			decoded.push_back(node->val);
		if (decoded[index] == '0')
			decode(node->left, index + 1, decoded);
		else
			decode(node->right, index + 1, decoded);
	}

	HuffmanTree buildHuffmanTree(const std::string& text)
	{
		std::unordered_map<char, int> freq;
		for (char c : text)
			++freq[c];
		std::priority_queue<Node*, std::vector<Node*>, decltype(comp)> pq;
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
		Node* root = pq.top();
	}
		encode(root, "", huffman);
};

int main()
{
	std::string text = "abacdaaccbdef";
	auto ht = HuffmanTree(text);
}
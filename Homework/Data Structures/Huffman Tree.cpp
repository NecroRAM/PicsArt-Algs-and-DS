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
};

class HuffmanTree
{
private:
	std::unordered_map<char, std::string> huffman;
public:
	void encode(Node* node, std::string s, std::unordered_map<char, std::string> huffman)
	{
		if (!node)
			return;
		if (!node->left and !node->right)
			huffman[node->val] = s;
		encode(node->left, s + '0', huffman);
		encode(node->right, s + '1', huffman);
	}

	void decode(Node* node, int index, std::string encoded, std::string decoded)
	{
		if (!node)
			return;
		if (node is a leaf)
			decoded.append(node->val);
		if (decoded[index] == '0')
			decode(node->left...);
		else
			decode(node->right...);
	}

	HuffmanTree buildHuffmanTree(std::string text)
	{
		std::unordered_map<char, int> freq;
		for (char c : text)
			++freq[c];
		std::priority_queue<Node> pq;
		for (auto [c, fr] : freq)
			pq.push(new Node(c, fr));
		while (pq.size() != 1)
		{
			Node* left = pq.top();
			pq.pop();
			Node* right = pq.top();
			pq.pop();

			pq.push(new Node(left->fr + right->fr, '$'; left, right);

			Node root = pq.top();
		}
	}
		encode(root, "", huffman);
};
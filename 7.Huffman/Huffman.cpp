/**
设字符集为{A,B,C,D,E,F,G,H}，每个字符在征文中出现
的次数分别为{19,2,13,5,11,7,3,17}。设计实现Huffman
树的构造算法，构造Huffman树并输出每个字符的Huffman编码。
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

typedef struct huffmanNode {
	char c = 0;
	int weight;
	string huffmanCode = "";
	huffmanNode * left = NULL;
	huffmanNode * right = NULL;
}* Node;

bool compare(Node x, Node y) {
	return (x->weight < y->weight);
}

void fillHuffmanCode(Node node, string codeFromFather, int flag) { // flag:0左,1右,-1根
	if (node == NULL)
		return;
	if (flag != -1) {
		node->huffmanCode = codeFromFather + (flag == 0 ? "0" : "1");
		fillHuffmanCode(node->left, node->huffmanCode, 0);
		fillHuffmanCode(node->right, node->huffmanCode, 1);
	}
	else {
		fillHuffmanCode(node->left, "", 0);
		fillHuffmanCode(node->right, "", 1);
	}

}

Node createHuffmanTree(char *chars, int *weights, int size) {
	vector<Node> nodes;
	for (int i = 0; i < size; i++) {
		nodes.push_back(new huffmanNode);
		nodes[i]->c = chars[i];
		nodes[i]->weight=weights[i];
	}
	while (nodes.size() != 1) {
		sort(nodes.begin(), nodes.end(), compare);
		Node temp = new huffmanNode;
		temp->left = nodes[0];
		temp->right = nodes[1];
		temp->weight = temp->left->weight + temp->right->weight;
		nodes.erase(nodes.begin());
		nodes.erase(nodes.begin());
		nodes.push_back(temp);
	}
	
	return nodes[0];
}

void printHuffmanCode(Node node) {
	if (node == NULL)
		return;
	if (node->c)
		cout << node->c << ":" << node->huffmanCode << endl;
	printHuffmanCode(node->left);
	printHuffmanCode(node->right);
}



int main() {
	char chars[] = "ABCDEFGH";
	int weights[] = { 19,2,13,5,11,7,3,17 };
	Node tree = createHuffmanTree(chars, weights, 8);
	fillHuffmanCode(tree, "", -1);
	printHuffmanCode(tree);
	system("pause");
	return 0;
}
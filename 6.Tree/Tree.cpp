/**
设一棵二叉树的先根遍历序列是“ABDHEIJCFKG”，中根遍历序列
是”DHBIEJAFKCG”，以该先根和中根遍历序列为输入，设计二叉
树结点类和二叉树类，构造该二叉树，并输出只有一个孩子的
结点。
*/

#include<iostream>
#include<vector>

using namespace std;

template<typename T>
class TreeNode {
public:
	T value;
	TreeNode *left = NULL, *right = NULL;
	
	TreeNode(T value) {
		this->value = value;
	}
};

template<typename T>
using Node = TreeNode * <T>;

template<typename T>
class Tree {
private :
	Node<T> head;
public:
	

};

int main() {
	string preOrder = "ABDHEIJCFKG";
	string inOrder = "DHBIEJAFKCG";
	//Tree<char> tree(preOrder.size());
	
	//tree.set(1, inOrder[inOrder.size() / 2]);


	system("pause");
	return 0;
}
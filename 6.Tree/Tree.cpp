/**
��һ�ö��������ȸ����������ǡ�ABDHEIJCFKG�����и���������
�ǡ�DHBIEJAFKCG�����Ը��ȸ����и���������Ϊ���룬��ƶ���
�������Ͷ������࣬����ö������������ֻ��һ�����ӵ�
��㡣
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
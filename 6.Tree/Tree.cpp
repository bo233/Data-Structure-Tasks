/**
�� һ �� �� �� �� �� �� �� �� �� �� ���� ��ABDHEIJCFKG�� �� 
�� �� �� �� �� ���ǡ�DHBIEJAFKCG�����Ը��ȸ����и���������
Ϊ���룬��ƶ����������Ͷ������࣬����ö������������
ֻ��һ�����ӵĽ�㡣
*/

#include<iostream>

using namespace std;

template<typename T>
class TreeNode {
public:
	T elem;
	TreeNode *left = NULL, *right = NULL;
};

template<typename T>
using Node = TreeNode * <T>;

template<typename T>
class Tree {
	Node<T> a;
};
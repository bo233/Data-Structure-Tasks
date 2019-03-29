/**
设 一 棵 二 叉 树 的 先 根 遍 历 序 列是 “ABDHEIJCFKG” ， 
中 根 遍 历 序 列是”DHBIEJAFKCG”，以该先根和中根遍历序列
为输入，设计二叉树结点类和二叉树类，构造该二叉树，并输出
只有一个孩子的结点。
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
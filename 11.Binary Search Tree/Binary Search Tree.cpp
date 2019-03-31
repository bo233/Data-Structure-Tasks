/**
设数据序列为{54,18,12,81,99,36,12,76,57,6,66,40}，根据该
序列设计程序构造基于二叉链表存储结构的二叉排序树，统计并
输出查找元素36的比较次数。
*/

#include<iostream>

using namespace std;

typedef class TreeNode{
public:
	int value;
	TreeNode* left = NULL;
	TreeNode* right = NULL;
	TreeNode(int value) { this->value = value; }
}*Node;

Node createBinSearchTree(int* nums, int size) {
	Node tree;
	int i = 0;
	tree = new TreeNode(nums[i]);
	for (i = 1; i < size; i++) {
		Node iter = tree;
		while (true){
			if (nums[i] < iter->value) {
				if (iter->left == NULL) {
					iter->left = new TreeNode(nums[i]);
					break;
				}
				else {
					iter = iter->left;
					continue;
				}
			}
			else if (nums[i] > iter->value) {
				if (iter->right == NULL) {
					iter->right = new TreeNode(nums[i]);
					break;
				}
				else {
					iter = iter->right;
					continue;
				}
			}
			else
				break;
		}
	}
	return tree;
}

// 返回比较次数
int find(Node tree, int value) {
	Node iter = tree;
	int count = 0;
	while (true) {
		if (value < iter->value) {
			if (iter->left == NULL)
				return -1;
			else {
				iter = iter->left;
				count++;
				continue;
			}
		}
		else if (value > iter->value) {
			if (iter->right == NULL)
				return -1;
			else {
				iter = iter->right;
				count++;
				continue;
			}
		}
		else
			return count;
	}
}

int main() {
	int nums[] = { 54,18,12,81,99,36,12,76,57,6,66,40 };
	Node tree = createBinSearchTree(nums, 12);
	cout << find(tree, 36) << endl;
	system("pause");
	return 0;
}
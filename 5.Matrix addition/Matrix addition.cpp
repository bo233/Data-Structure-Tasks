/**
以行的单链表、列的单链表、十字链表中的任一种存储结构为基础，
设计程序实现教材 134 页 A、B 两个稀疏矩阵的相加运算。 
*/

#include<iostream>
#include<vector>

using namespace std;

struct Triple {
	int row, column, value;
	Triple *next = NULL;
};

class MatrixRowList {
public:
	int row, column;
	Triple **data;
	MatrixRowList(int row, int column) {
		this->row = row;
		this->column = column;
		data = new(Triple*[row]);
	}

	int get(int row, int column) {
		auto iter = data[row];
		while (iter) {
			if (iter->column == column)
				return iter->value;
			iter = iter->next;
		}
		return 0;
	}

	void set(int row, int column, int value) {
		if (data[row] == NULL && value != 0) {
			data[row] = new(Triple);
			data[row]->row = row;
			data[row]->column = column;
			data[row]->value = value;
			return;
		}
		auto iter = data[row];
		if (value == 0) {
			while (iter) {
				if (iter->next != NULL && iter->next->column == column) {
					if (iter == data[row])
						data[row] = NULL;
					else
						iter->next = iter->next->next;

					return;
				}
			}
		}
		else {

		}

	}
};



int main() {

}
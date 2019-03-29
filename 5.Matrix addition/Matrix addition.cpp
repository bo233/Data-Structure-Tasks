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

class Matrix {
private:
	int row, column;
	Triple **data;

public:
	Matrix(int row, int column) {
		this->row = row;
		this->column = column;
		data = new(Triple*[row]);
		for (int i = 0; i < row; i++)
			data[i] = NULL;
	}

	int get(int row, int column) {
		auto iter = data[row];
		if (iter == NULL)
			return 0;

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
				iter = iter->next;
			}
		}
		else {
			if (iter->column > column) {
				auto temp = data[row];
				data[row] = new(Triple);
				data[row]->row = row;
				data[row]->column = column;
				data[row]->value = value;
				data[row]->next = temp;
			}
			else {
				while (iter->next) {
					if (iter->column == column) {
						iter->value = value;
						return;
					}
					else {
						if (iter->column < column && (iter->next == NULL || iter->next->column > column)) {
							auto temp = iter->next;
							iter->next = new(Triple);
							iter->row = row;
							iter->column = column;
							iter->value = value;
							iter->next = temp;
							return;
						}
					}
					iter = iter->next;
				}
				iter->next = new(Triple);
				iter->next->row = row;
				iter->next->column = column;
				iter->next->value = value;
			}
		}
	}

	void display() {
		for (int i = 0; i < row; i++) {
			auto iter = data[i];
			cout << "|";
			if (iter == NULL) 
				for (int j = 0; j < column; j++)
					cout << " 0 ";
			else {
				for (int j = 0; j < column; j++) {
					if (iter != NULL && iter->column == j) {
						cout << " " << iter->value << " ";
						iter = iter->next;
					}
					else
						cout << " 0 ";
				}
			}
			cout << "|" << endl;
		}
		cout << endl;
	}

	Matrix* operator+(Matrix b) {
		Matrix* ans = new Matrix(row, column);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				ans->set(i, j, this->get(i, j) + b.get(i, j));
			}
		}
		return ans;
	}

};



int main() {
	Matrix matrixA(7, 8);
	Matrix matrixB(7, 8);
	matrixA.set(0, 6, 5);
	matrixA.set(1, 1, 10);
	matrixA.set(1, 3, 9);
	matrixA.set(3, 5, 17);
	matrixA.set(5, 1, 21);
	matrixA.set(5, 3, 34);
	matrixA.set(5, 7, 75);
	matrixA.display();

	matrixB.set(0, 0, 1);
	matrixB.set(0, 5, -5);
	matrixB.set(1, 0, 11);
	matrixB.set(1, 2, 43);
	matrixB.set(1, 6, 77);
	matrixB.set(3, 5, 51);
	matrixB.set(5, 1, -21);
	matrixB.set(5, 3, -34);
	matrixB.display();

	Matrix *matrixC;
	matrixC = matrixA + matrixB;
	matrixC->display();
	system("pause");
	return 0;
}
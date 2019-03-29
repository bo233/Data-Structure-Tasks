/**
���еĵ������еĵ�����ʮ�������е���һ�ִ洢�ṹΪ������
��Ƴ���ʵ�ֽ̲� 134 ҳ A��B ����ϡ������������㡣 
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
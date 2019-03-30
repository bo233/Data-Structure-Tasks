/**
��ؼ�������Ϊ{9,4,12,14,74,6,16,96}����ƹ���
����Ϊ10��ɢ�б���������ַ�������ͻ����Ƴ�
����㲢����ɹ����ҵ�ƽ�����ҳ��ȡ�
*/

#include<iostream>
#include<vector>

using namespace std;

struct NodeInstance {
	int key;
	NodeInstance* next = NULL;
};

typedef NodeInstance* HashNode;

class HashTable {
private:
	HashNode* table;
	int HashTableSize;

public:
	HashTable(int size) {
		table = new HashNode[size];
		for (int i = 0; i < size; i++)
			table[i] = NULL;
		HashTableSize = size;
	}

	int HashFunc(int key) {
		//����ȡ��Ĺ����ϣ��������
		return key % HashTableSize;
	}

	void insert(int key) {
		int index = HashFunc(key);
		if (table[index] == NULL) {
			HashNode t = new NodeInstance;
			t->key = key;
			table[index] = t;
		}
		else {
			auto iter = table[index];
			while (iter->next)
				iter = iter->next;
			HashNode t = new NodeInstance;
			t->key = key;
			iter->next = t;
		}
	}
	
	//���ز��Ҵ���
	int find(int key) {
		int count = 0;
		auto iter = table[HashFunc(key)];
		while (iter) {
			count++;
			if (iter->key == key)
				return count;
			iter = iter->next;
		}
		return count;
	}
};

int main() {
	HashTable hashTable(10);
	vector<int> keys = { 9,4,12,14,74,6,16,96 };
	for (int i : keys)
		hashTable.insert(i);
	int count = 0;
	for (int i : keys)
		count += hashTable.find(i);

	cout << (count + 0.0) / keys.size() << endl;

	system("pause");
	return 0;
}
/**
��Ŀ�괮�ǡ�acabbabbabc����ģʽ���ǡ�abbabc�������ʵ�ִ��� Brute-Force ģ
ʽƥ���㷨����ɴ���ƥ�䡣Ҫ������Զ�����ַ�����ʵ�֣�����ƥ��������
�Ƚϴ�����ƥ��λ�á�
*/

#include<iostream>
#include<vector>

using namespace std;

class MyString {
private:
	vector<char> string;

public:
	MyString(char* s) {
		int i = 0;
		while (s[i])
			string.push_back(s[i++]);
	}

	MyString() {

	}

	int length() {
		return string.size();
	}

	char charAt(int index) {
		return string[index];
	}

	void append(char* s) {
		int i = 0;
		while (!s[i])
			string.push_back(s[i++]);
	}

	void append(char c) {
		string.push_back(c);
	}

	void append(MyString myS) {
		int i = 0;
		while (i < myS.length())
			string.push_back(myS.charAt(i));
	}

	MyString subString(int begin, int end) {
		MyString temp;
		int i = begin;
		while (i < end)
			temp.append(string[i++]);
		return temp;
	}
};

int BFMatch(MyString s, MyString p){
	int i, j;
	i = 0;
	while (i < s.length()){
		j = 0;
		while (j < p.length() && i < s.length() && s.charAt(i) == p.charAt(j)){
			i++;
			j++;
		}

		if (p.length() == j)
			return i - p.length();

		i = i - j + 1;                // ָ��i����
	}

	return -1;
}

int main() {
	char a[100], b[100];
	gets_s(a);
	gets_s(b);
	MyString s1(a);
	MyString s2(b);
	cout << "ƥ�����ʼλ�ã�" << BFMatch(s1, s2) << endl;
	system("pause");
	return 0;
}